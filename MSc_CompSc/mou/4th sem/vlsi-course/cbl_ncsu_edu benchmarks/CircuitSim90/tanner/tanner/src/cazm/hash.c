/*---------------------------------------------------------------------------


    =========       ========        ===========    ===== =======   =======
   ==      ===     ===     ==       ==     ===        ===     === =     ===
  ==       ===     ===   =====      =     ===         ==       ===       ===
  ==               =====   ===          ===           ==       ===       ===
  ==              ===      ===         = =    =       ==       ===       ===
   ==        =    ===      ===       ===      =       ==       ===       ===
    =========      ======== ====    ===========    =======   =======  =======

-----------------------------------------------------------------------------

	            Designed and written by
                    	Donald Erdman - Duke University
                    	Ravi Subrahmanyan - MCNC
                    	Gary Nifong - MCNC
                    	Steve Kenkel - MCNC

	Copyright 1989, 1990 by the Microelectronics Center of North 
	Carolina, Don Erdman, and Don Rose.

        This copy, serial #00, of MCNC proprietary software, is made  
        available under license agreement.  Please heed all non-  
        disclosure and internal use restrictions.  
-----------------------------------------------------------------------------

	This file contains the netlist creation subroutines

----------------------------------------------------------------------------*/
/* 
$Header: hash.c,v 1.11 87/10/30 16:09:13 erdman Locked $
$Log:	hash.c,v $
 * Revision 1.11  87/10/30  16:09:13  erdman
 * October release version
 * 
 * Revision 1.9  87/03/25  13:22:25  erdman
 * release version
 * 
 * Revision 1.8  86/07/10  13:20:13  erdman
 * changing the hash_model,  hash_device routines
 * 
 * Revision 1.6  86/05/28  13:16:57  erdman
 * Adding new spice parser
 * 
 * Revision 1.5  86/01/14  10:32:30  erdman
 * adding extension information on tables
 * 
 * Revision 1.4  85/10/31  11:56:42  erdman
 * Adding subcircuit capabilities and
 * removed the head of the circuit list
 * 
 * Revision 1.3  85/09/19  08:31:48  erdman
 * Added the binary version of get_model
 * 
 * Revision 1.2  85/09/12  13:44:12  erdman
 * Adding command parser
 * 
 * Revision 1.1  85/08/12  11:06:41  erdman
 * Initial revision
 * 
*/
#include <math.h>
#include "Hmain.h"
#include "Hcmd.h"
#include "mod.h"
#include "sim.h"
#include "sp.h"
#include "spcmd.h"
#include "newfunc.h"


/*
-----------------------------------------------------------
|    HASH_FUNCTION
|    accepts a character string and returns an integer between 0 and 
|    HASH_TABLESIZE
|
| Parameters -
|         Name - character string and function argument
|
| Returns -
|         Integer that is a function of the string and the hash table size.
|
| Deficiencies -
|          There may be better functions for the expected name distributions
------------------------------------------------------------
*/

int
hash_function(name)
char *name;
{
	int hashval;

	hashval = 0;
        while (*name !=  '\0' )
		hashval = hashval + *name++;        /* sum the ascii values */
	return(hashval % HASH_TABLESIZE);	/* modulo the table size */
}

/*
-----------------------------------------------------------
|    HASH_NODES
|    insert or find node names in global hash table
|
| Parameters -
|         hashtable - array of pointers to table records (global)
|         name - string being inserted or searched for
|         node_num - next node number to be inserted 
|	  node_names - array of node names used for a debug map
|      
| Returns -
|         Returns node number if the string is found in the table, 
|         otherwise it returns the next unique number and adds the string
|	  to the table.
|
| Side effects -
|         Adds a record to the hash table.
|
------------------------------------------------------------
*/

int
hash_nodes(name, node_num, hashtable, node_names)
char *name;
int *node_num;		/* current unique node number */
struct hash_table_s **hashtable;
char ***node_names;
{
	struct hash_table_s *ptr_hash;		/* temporary ptr */
	struct hash_table_s *new_hash;		/* temporary ptr */
	struct hash_table_s *find_name();	/* function */
	char **cz_realloc();			/* realloc node name list */
	int hashval;				/* index into hash table */

	ptr_hash = find_name(name, NODE, hashtable);
	if (ptr_hash == NULL ) 	{	/* insert the new name */
		hashval = hash_function(name);
		ptr_hash = hashtable[hashval];

					/* allocate new record and insert */
		new_hash = hashalloc();
		new_hash->h_next = ptr_hash;
		hashtable[hashval] = new_hash;
		new_hash->h_type = NODE;
		new_hash->h_name = name;

				/* assign new node number and increment it */
		new_hash->h_node_num = *node_num;
				/* map name and number */
		if (node_names != NULL && (*node_names) != (char **) NULL) {
		    if (*node_num > 0 && (*node_num % 100) == 0) /* realloc */
			(*node_names) = cz_realloc(node_names, *node_num, 1);

		    (*node_names)[*node_num] = (char *)
			sim_alloc((strlen(name)+1) * sizeof(char),S_CAZM);
		    strcpy((*node_names)[*node_num] ,name);
		}

		(*node_num)++;
		return(*node_num - 1);
	}
	else
		return(ptr_hash->h_node_num);
}
        
/*
-----------------------------------------------------------
|    HASH_MODEL
|    Read in model table, and add device name and pointer to table
|    or stores device characteristics from .model card.
|
| Parameters -
|         name - character string the hashing is performed on
|	  filenameF - the prefix name of the steady state current table
|	  filenameQ - the prefix name of the Charge model table
|	  modellist - pointer to model list
|	  params - struct of device characteristics from .model card
|
| Side effects -
|         adds a new device to the hash table list 
|
------------------------------------------------------------
*/
hash_model(name, filenameF, filenameQ, modellist, params, type)
char *name;
char *filenameF;
char *filenameQ;
struct modellist_s *modellist;
struct sp_model_s *params;
int type;				/* Transistor or diode */
{
	int notdone = TRUE;

	while  (modellist->m_next != NULL && notdone) {
	    if (strcmp(modellist->m_next->m_name, name) == 0 )
		notdone = FALSE;
	     else 
	        modellist = modellist->m_next;
	}

	if (modellist->m_next == NULL ) 	{
					/* insert new name */
	    modellist->m_next = (struct modellist_s *) sim_alloc(
			sizeof(struct modellist_s), S_CAZM);
	    modellist = modellist->m_next;
	    modellist->m_next = NULL;
	    modellist->m_paramlist = NULL;
	    modellist->m_name = name;
	    modellist->m_param = params;
	    modellist->m_type = type;

				/* We have a MACRO filename */
	    if (filenameF != NULL) { 	/* then we have to read in table */
		modellist->m_modelQ = (struct sim_model_s *)
			sim_alloc(sizeof(union table_ptr), S_CAZM);
		modellist->m_modelF = (struct sim_model_s *)
			sim_alloc(sizeof(union table_ptr), S_CAZM);
	    	if(sim_get_table_now(modellist->m_modelQ,
		    filenameQ, (char *)NULL) == SIM_FAILED) {
			sim_error(S_FATAL, S_CAZM,
			"Table \"%s\" has incorrect format!", filenameQ);
		    exit(1);
		}
		else
		    modellist->m_flag = TRUE;

	    	if(sim_get_table_now(modellist->m_modelF,
		    filenameF, (char *)NULL) == SIM_FAILED) {
			sim_error(S_FATAL, S_CAZM,
			"Table \"%s\" has incorrect format!", filenameF);
		    exit(1);
		}
		else
		    modellist->m_flag = TRUE;
	    } 
	    else {
				/* Else it is a .MODEL  statement */
		modellist->m_modelQ = NULL;
		modellist->m_modelF = NULL;
		modellist->m_flag = TRUE;
	    }

/* Check to see if this model is an rc_resmodel. If so, we want to add it to
   a small list of rc_resmodels only */

	    if( type == RC_RESISTOR )
		rc_list( modellist );

	} else {

					/* model has already been hashed
					 * write over the old model.
					 */
	    modellist = modellist->m_next;

	    if (filenameF != NULL) { 	/* then we have to read in table */

		if ( modellist->m_type != MOSFET ) {
		    if (sim_get_table_now(modellist->m_modelQ,
			filenameQ, (char *)NULL) == SIM_FAILED) {
			sim_error(S_FATAL, S_CAZM,
			"Table \"%s\" has incorrect format!", filenameQ);
			exit(1);
		    }
		    else
			modellist->m_flag = TRUE;
			
		    if(sim_get_table_now(modellist->m_modelF,
			filenameF, (char *)NULL) == SIM_FAILED) {
			sim_error(S_FATAL, S_CAZM,
			"Table \"%s\" has incorrect format!", filenameF);
			exit(1);
		    }
		    else
			modellist->m_flag = TRUE;
		} else {		/* read in transistor */
	            struct areatable_s *tp;		/* hash table pointer */
		    int i;

		    if(sim_get_table_now(modellist->m_paramlist->p_modelF,
			filenameF, (char *)NULL) == SIM_FAILED) {
		        sim_error(S_FATAL, S_CAZM,
			    "Table \"%s\" has incorrect format!", filenameF);
			exit(1);
		    }
		    else
			modellist->m_flag = TRUE;

					/* Do it */
	            for (i = 0; i < AP_HASHSIZE; i++)
		        if((tp = modellist->m_paramlist->p_tab[i]) != NULL) {
	    	            if(sim_get_table_now(tp->a_cp->c_modelQ, 
				filenameQ, (char *)NULL) == SIM_FAILED) {
				    sim_error(S_FATAL, S_CAZM,
					"Table \"%s\" has incorrect format!",
					filenameQ);
				    exit(1);
			    }
			    else
				modellist->m_flag = TRUE;
		        modellist->m_modelQ = tp->a_cp->c_modelQ;
			}

		    modellist->m_modelF = modellist->m_paramlist->p_modelF;
		}

	    } else { 		/* .model card for previously mentioned
				 * mosfet.
				 */

	        modellist->m_param = params;
		modellist->m_flag = TRUE;
	    }
	}
}


/*
-----------------------------------------------------------
|    HASH_DEVICE
|    find and insert the device name and pointer to table
|
| Parameters -
|         name - modelname
|
|    The top most category is linked list of the model name (ie "penh")
|    For each modelname there is a linked list of transistor lengths and widths,
|    For each unique length and width there is a hash table for 
|    area/perim of the source and drain.
------------------------------------------------------------
*/
hash_device(gp, name, trans, modellist, cp, type)
Param *gp;
char *name;
struct sp_mosfet_s *trans;
struct modellist_s *modellist;
struct circuit_s *cp;
int type;			/* Diode, mosfet ... */
{
	struct paramlist_s *pl;		/* parameter list pointer */
	struct sp_bipolar_s *bp;	/* used for bipolar transistor */
	struct sp_jfet_s *jp;		/* used for jfet transistor */
	struct sp_mesfet_s *mf;		/* used for mesfet transistor */
	double areafactor;
	int notdone = TRUE;

	while  (modellist->m_next != NULL && notdone)
	    if (modellist->m_next->m_type == type &&
	        strcmp(modellist->m_next->m_name, name) == 0)
		notdone = FALSE;
	     else 
	        modellist = modellist->m_next;

	if (modellist->m_next == NULL ) 	{	
					/* insert new name */
	    modellist->m_next = (struct modellist_s *) sim_alloc(
			sizeof(struct modellist_s), S_CAZM);
	    modellist = modellist->m_next;
	    modellist->m_next = NULL;
	    modellist->m_paramlist = NULL;
	    modellist->m_param = NULL;
	    modellist->m_name = name;
	    modellist->m_type = type;
	    modellist->m_flag = FALSE;


	    if (type == BSIM_RESISTOR || type == BSIM_CAPACITOR) {

		/* Attach model to device info structure */
	        cp->c_params->pre_comp = (struct generic_s *) modellist;

	    } else 
            if (type == GENDEV) {
		struct func_s *f;

		f = (struct func_s *) cp;
	 	f->model = (struct sp_genmodel_s *) modellist;
	    } else {
	    				/* add length, width, ... */
		if (trans != NULL) {
		   add_size(gp, modellist, cp, trans, type);
		   modellist->m_modelF = NULL;
		} else {		/* allocate space for the macro */
		    modellist->m_modelF = cp->c_modelF = (struct sim_model_s*)
			sim_alloc( sizeof(union table_ptr), S_CAZM);
		    modellist->m_modelQ = cp->c_modelQ = (struct sim_model_s*)
			sim_alloc( sizeof(union table_ptr), S_CAZM);
		}
	    }
	} else {

				/* there is either an existing table
				 * for this transistor or a .model
				 * card for this transistor. If it is
				 * a .model card, we must find the one
				 * corresponding to the transistor size
				 * The same for a macromodel without size prob.
				 */
		
	    modellist = modellist->m_next;
	    pl = modellist->m_paramlist;

	    if (type == BSIM_RESISTOR || type == BSIM_CAPACITOR) {

		/* Attach model to device info structure */
	        cp->c_params->pre_comp = (struct generic_s *) modellist;

	    } else 
            if (type == GENDEV) {
		struct func_s *f;

		f = (struct func_s *) cp;
	 	f->model = (struct sp_genmodel_s *) modellist;
	    } else
	    if (trans == NULL) {	/* have a macro */
		cp->c_modelF = modellist->m_modelF;
		cp->c_modelQ = modellist->m_modelQ;
	    } else { 		/* Otherwise it is a transistor */
				/* table has not been read in so save info */
				/* look for transistor with same sizes */
				/* or for a diode with same area */

	    if (pl == NULL) {	/* First time through list */
	       add_size(gp, modellist, cp, trans, type);
	    } else {	/* Second time through list */
		switch(type) {
		    case DIODE: 
			hash_area(gp, pl->p_tab,trans,cp, type);
			break;
		    case JFET: 
			jp = (struct sp_jfet_s *) trans;
			areafactor = jp->areafactor;
			while ((pl->p_width != areafactor) &&
				(pl->p_next != NULL))
			    pl = pl->p_next;
				    /* check to see if we found one */
			if (pl->p_width == areafactor) {
			    cp->c_modelF = pl->p_modelF;
			    cp->c_modelQ = pl->p_modelQ;
				    /* otherwise insert a new entry */
			} else 
			    add_size(gp, modellist, cp, trans, type);
			break;
		    case BIPOLAR: 
			bp = (struct sp_bipolar_s *) trans;
			areafactor = bp->areafactor;
			while ((pl->p_width != areafactor) &&
				(pl->p_next != NULL))
			    pl = pl->p_next;
				    /* check to see if we found one */
			if (pl->p_width == areafactor) {
			    cp->c_modelF = pl->p_modelF;
			    cp->c_modelQ = pl->p_modelQ;
				    /* otherwise insert a new entry */
			} else 
			    add_size(gp, modellist, cp, trans, type);
			break;
		    case MESFET: 
			mf = (struct sp_mesfet_s *) trans;
			while (((pl->p_length != mf->length) || 
			   (pl->p_width != mf->width) ||
			   (pl->p_multiplier != mf->multiplier) ) &&
			   (pl->p_next != NULL))
				pl = pl->p_next;

				    /* check to see if we found one */
			if((pl->p_length == mf->length) && 
			   (pl->p_width == mf->width) &&
			   (pl->p_multiplier == mf->multiplier)) {
				cp->c_modelF = pl->p_modelF;
				cp->c_modelQ = pl->p_modelQ;
				hash_area(gp, pl->p_tab, trans, cp, type);
				    /* otherwise insert a new entry */
			} else 
			    add_size(gp, modellist, cp, trans, type);
			break;

				/* Normal MOS transistors */
				/* Level One through level four models */
		    case MOSFET: 
			while (((pl->p_length != trans->length) || 
			   (pl->p_width != trans->width) ) &&
			   (pl->p_next != NULL))
				pl = pl->p_next;

				/* check to see if we found one */
			if ((pl->p_length == trans->length) && 
			    (pl->p_width == trans->width)) {
				cp->c_modelF = pl->p_modelF;
				hash_area(gp, pl->p_tab, trans, cp, type);
				    /* otherwise insert a new entry */
			} else 
			    add_size(gp, modellist, cp, trans, type);
			break;
		    }

	    } 
	    }
	}
}
/*
----------------------------------------------------------------------
|  ADD_SIZE
|  add transistor sizes to the list
----------------------------------------------------------------------
*/
add_size(gp, modellist, cp, trans, type)
Param *gp;
struct modellist_s *modellist;
struct circuit_s *cp;
struct sp_mosfet_s *trans;
int type;			/* diode, mosfet ... */
{
	int i;
	struct paramlist_s *pl;		/* parameter list pointer */
	struct sp_bipolar_s *bp;	/* used for bipolar transistor */
	struct sp_jfet_s *jp;		/* used for jfet transistor */
	struct sp_mesfet_s *mf;		/* used for mesfet transistor */

	pl = (struct paramlist_s *) sim_alloc(sizeof(struct paramlist_s), 
			S_CAZM);
	pl->p_next = modellist->m_paramlist;
	modellist->m_paramlist =  pl;

	if (type == BIPOLAR) {
	    bp = (struct sp_bipolar_s *) trans;
	    pl->p_width = bp->areafactor;
	    pl->p_modelF = (struct sim_model_s *)
		sim_alloc(sizeof(struct sim_model_s), S_CAZM);
	    cp->c_modelF = pl->p_modelF;
	    pl->p_modelQ = (struct sim_model_s *)
		sim_alloc(sizeof(struct sim_model_s), S_CAZM);
	    cp->c_modelQ = pl->p_modelQ;
	    return;
	} else
	if (type == JFET) {
	    jp = (struct sp_jfet_s *) trans;
	    pl->p_width = jp->areafactor;
	    pl->p_modelF = (struct sim_model_s *)
		sim_alloc(sizeof(struct sim_model_s), S_CAZM);
	    cp->c_modelF = pl->p_modelF;
	    pl->p_modelQ = (struct sim_model_s *)
		sim_alloc(sizeof(struct sim_model_s), S_CAZM);
	    cp->c_modelQ = pl->p_modelQ;
	    return;
	} else {
	    if (type == MESFET) {
		mf = (struct sp_mesfet_s *) trans;

		pl->p_width = mf->width;
		pl->p_length = mf->length;
		pl->p_multiplier = mf->multiplier;
		pl->p_modelF = (struct sim_model_s *)
		    sim_alloc(sizeof(union table_ptr), S_CAZM);
		cp->c_modelF = pl->p_modelF;
		pl->p_modelQ = (struct sim_model_s *)
		    sim_alloc(sizeof(union table_ptr), S_CAZM);
		cp->c_modelQ = pl->p_modelQ;
	    } else
	    if (type == MOSFET) {
				/* level 0ne through level three models */
				/* save size information */
		pl->p_width = trans->width;
		pl->p_length = trans->length;
				/* steady state current does not depend on */
				/* areas or perimeters of the drain/source */
		pl->p_modelF = (struct sim_model_s *)
			sim_alloc(sizeof(union table_ptr), S_CAZM);
		cp->c_modelF = pl->p_modelF;
	    } else {		/* Diode */
		pl->p_width = 0;
		pl->p_length = 0;
		pl->p_modelF = (struct sim_model_s *)
			sim_alloc(sizeof(union table_ptr), S_CAZM);
		cp->c_modelF = pl->p_modelF;
	    }
				    /* clear table */
	    for (i = 0 ; i < AP_HASHSIZE; i++)
		    pl->p_tab[i] = NULL;

				/* hash area and perimeter */
	    hash_area(gp, pl->p_tab, trans, cp, modellist->m_type);
	}

}
/*
------------------------------------------------------------
|  HASH_AREA
|  hash the area of the device 
------------------------------------------------------------
*/
hash_area(gp, table, trans, cp, type)
Param *gp;
struct areatable_s **table;		/* hash table */
struct sp_mosfet_s *trans;
struct circuit_s *cp;			/* circuit entry pointer */
int type;
{
	int hashval;
	int notdone = TRUE;
	double as, ad, ps, pd;
	struct areatable_s *tp;		/* hash table pointer */
	struct sp_diode_s *d_ptr;
	struct sp_mesfet_s *mf;		/* used for mesfet transistor */

	if (type == MOSFET) {
	    as = trans->sarea;
	    ad = trans->darea;
	    ps = trans->sperim;
	    pd = trans->dperim;
	
				/* Compute hash value */
	    hashval = ((int) (as * ad * 1.0e25)) % AP_HASHSIZE;
	    if (hashval < 0)
	       hashval = 0;

	    tp = table[hashval];
	    while (tp != NULL && notdone)
	        if ((tp->a_as != as) || (tp->a_ad != ad) ||
		    (tp->a_ps != ps) || (tp->a_pd != pd )) {
		    tp = tp->a_next;
	        } else {
		    notdone = FALSE;
	        }

	    if (notdone) {		/* create new entry */
	        tp = (struct areatable_s *)
			sim_alloc(sizeof(struct areatable_s), S_CAZM);
	        tp->a_cp = cp;
	        tp->a_as = as;
	        tp->a_ad = ad;
	        tp->a_ps = ps;
	        tp->a_pd = pd;
	        tp->a_next =  table[hashval];
	        table[hashval] = tp;
				/* allocate space for charge table */
	        cp->c_modelQ = (struct sim_model_s *)
			sim_alloc(sizeof(union table_ptr), S_CAZM);

				/* keep track of how many unique transistors */
	    	gp->p_count.c_uniquetr++;

	    } else {		/* entry exist for these sizes */
	        cp->c_modelQ = tp->a_cp->c_modelQ;
	    }
	} else if (type == MESFET) {
	    mf = (struct sp_mesfet_s *) trans;

	    hashval = ((int) (mf->areafactor)) % AP_HASHSIZE;
	    if (hashval < 0)
	       hashval = 0;

	    tp = table[hashval];
	    while (tp != NULL && notdone)
	        if (tp->a_as != mf->areafactor)
		    tp = tp->a_next;
	        else {
		    notdone = FALSE;
	        }
	    if (notdone) {		/* create new entry */
	        tp = (struct areatable_s *)
			sim_alloc(sizeof(struct areatable_s), S_CAZM);
	        tp->a_cp = cp;
	        tp->a_as = mf->areafactor;
	        tp->a_next =  table[hashval];
	        table[hashval] = tp;
				/* allocate space for charge table */
	        cp->c_modelF = (struct sim_model_s *)
			sim_alloc(sizeof(union table_ptr), S_CAZM);
	        cp->c_modelQ = (struct sim_model_s *)
			sim_alloc(sizeof(union table_ptr), S_CAZM);
	    } else {		/* entry exist for these sizes */
	        cp->c_modelQ = tp->a_cp->c_modelQ;
	        cp->c_modelF = tp->a_cp->c_modelF;
	    }

	} else {		/* diode */
	    d_ptr = (struct sp_diode_s *) trans;
	    hashval = ((int) (d_ptr->dioarea * 1.0e25)) % AP_HASHSIZE;
	    if (hashval < 0)
	       hashval = 0;

	    tp = table[hashval];
	    while (tp != NULL && notdone)
	        if (tp->a_as != d_ptr->dioarea)
		    tp = tp->a_next;
	        else {
		    notdone = FALSE;
	        }

	    if (notdone) {		/* create new entry */
	        tp = (struct areatable_s *)
			sim_alloc(sizeof(struct areatable_s), S_CAZM);
	        tp->a_cp = cp;
	        tp->a_as = d_ptr->dioarea;
	        tp->a_ps = d_ptr->dioperim;
	        tp->a_next =  table[hashval];
	        table[hashval] = tp;
				/* allocate space for charge table */
	        cp->c_modelF = (struct sim_model_s *)
			sim_alloc(sizeof(union table_ptr), S_CAZM);
	        cp->c_modelQ = (struct sim_model_s *)
			sim_alloc(sizeof(union table_ptr), S_CAZM);
	    } else {		/* entry exist for these sizes */
	        cp->c_modelQ = tp->a_cp->c_modelQ;
	        cp->c_modelF = tp->a_cp->c_modelF;
	    }
	}
}
/*
-----------------------------------------------------------
|    HASH_IND
|    find and or insert an inductor name into hash table 
|
-----------------------------------------------------------
*/
struct hash_table_s
*hash_ind(name, lp)
char *name;
struct inductor_s *lp;
{
	struct hash_table_s *ptr_hash;		/* temporary ptr */
	struct hash_table_s *new_hash;		/* temporary ptr */
	int hashval;				/* index into hash table */

	ptr_hash = find_name(name, INDUCTOR, sub_hash);
	if (ptr_hash == NULL ) 	{	/* insert the new name */
		hashval = hash_function(name);
		ptr_hash = sub_hash[hashval];

					/* allocate new record and insert */
		new_hash = hashalloc();
		new_hash->h_next = ptr_hash;
		new_hash->h_info = (struct sub_s *) lp;
		sub_hash[hashval] = new_hash;
		new_hash->h_type = INDUCTOR;
		new_hash->h_name = name;
		return(NULL);
	} else
		return(ptr_hash);
}
/*
-----------------------------------------------------------
|    HASH_SUB
|    find and insert subcircuit into hash table 
|
| Parameters - assumes that the subcircuit does not exist.
|         name - name of the subcircuit
|	  namlst - list of arguments
|
| Returns - pointer to hash table entry.
| Side effects -
|	  The reserved words are added to the new circuit hash table
|	  followed by the argument list. The hash table entry for
|	  the subcircuit is created. If a subcircuit of the same name
|	  already exists, then the program aborts (an error message is
|	  printed). 
|
------------------------------------------------------------
*/
struct hash_table_s
*hash_sub(name, namelst, hashtable, node_names)
char *name;
struct sp_pinlist_s *namelst;
struct hash_table_s **hashtable;
char ***node_names;
{
	struct hash_table_s *ptr_hash;		/* temporary ptr */
	struct hash_table_s *new_hash;		/* temporary ptr */
	struct sub_s *sub_ptr;			/* caste for h_info */
	struct sp_pinlist_s *p;			/* loop var for args */
	struct hash_table_s *find_name();	/* function */
	int argcnt;				/* number of arguments */
	int hashval;				/* index into hash table */
	int node_num;				/* next unique number */
	int i;

	ptr_hash = find_name(name, SUB_CIR, sub_hash);
	if (ptr_hash == NULL ) 	{	/* insert the new name */
		hashval = hash_function(name);
		ptr_hash = sub_hash[hashval];

					/* allocate new record and insert */
		new_hash = hashalloc();
		new_hash->h_info = (struct sub_s *) 
			sim_alloc(sizeof(struct sub_s), S_CAZM);

		new_hash->h_next = ptr_hash;
		sub_hash[hashval] = new_hash;
		new_hash->h_type = SUB_CIR;
		new_hash->h_name = name;

		node_num = GNDNUM;

					/* initialize hash table */
		for (i = 0; i < HASH_TABLESIZE; i++)
		    hashtable[i] = NULL;

					/* hash global ground */
					/* if not in main routine */
		if (strcmp(name,MAIN_SUB) != 0) {
		    node_num = -1;
		    (void) hash_nodes(GLOBAL_GND, &node_num, hashtable, (char ***) NULL);
		    node_num = GNDNUM;
		} else {

		    (void) hash_nodes(GND, &node_num, hashtable, node_names);
		    node_num = GNDNUM;
		    (void) hash_nodes(GND2, &node_num, hashtable, node_names);
		    node_num = GNDNUM;
		    (void) hash_nodes(GND3, &node_num, hashtable, node_names);
		    node_num = GNDNUM;
		    (void) hash_nodes(GND4, &node_num, hashtable, node_names);
		    (void) hash_nodes(VDD, &node_num, hashtable, node_names);
		    node_num = VDDNUM;
		    (void) hash_nodes(VDD2, &node_num, hashtable, node_names);
		    node_num = 2;
		    (void) hash_nodes(GLOBAL_GND, &node_num, hashtable, node_names);
	        }

					/* hash arguments to the subcircuit */
		argcnt = 0;
		sub_ptr = (struct sub_s *) new_hash->h_info;
		for (p = namelst; p != NULL; p = p->next, argcnt++)
		    sub_ptr->s_ext_nodes[argcnt] = hash_nodes(
				p->name, &node_num, hashtable, node_names);
		sub_ptr->s_num_arg = argcnt;
		sub_ptr->s_max_def = node_num - 1;

		/*
		if (argcnt != node_num && strcmp(name,MAIN_SUB) != 0)
		    sim_error(S_WARNING, S_CAZM, 
		"Non-unique node names in argument list for subcircuit %s",name);
		*/
		return(new_hash);
	}
	else {
		sim_error(S_FATAL, S_CAZM, "redefinition of subcircuit");
		fprintf(stderr,"%s \n", name);
		exit(1);
	}
}

/*
-----------------------------------------------------------
|    FIND_NAME
|    finds and record in the hash table if it exists
|
| Parameters -
|         name - character string on which the hash is formed
|         type - NODE or DEVICE
|
| Returns -
|         Pointer to the record if it is found, otherwise NULL.
|
------------------------------------------------------------
*/
struct hash_table_s 
*find_name(name, type, hashtable)
char *name;
int type;
struct hash_table_s **hashtable;
{
	int notfound;				/* boolean flag */
	struct hash_table_s *ptr_hash;		/* temporary pointer */

	notfound = TRUE;
	ptr_hash = hashtable[hash_function(name)];
	while ((ptr_hash != NULL) && notfound) {
		if (type == ptr_hash->h_type) {
			if (strcmp(name, ptr_hash->h_name) == 0)
				notfound = FALSE;
			else
				ptr_hash = ptr_hash->h_next;
		}
		else 
			ptr_hash = ptr_hash->h_next;
	}
	return(ptr_hash);
}
	
/*
-----------------------------------------------------------
|    REMAP
|    Renumbers the nodes so that the unknown nodes are the lowest numbers
|
| Parameters - The boundary list and the circuit list.
|
| Returns - Nothing, but later may need to return the map.
|
| Side effects -
|         After the mapping is performed, the circuit list will be altered
|    to reflect the change. The boundary node and plot lists are also updated
|
------------------------------------------------------------
*/
remap(gp)
struct param_s *gp;
{
	int *map;		/* map[old node #] = new node # */
	int *factored;		/* factored[node] = TRUE if eliminated */
	int old_node;
	int i, j, k, ii;	/* array index */
	int vv_cnt;
	int add_rows_current();
	struct boundary_s *b;	/* pointer to traverse boundary list */
	struct factored_s *of_old; /* temp save for b-list */
	struct other_wavef_s *ow;/* Other waveform pointer */
	struct factored_s *fp, *of, *tf; 
	int not_done;
	int row;
	int bound_left;		/* flag - no more v-sources attached to */
				/* boundary-nodes */
	
		/* check for redef of Vdd or GND */
	source_redef(gp);
		/* add the necessary rows for vvts, cvts, ccts */
	vv_cnt = add_rows_current(gp);


		/* create map array and initialize it to an identity map */
	map = (int *) sim_alloc((gp->p_num_nodes) * 
		sizeof(int), S_CAZM);
	factored = (int *) sim_alloc((gp->p_num_nodes) * 
		sizeof(int), S_CAZM);
	for ( i = 0; i < gp->p_num_nodes; i++) {
		map[i] = i;
	        factored[i] = FALSE;
	}

		/* create voltage list to factor */
	of = (struct factored_s *) sim_alloc(sizeof(struct factored_s), S_CAZM);
	tf = of;
	for (b = gp->p_boundary; b != NULL; b= b->b_next) {
			/* Check to see if we can factor out */
	    if (b->b_row == 0) {
	        tf->f_next = (struct factored_s *) sim_alloc(
			sizeof(struct factored_s), S_CAZM);
	        tf = tf->f_next;
	        tf->f_type = PWL_V;
	        tf->f_volt = ( struct generic_s *) b;
	        tf->node1 = &(b->b_node1);
	        tf->node2 = &(b->b_node2);
	        tf->row = &(b->b_row);
		b->b_floating = FALSE;
	    } else {
		b->b_floating = TRUE;
		fprintf(stderr,"Vsrc %s\n",b->b_name);	
	    }
	}
	of = of->f_next;
		/* Now copy other waveforms */
	for ( ow = gp->p_other_v; ow != NULL ; ow = ow->o_next) {
	    tf->f_next = (struct factored_s *) sim_alloc(
			sizeof(struct factored_s), S_CAZM);
	    tf = tf->f_next;
	    tf->f_type = OTHER_V;
	    tf->f_volt = ( struct generic_s *) ow;
	    tf->node1 = &(ow->o_node1);
	    tf->node2 = &(ow->o_node2);
	    tf->row = &(ow->o_row);
	}
	tf->f_next = NULL;

		/* loop through the boundary node lists and assign those
		* node numbers to the highest node numbers
		* by swapping boundary number with the next hi number
		* pointed to by 'i'. Then the routine makes sure it
		* is not swapping the wrong node 
		* We will also order the voltage sources so that,
		* when they are factored out of the system, there is no fill.
		*/
	i = gp->p_num_nodes - 1;
	not_done = TRUE;
				/* first node to be added (GND) */
	bound_left = TRUE;
	fp = NULL;		/* factored list is zero initially*/
	while (not_done) {
	    not_done = FALSE;
	    of_old = NULL;
	    while (of != NULL) {
				/* make factored node second */
		swap_nodes_v(of, factored, i);
	        old_node = map[*(of->node1)];
				/* if not already attached postpone */
		if (!factored[*(of->node2)] && !bound_left) {
		    tf = of;
		    of = of->f_next ;
		    tf->f_next = of_old;
		    of_old = tf;
		} else {       	/* add to final factored list */
				/* node1 becomes the relative node */
				/* The current in node1 -> node2 */
	            if (old_node <= i) { /* not already a boundary node */
	     	        for (j = i; map[j] != i; j = map[j]);
	     	        map[*(of->node1)] = i;
	     	        map[j] = old_node;
	     	        i--;
	            }
		    factored[*(of->node1)]= TRUE;
		    factored[*(of->node2)]= TRUE;
		    tf = of;
		    of = of->f_next;
		    tf->f_next = fp;
		    fp = tf;
		    bound_left = FALSE;
		    not_done = TRUE;
		}
	    }
	    of = of_old;
	    if (!not_done && of != NULL) {
		not_done = TRUE;
		bound_left = TRUE;
	    }
	}

			/* order GND and global_gnd last */
	k = gp->p_num_nodes-1;
	for (tf = fp; tf != NULL; tf= tf->f_next) {
	    if (*tf->node1 == *tf->node2) {
		for (j = k; map[j] != k; j = map[j]);
		old_node = map[*(tf->node1)];
		map[*(tf->node1)] = k;
		map[j] = old_node;
		k--;
	    }
	}
			/* order the vvt currents last inside numind */
	k = i;
	for (ii = 0 ; ii < vv_cnt ; ii++) {
	    for (j = k; map[j] != k; j = map[j]);
	    old_node = map[gp->p_num_nodes-1-ii];
	    map[gp->p_num_nodes-1-ii] = k;
	    map[j] = old_node;
	    k--;
	}
			/* After we factored the voltage supplies */

	gp->p_fact = fp;


	row = gp->p_num_nodes - NUM_GNDS;
	for(fp = gp->p_fact, tf = NULL; fp != NULL; tf = fp, fp = fp->f_next) { 
			/* link the list doubley */
		fp->f_prev = tf;
			/* Don't count GND sources */
		if (*fp->node1 == *fp->node2)
		       continue;
		*fp->row = row;
		row++;
	}
	gp->p_fact_rev = tf;


		/* save the number of non boundary nodes */
	gp->p_num_ind = i + 1;

	/*
	for(i=0; i < gp->p_num_nodes; i++)
		printf("map[%d]=%d\n", i, map[i]);
	*/

	remap_all(gp, map);
	sim_free((char *)map, S_CAZM);
	sim_free((char *)factored, S_CAZM);
}
int
ret_node(p, node_num)
struct factored_s *p;
int node_num;
{
	struct boundary_s *b;	/* pointer to traverse boundary list */
	struct other_wavef_s *ow;/* Other waveform pointer */
	struct volt_volt_s *vv;	/* VV waveform pointer */

	switch(p->f_type) {
	case PWL_V:
	    b = (struct boundary_s *) p->f_volt;
	    if (node_num == 1)
	       return(b->b_node1);
	    else
	       return(b->b_node2);
	    break;
	case VV_V:
	    vv = (struct volt_volt_s *) p->f_volt;
	    if (node_num == 1)
	       return(vv->v_node1);
	    else
	       return(vv->v_node2);
	    break;
	case OTHER_V:
	    ow = (struct other_wavef_s *) p->f_volt;
	    if (node_num == 1)
	        return(ow->o_node1);
	    else
	        return(ow->o_node2);
	    break;
	}
}
/*
-----------------------------------------------------------
|    SWAP_NODES_V
|    Reorders the nodes in the  boundary list and corrects the voltage
|    to make the boundary node the second node 
|
-----------------------------------------------------------
*/
swap_nodes_v(of, factored, num_ind)
struct factored_s *of;
int *factored;
int num_ind;
{
	int i;
	struct boundary_s *b;	/* pointer to traverse boundary list */
	struct other_wavef_s *ow;/* Other waveform pointer */
	struct volt_volt_s *vv;	/* VV waveform pointer */

	if (!factored[*(of->node2)] && factored[*(of->node1)]) {
	    i = *(of->node2);
	    switch(of->f_type) {
	    case PWL_V:
	    	b = (struct boundary_s *) of->f_volt;
	    	b->b_node2 = b->b_node1;
	    	b->b_node1 = i;
				/* now fix voltages */
	    	for (i = 0; i < b->b_length; i++)
			b->b_value[i] = -b->b_value[i];
	    break;
	    case VV_V:
	    	vv = (struct volt_volt_s *) of->f_volt;
	    	vv->v_node2 = vv->v_node1;
	    	vv->v_node1 = i;
				/* now fix voltages */
		vv->v_value = - vv->v_value;
	    break;
	    case OTHER_V:
	    	ow = (struct other_wavef_s *) of->f_volt;
	    	ow->o_node2 = ow->o_node1;
	    	ow->o_node1 = i;
				/* negate amplitude  */
		if(ow->o_type == CMD_SIN)
		    ow->o_value[1] = - ow->o_value[1];

/*
	ow->o_type == CMD_SIN
	ow->o_type == SP_SIN
	ow->o_type == SP_EXP

	
	THIS CODE MUST BE FIXED!!!!!!
*/
	    break;
	    }
	}
}
/*
-----------------------------------------------------------
|    REMAP_ALL
|    Renumbers all nodes in all the circuit and control lists
|
| Parameters - The boundary list and the circuit list.
|
-----------------------------------------------------------
*/
remap_all(gp, map)
struct param_s *gp;
int *map;
{
	char **node_nt;		/* temporary node name holder */
	FILE *fd;		/* file descriptor for map save */
	struct boundary_s *b;	/* pointer to traverse boundary list */
	struct circuit_s *c;	/* pointer to traverse circuit list */
	struct main_plot_s *pm;/* pointer to traverse outer plot list */
	struct plot_s	*p;	/* pointer to traverse plot list */
	struct ac_volt_s *acv;	/* pointer to info for ac analysis */
	struct ac_curr_s *acc;  /* pointer to input currents for ac analysis */
	struct spcmd_assign_s *dcg; /* pointer to initial guesses for dc */
	struct spcmd_assign_s *ic; /* pntr to initial condition for transient */
	struct other_wavef_s *ow;/* Other waveform pointer */
	struct volt_volt_s *vv;	/* VV waveform pointer */
	struct current_cont_s *cc;/* VV waveform pointer */
	struct cmd_power_s *pt;	/* power */
	struct func_s *func;	/* functions */
	int i, k;

		/* now renumber the boundary nodes */
	for ( b = gp->p_boundary; b != NULL ; b = b->b_next) {
		b->b_node1 = map[b->b_node1];
		b->b_node2 = map[b->b_node2];
	}
	for ( b = gp->p_currb; b != NULL ; b = b->b_next) {
		b->b_node1 = map[b->b_node1];
		b->b_node2 = map[b->b_node2];
	}
		
		/* renumber the nodes in the circuit list */
	for ( c = gp->p_circuit; c != NULL ; c = c->c_next){
		for (i = 0; i < c->c_numnodes; i++)
			c->c_nodes[i] = map[c->c_nodes[i]];
	}

		/* renumber the nodes in the plot list */
	for (pm = gp->p_plot; pm != NULL ; pm = pm->next) 
	   for ( p = pm->plot_n; p != NULL ; p = p->p_next) {
	    if (p->p_printype != NULL ) {
	        p->p_nodes[0] = map[p->p_nodes[0]];
	        p->p_nodes[1] = map[p->p_nodes[1]];
	    }
	}

		/*renumber the nodes in the init list for dc, trans, and power*/
	if (gp->p_dcg != NULL)
	   for (dcg = gp->p_dcg; dcg != NULL ; dcg = dcg->next) 
		    dcg->node_num = map[dcg->node_num];


		/* renumber the nodes in the list for ac analysis */
	if (gp->p_ac_volt != NULL) 
	   for (acv = gp->p_ac_volt; acv != NULL ; acv = acv->next) {
	            acv->node_num1 = map[acv->node_num1];
	            acv->node_num2 = map[acv->node_num2];
	   }	

		/* renumber the nodes in the list for ac analysis */
	if (gp->p_ac_curr != NULL) 
	   for (acc = gp->p_ac_curr; acc != NULL ; acc = acc->next) {
	            acc->node_num1 = map[acc->node_num1];
	            acc->node_num2 = map[acc->node_num2];
	   }	

	 for (ic = gp->p_ic; ic != NULL ; ic = ic->next) 
		    ic->node_num = map[ic->node_num];

	 for (ow = gp->p_other_i; ow != NULL ; ow = ow->o_next) {
		    ow->o_node1 = map[ow->o_node1];
		    ow->o_node2 = map[ow->o_node2];
	 }

	 for (ow = gp->p_other_v; ow != NULL ; ow = ow->o_next) {
		    ow->o_node1 = map[ow->o_node1];
		    ow->o_node2 = map[ow->o_node2];
	 }

	 for (vv = gp->p_volt_v; vv != NULL ; vv = vv->v_next) {
		    vv->v_node1 = map[vv->v_node1];
		    vv->v_node2 = map[vv->v_node2];
		    vv->v_node3 = map[vv->v_node3];
		    vv->v_node4 = map[vv->v_node4];
		    vv->v_row = map[vv->v_row];
	 }
	 for (cc = gp->p_curr_c; cc != NULL ; cc = cc->next) {
		    cc->node1 = map[cc->node1];
		    cc->node2 = map[cc->node2];
		    cc->row = map[cc->row];
		    cc->row_cont = map[cc->row_cont];
	 }

	if (gp->p_power != NULL) {
	    for (pt = gp->p_power; pt != NULL ; pt = pt->p_next) {
	        pt->p_nodes[0] = map[pt->p_nodes[0]];
	        pt->p_nodes[1] = map[pt->p_nodes[1]];

	        if (pt->p_nodes[0] < gp->p_num_ind ||
	            pt->p_nodes[1] < gp->p_num_ind )
		    sim_error(S_WARNING, S_CAZM, 
"Power nodes are not boundary nodes, power information will be incorrect");
	    }

	}
	for (func = gp->p_func; func != NULL; func = func->next) {
	    for (i = 0; i < func->num_output; i++)
		func->o_nodes[i] = map[func->o_nodes[i]];
	    for (i = 0; i < func->num_input; i++)
		func->i_nodes[i] = map[func->i_nodes[i]];
	}

	    
		/* now output node map for debugging */
#ifdef DEBUG
	if (gp->p_debug_num > 1) {
	  if ((fd = fopen("node.map", "w")) == NULL) {
	    sim_error(S_WARNING, S_CAZM,"can't open node.map for write\n");
	    fd = stderr;
	    for (i = 0; i < gp->p_num_nodes; i++) 
	        fprintf(fd,"%d %s\n", map[i], node_names[i]);
	  } else {
	  for (i = 0; i < gp->p_num_nodes; i++) 
	    fprintf(fd,"%d %s\n", map[i], node_names[i]);
	  fclose(fd);
	  }
	}
#endif
	node_nt = (char **) sim_calloc(gp->p_num_nodes, sizeof(char *),
								S_CAZM);
		/* reorder node map for further use */
	for (i = 0; i < gp->p_num_nodes; i++) {
	     node_nt[map[i]] = node_names[i];
	}
		/* copy back */
	for (i = 0; i < gp->p_num_nodes; i++) {
	     node_names[i] = node_nt[i];
	}

	sim_free((char *)node_nt, S_CAZM);
}
/*
--------------------------------------------------------------------------
|     SPARSE_CREATE
|     form the ja array from the circuit description
|
|	Parameters - gp = contains circuit info
|	Returns - ja in following format :
|		ja[                                        ]
|			         ^                         ^
|	 	  (ptrs to rows) n+1    (ptrs to columns)  m
|	where
|	n = number of independent nodes (non boundary)
|	m = number of non zero elements in Jacobian
|
---------------------------------------------------------------------------
*/
sparse_create(gp, val_int, ja, flag)
struct param_s *gp;
Val_Int *val_int;
int *ja;
int flag;					/* AC flag */
{
	struct circuit_s *p;		        /* loop var for circuit */
	struct edge_s *t, *e;			/* edge loop var */
	struct edge_s **edge_list;		/* edge list */
	struct func_s *func;
	struct factored_s *f;
	int i, j, k;				/* loop indices */
	int gnd_nodes[2];
	int gnd_num;
	int num_nodes;				/* number of voltage rows */
	int *perm;
						/* in matrix */

					/* allocate and initialize edge
					*  list */
	
	edge_list = (struct edge_s **) sim_calloc(val_int->jasize+1, 
		     sizeof(struct edge_s *), S_CAZM);
	for (i = 0; i < val_int->jasize; i++)
	    edge_list[i] = NULL;
	perm = (int *) sim_calloc(sizeof(int), gp->p_num_nodes, S_CAZM);
					/* zero pointers */
	for (i = 0; i <= val_int->jasize; i++)
	    ja[i] = 0;

	if (flag == AC) {

					/* remove GND and global_gnd */
	    gnd_num = 0;
            for (f =  gp->p_fact; f != NULL ; f = f->f_next) {
                        /* add only node1 */
                if (*f->node1 == *f->node2) {
                    gnd_nodes[gnd_num] = *f->node2;
                    gnd_num++;
	        }
	    }
	    num_nodes = gp->p_num_nodes - NUM_GNDS;
	    for (func = gp->p_func; func != NULL; func = func->next) {
                for (i = 0; i < func->num_output; i++)
                    func->o_pos[i] = func->o_nodes[i] ;
            }
					/* set matrix positions */
	    for (p = gp->p_circuit; p != NULL; p = p->c_next) 
		for (i = 0; i < p->c_numnodes; i++) {
		    for (j = 0 ; j < 2; j ++)
			if (gnd_nodes[j] == p->c_nodes[i]) {
			   p->c_pos[i] = j + val_int->jasize;
			   break;
			} else
		           p->c_pos[i] = p->c_nodes[i];
		}

	} else {
					/* add information about floating
					   voltage sources */
	    indep_vsource(gp, perm);
	    num_nodes = gp->p_num_ind;
	}

				
					/* tally number of non-zeros (not
					*  diagonal) in each row of Jacobian.
					*  The number also represents the
					*  number of edges connected to a
					*  specific node.
					*/
	for (p = gp->p_circuit; p != NULL; p = p->c_next) {
	    for (i = 0 ; i < p->c_numnodes ; i++) 
		if (p->c_pos[i] < num_nodes)
		    for (j = 0; j < p->c_numnodes; j++) {
		    	if (p->c_pos[j] < num_nodes &&
			    j != i && p->c_pos[i] < p->c_pos[j]) {
			    off_diag(edge_list, ja, val_int, p->c_pos[i], 
				p->c_pos[j]);
			    }
		    }
	}

					/* update totals for functions */
	add_func_mat(gp->p_func, edge_list, ja, val_int);

					/* update totals for vvts */
	add_vvt_mat(gp, gp->p_volt_v, edge_list, ja, val_int);

					/* update totals for current-cntrl */
	add_cct_mat(gp, edge_list, ja, val_int);

					/* permute rows */
					/* CURRENTLY TURNED OFF */
	if (flag != AC) 
	    permute_rows(perm, edge_list, ja, num_nodes, val_int);
					/* use the totals in ja to set up
					*  pointers to the columns in each
					*  row 
					*/
	k = 2;
	for (i = 0; i < val_int->jasize; i++) {
	    j = ja[i];
	    ja[i] = k + val_int->jasize;
	    k = j + k;
	}
	ja[val_int->jasize] = k + val_int->jasize;


					/* add column numbers to the
					*  end of the ja vector using
					*  the row pointers in the
					*  head of ja and the edge list
					*/
	j = ja[0] - 1;
	for (i = 0; i < val_int->jasize; i++) {
	    for (e = edge_list[i]; e != NULL && e->e_node <= i; e = e->e_next);
	    for (; e != NULL; e = e->e_next) {
		ja[j] = e->e_node + 1;
		j++;
	    }
	}

					/* generate information for */
					/* rapid swapping of rows */
	if (flag != AC) 
	    set_to_from(edge_list, ja, val_int, perm);


					/* free the memory associated
					*  with the edge list */
					/* Check for independent nodes */
	for (i = 0; i < val_int->jasize; i++) 
	    for (e = edge_list[i]; e != NULL; ) {
		t = e->e_next;
		sim_free((char *)e, S_CAZM);
		e = t;
	    }
	sim_free((char *)edge_list, S_CAZM); 
	sim_free((char *)perm, S_CAZM); 

			/* set the positions for the assem */
	set_pos_vvt(gp, ja, val_int->jasize, gp->p_volt_v);

	set_pos_current(gp, ja, val_int->jasize);

			/* make two terminal devices assemble faster */
	assem_speedup(gp, ja, val_int->jasize);
#ifdef DEBUG
	if (gp->p_debug_num == 6) {
	    fprintf(stderr,"Ja = ");
	    for (i = 0; i < ja[val_int->jasize]; i++)
		fprintf(stderr," %d", ja[i]);
	    fprintf(stderr,"\n");
	}
#endif
}

struct hash_table_s *hashlimit=NULL;	/* top of the memory pool */
struct hash_table_s *hashpool=NULL;	/* current location in the buffer */
struct hash_table_s **hashlist=NULL;	/* keeps track of the pools */
int hashptr = 0;			/* index pointer to array hashlist */
int hashnum = HASH_LIST;		/* number of pointers in hashlist */

/* 
------------------------------------------------------------------
|   HASHALLOC
|   Allocate a hash structure from a pool
|
-----------------------------------------------------------------
*/

struct hash_table_s *
hashalloc()
{
    if(hashlist == NULL)
	hashlist = (struct hash_table_s **) 
		sim_alloc(sizeof(struct hash_table_s *) * HASH_LIST, S_CAZM);

    if ((unsigned) hashpool >= (unsigned) hashlimit)
    {
				/* Get one page for alloc pool */
	hashpool = (struct hash_table_s *)
		sim_alloc(HASH_ALLOC * sizeof(struct hash_table_s), S_CAZM);
	hashlimit = hashpool + (unsigned) HASH_ALLOC;
				/* keep track of memory so it can be freed */
	if (hashptr == hashnum-1) 
	    hash_realloc();

	hashlist[hashptr] = hashpool;
	hashptr++;
    }
    return(hashpool++);
}

/* 
------------------------------------------------------------------
|   HASH_REALLOC
|   Re_alloc the array of pointers to the hash structure pool.
|
-----------------------------------------------------------------
*/
hash_realloc()
{
	struct hash_table_s **temp;
	int i;

	hashnum = 2 * hashnum;

			/* Allocate new size */
	temp = (struct hash_table_s **) 
		sim_alloc(sizeof(struct hash_table_s *) * hashnum, S_CAZM);

			/* copy pointers to new space */
	for (i = 0 ; i < hashptr+1; i++)
		temp[i] = hashlist[i];

			/* free old array */
	sim_free((char *) hashlist, S_CAZM); 

	hashlist = temp;
}

/*
-------------------------------------------------------------------
|   CZ_MEM_FREE
|   frees up the memory associated with the hash table for now 
|
-------------------------------------------------------------------
*/
cz_sim_free()
{
	int i;

	for (i = 0 ; i < hashptr; i++) 
	    sim_free((char *) hashlist[i], S_CAZM);
				/* reset for later use */

	hashlimit=NULL;	/* top of the memory pool */
	hashpool=NULL;	/* current location in the buffer */
	hashptr=0;	/* pointer to array hashlist */
}
/*
-------------------------------------------------------------------
|   CZ_REALLOC
|   Reallocs memory for node name list
|
-------------------------------------------------------------------
*/
char **
cz_realloc(node_names, num_nodes, num)
char ***node_names;
int num_nodes;
int num;
{
	int i,j;
	char **temp;

			/* adjust num_node so it is on a 100 boundary */
	if ((num_nodes % 100) != 0)
	    j = num_nodes + 100 - (num_nodes % 100);
	else
	    j = num_nodes;

			/* alloc more space */
	temp = (char **) sim_calloc(sizeof(char *),j + num*100, S_CAZM);
	
			/* copy nodes to new space */
	for (i = 0 ; i < num_nodes; i++)
		temp[i] = (*node_names)[i];

			/* free old space */
	sim_free((char *)*node_names, S_CAZM); 

	return(temp);
}


/*
-------------------------------------------------------------------
|   SOURCE_REDEF
|   Removes old definition if the user has specified a new Vdd or GND
|
-------------------------------------------------------------------
*/
source_redef(gp)
struct param_s *gp;
{
	struct boundary_s *b_head;
	struct boundary_s *vdd;
	struct boundary_s *bt;
	struct boundary_s *btlast;
	int found;
	int k;

			/* Find the original VDD,
			 * and save the pointers 
			 */
	btlast = b_head = gp->p_boundary;
	for (bt = b_head; bt != NULL; bt = bt->b_next) {
	    if(bt->b_name != NULL) {
		if(strcmp(bt->b_name, VDDNAME) == 0) {
		    vdd = bt;
		    break;
		}
	    }
	    btlast = bt;
	}

	for (bt = b_head; bt != NULL; bt = bt->b_next) {
	    if ((vdd->b_node1 == bt->b_node1 && vdd->b_node2 == bt->b_node2) ||
	        (vdd->b_node1 == bt->b_node2 && vdd->b_node2 == bt->b_node1)) {

			/* delete old Vdd source if another source is found */
	        if(bt->b_name == NULL) {
		    btlast->b_next = vdd->b_next;
		}
		else if(strcmp(bt->b_name, VDDNAME) != 0) { 
		    btlast->b_next = vdd->b_next;
		}
	    }
	}

}
/*
-------------------------------------------------------------------
|   ADD_FUNC_MAT
|   Add function entries to the Jacobian
|
-------------------------------------------------------------------
*/
add_func_mat(func, edge_list, ja, val_int)
struct func_s *func;
struct edge_s **edge_list;
int *ja;
Val_Int *val_int;
{
	struct edge_s *e, *t;			/* edge loop var */
	struct edge_s *ep, *ep2;		/* temp pointers for sort */
	int i, j, k;				/* loop indices */
	int temp;				/* swap var */
	int *nodes;
	int tot;

	if (func==NULL || val_int->jasize == 0)
	    return;
	nodes = (int *) sim_calloc(2*val_int->jasize,sizeof(int),S_CAZM);
	for (func; func != NULL ; func = func->next) {
			/* loop through only output nodes */
	    
	    for (i = 0 ; i < func->num_output; i++) 
		nodes[i] = func->o_nodes[i];
	    for (i = func->num_output ; i < func->num_output+func->num_input; i++) 
		nodes[i] = func->i_nodes[i-func->num_output];
	    tot = func->num_output+func->num_input;
	    for (i = 0 ; i < tot; i++) 
		if (nodes[i] < val_int->jasize)
		    for (j = 0; j < tot; j++) {
		    	if (nodes[j] < val_int->jasize &&
			    nodes[i] != nodes[j] && 
				nodes[i] < nodes[j]) {
			    off_diag(edge_list, ja, val_int, nodes[i], 
				nodes[j]);
			}
	           }
	}
	sim_free(nodes,S_CAZM);
}
/*
-------------------------------------------------------------------
|   OFF_DIAG
|   Add a offdiagonal edge to the graph
|
-------------------------------------------------------------------
*/
off_diag(edge_list, ja, val_int, i, j)
struct edge_s **edge_list;
int *ja;
Val_Int *val_int;
int i;
int j;
{
    struct edge_s *e, *ep, *ep2;
    int temp;

		/* check to make sure it has not been
		*  counted twice and is in upper tri*/
    for (e = edge_list[i]; e != NULL &&
	 e->e_node != j; e = e->e_next);
    if (e == NULL) {
		/* node is new so add it to list */
		/* and sort it */
	e = (struct edge_s *) sim_alloc(sizeof(struct edge_s), S_CAZM);
	e->e_node = j;
	ep = ep2 = edge_list[i]; 
	while (ep != NULL) {
	    if (ep->e_node > e->e_node)
		ep = NULL;
	    else {
		ep2 = ep;
		ep = ep->e_next;
	     }
	}

	if (ep2 == NULL){	
					/* first one */
	   e->e_next = ep2;
	   edge_list[i] = e;
	} else {
	   e->e_next = ep2->e_next;
	   ep2->e_next = e;
					/* swap */
	   if (e->e_node < ep2->e_node) {
	       temp = e->e_node;
	       e->e_node = ep2->e_node;
	       ep2->e_node = temp;
	   }
	}
		/* keep track of count */
	ja[i]++;
    }
}
/*
-------------------------------------------------------------------
|   PERMUTE_ROWS
|   Permute the rows to get rid of pesky zero diagonal elements
|   so that partial pivoting won't be necessary and diagonal
|   damping will be kept at a minimum. Uses the vector "perm"
|   to determine which rows to switch.
|
-------------------------------------------------------------------
*/
permute_rows(perm, edge_list, ja, num_nodes, val_int)
int *perm;
struct edge_s **edge_list;
int *ja;
int num_nodes;
Val_Int *val_int;
{
    struct edge_s *e, *ep, *ep2;
    int i,j;
    int cnt;
    int none;

				/* check to see if we have any permuting*/
				/* to do */
    none = TRUE;
    for (i = 0 ; i < num_nodes; i++) 
	if (perm[i] != i ) 
           none = FALSE;
    if (none) {
        val_int->from = (int *)NULL;
        val_int->to = (int *)NULL;
        val_int->permute_cnt = 0;
	return;
    }
				/* Temporarly add lower diagonal piece */
				/* to the edge list */
				/* Add the diagonal first */
    for (i = 0 ; i < num_nodes; i++) {
	e = (struct edge_s *) sim_alloc(sizeof(struct edge_s), S_CAZM);
	e->e_node = i;
	ep = edge_list[i]; 
	edge_list[i] = e;
	e->e_next = ep;
    }
				/* add the lower triangle */
    for (i = num_nodes-1 ; i >= 0; i--) {
	for (ep2 = edge_list[i]->e_next; ep2 != NULL; ep2 = ep2->e_next) {
	    e = (struct edge_s *) sim_alloc(sizeof(struct edge_s), S_CAZM);
	    j = ep2->e_node;
	    e->e_node = i;
	    ep = edge_list[j]; 
	    edge_list[j] = e;
	    e->e_next = ep;
	}
    }

    cnt = 0;
    for (i = 0 ; i < num_nodes; i++) 
	if (perm[i] != i ) {		/* permute row i with perm[i] */
	    for (e = edge_list[i]; e != NULL ; e = e->e_next) {
		add_col(edge_list, e->e_node, perm[i], ja);
		add_col(edge_list, perm[i], e->e_node, ja);
	    }
	    for (e = edge_list[perm[i]]; e != NULL ; e = e->e_next) {
		add_col(edge_list, e->e_node, i, ja);
		add_col(edge_list, i, e->e_node, ja);
	    }
	}
    for (i = 0 ; i < num_nodes; i++) 
	if (perm[i] != i ) {		/* count the number we need to move*/
	    for (e = edge_list[i]; e != NULL ; e = e->e_next) 
		cnt++;
	}

    val_int->from = (int *) sim_calloc(sizeof(int), cnt, S_CAZM);
    val_int->to = (int *) sim_calloc(sizeof(int), cnt, S_CAZM);
    val_int->permute_cnt = cnt;
}
/*
-------------------------------------------------------------------
|   ADD_COL
|   add an entry to edge list. must keep symetric 
|
-------------------------------------------------------------------
*/
add_col(edge_list,  col, row, ja)
struct edge_s **edge_list;
int col, row;
int *ja;
{
	struct edge_s *e, *ep, *ep2;
	int temp;

	ep = ep2 = edge_list[row]; 
	while (ep != NULL) {
	    if (ep->e_node == col)
		return;
	    else
	    if (ep->e_node > col)
		ep = NULL;
	    else {
		ep2 = ep;
		ep = ep->e_next;
	     }
	}

	e = (struct edge_s *) sim_alloc(sizeof(struct edge_s), S_CAZM);
	e->e_node = col;
	e->e_next = ep2->e_next;
	ep2->e_next = e;
					/* swap */
	if (e->e_node < ep2->e_node) {
	       temp = e->e_node;
	       e->e_node = ep2->e_node;
	       ep2->e_node = temp;
	}
		/* keep track of count */
		/* in upper triangle */
	if (row < col)
	    ja[row]++;
}
/*
-------------------------------------------------------------------
|   SET_TO_FROM
|   Make the map for permuting the rows
|
-------------------------------------------------------------------
*/
set_to_from(edge_list, ja, val_int, perm)
struct edge_s **edge_list;
int *ja;
Val_Int *val_int;
int *perm;
{
	int *from, *to;
	int i;
	int cnt;
	int cnt2;
	int jacobian_loc();
	struct edge_s *e;

	if (val_int->permute_cnt == 0)
	    return;
	from = val_int->from;
	to = val_int->to;

	cnt = 0;
	cnt2 = 0;
    	for (i = 0 ; i < val_int->jasize; i++) 
	    if (perm[i] != i ) {	/* permute row i with perm[i] */
	        for (e = edge_list[i]; e != NULL ; e = e->e_next) {
		    from[cnt] = jacobian_loc(ja,val_int->jasize,i,e->e_node);
		    to[cnt] = jacobian_loc(ja,val_int->jasize,perm[i],e->e_node);
		    cnt++;
		}
		cnt2++;
	    }
	val_int->num_rows_permute = cnt2;
	val_int->rows_permute = (int *) sim_calloc(2*cnt2, sizeof(int), S_CAZM);
	cnt = 0;
    	for (i = 0 ; i < val_int->jasize; i++) 
	    if (perm[i] != i ) {	/* permute row i with perm[i] */
		val_int->rows_permute[cnt] = i;
		cnt++;
		val_int->rows_permute[cnt] = perm[i];
		cnt++;
	    }
}
/*
-------------------------------------------------------------------
|   JACOBIAN_LOC
|   Returns the index into the Jacobian for a row, and col
|
-------------------------------------------------------------------
*/
int
jacobian_loc(ja, num_ind,row,col)
int *ja;
int num_ind;
int row, col;
{
	int i,j,k,h;
	int *jak;

	h = ja[num_ind]-ja[0];
	if (row == col) {
	    return(row);
	} else
	if (row < col) {
	    for (k = ja[row] - 1, jak = &ja[k];*jak != col + 1; 
		k++, jak++);
	    return(k);
	} else {
	    for (k = ja[col] - 1, jak = &ja[k];*jak != row + 1; 
		k++, jak++);
	    return(k+h);
	}
}

static struct rc_modellist_s *rc_models_only=NULL;

rc_list( modellist )
struct modellist_s *modellist;
{
	struct rc_modellist_s *rc;

	if( rc_models_only == NULL ) {
	    rc_models_only = (struct rc_modellist_s *) sim_alloc(
		sizeof(struct rc_modellist_s), S_CAZM);
	    rc_models_only->rc_model=modellist;
	    rc_models_only->rc_next=NULL;
	} else {
	    rc=rc_models_only;

	    while( rc->rc_next != NULL ) rc=rc->rc_next;

	    rc->rc_next = (struct rc_modellist_s *) sim_alloc(
	               sizeof(struct rc_modellist_s), S_CAZM);
	    rc = rc->rc_next;
	    rc->rc_model=modellist;
	    rc->rc_next=NULL;
	}
}

struct sp_rc_resmodel_s *
get_rcmodel( modelname )
char *modelname;
{
	struct rc_modellist_s *rc;

	rc=rc_models_only;
	while( rc != NULL ) {
	   if( strcmp(rc->rc_model->m_name ,modelname) == 0 )
		return( (struct sp_rc_resmodel_s *) rc->rc_model->m_param  );
	   else
		rc = rc->rc_next;
	} 
	return( (struct sp_rc_resmodel_s *) NULL  );
}

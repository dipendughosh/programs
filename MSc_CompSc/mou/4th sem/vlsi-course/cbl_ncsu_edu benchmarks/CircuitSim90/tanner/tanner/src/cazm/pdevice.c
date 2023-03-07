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
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>
#include "Hmain.h"
#include "sim.h"
#include "sp.h"
#include "mod.h"

/*
-------------------------------------------------------------
|   MOSFET_PARSE
|   Front end set up for the MOSFET transistor, returns new node_num
|
-------------------------------------------------------------
*/
int
mosfet_parse(gp, fsp, c_head, modellist, sub_level, hash_tab, node_num)
Param *gp;
struct sp_mosfet_s *fsp;
struct circuit_s **c_head;
struct modellist_s *modellist;
struct sub_level_s *sub_level;  /* pointer to current level */
struct hash_table_s **hash_tab;
int node_num;
{
        struct circuit_s *cptr;

	double area;
	double perim;
	int i;

	/* Take care of defaults for source/drain areas and perims */

	if (fsp->length == ZEROSET) fsp->length = 1.0e-4;
	if (fsp->width  == ZEROSET) fsp->width  = 1.0e-4;

	if (gp->p_moscap == TRUE) {

	    area  = fsp->length * fsp->width;
	    perim = 2 * (fsp->length + fsp->width);

	} else {

	    area  = 0.0;
	    perim = 0.0;
	}

	if (fsp->sarea  == ZEROSET) fsp->sarea = area;
	if (fsp->darea  == ZEROSET) fsp->darea = area;
	if (fsp->sperim == ZEROSET) fsp->sperim = perim;
	if (fsp->dperim == ZEROSET) fsp->dperim = perim;

	if (fsp->sarea == 0.0 && fsp->sperim != 0.0) {
	    sim_error(S_WARNING, S_CAZM, 
		"Mosfet area-perimeter error on device \"%s\"", fsp->name);
	    fsp->sarea = 0.0;
	}
	if (fsp->darea == 0.0 && fsp->dperim != 0.0) {
	    sim_error(S_WARNING, S_CAZM, 
		"Mosfet area-perimeter error on device \"%s\"", fsp->name);
	    fsp->darea = 0.0;
	}

					/* allocate circuit entry */
	cptr = (struct circuit_s *) 
			     sim_alloc(sizeof(struct circuit_s), S_CAZM);

				/* initialize the c_fq[6] array */
	for(i=0; i<6; i++)
	    cptr->c_fq[i] = 0.0;

	cptr->c_params = (struct anl_model_s *) 
			     sim_alloc(sizeof(struct anl_model_s), S_CAZM);
	cptr->c_params->device = (struct generic_s *)fsp;
	cptr->c_params->sp_device = (struct generic_s *)fsp;
	cptr->c_params->pre_comp = NULL;
	cptr->c_name = (char *) sim_str_alloc(strlen(fsp->name), S_CAZM);
	strcpy(cptr->c_name,fsp->name);
	cptr->c_type = MOSFET;
	cptr->c_numnodes = 4;

				/* add nodes to hash table and get */
				/* an unique node number */
	cptr->c_nodes[DRAIN] = hash_nodes(fsp->dnode, &node_num,
					hash_tab, &sub_level->s_node_names);
	cptr->c_nodes[SOURCE] = hash_nodes(fsp->snode, &node_num,
					hash_tab, &sub_level->s_node_names);
	cptr->c_nodes[GATE] = hash_nodes(fsp->gnode, &node_num,
					hash_tab, &sub_level->s_node_names);
	cptr->c_nodes[BULK] = hash_nodes(fsp->bnode, &node_num,
					hash_tab, &sub_level->s_node_names);


					/* check to see if we loaded table */
	hash_device(gp, fsp->modelname, (struct sp_mosfet_s *)fsp,
		modellist, cptr, MOSFET);

					
					/* link to list */
	cptr->c_next = *c_head;
	*c_head = cptr;

	return(node_num);
}
/*
-------------------------------------------------------------
|   BIPOLAR_PARSE
|   Front end set up for the bipolar transistor, returns new node_num
|
-------------------------------------------------------------
*/
int
bipolar_parse(gp, fsp, c_head, modellist, sub_level, hash_tab, node_num, type)
Param *gp;
struct sp_bipolar_s *fsp;
struct circuit_s **c_head;
struct modellist_s *modellist;
struct sub_level_s *sub_level;	/* pointer to current level */
struct hash_table_s **hash_tab;
int node_num;
int type;
{
	struct circuit_s *cptr;
	int i;
					/* allocate circuit entry */
	cptr = (struct circuit_s *) 
			     sim_alloc(sizeof(struct circuit_s), S_CAZM);

				/* initialize the c_fq[6] array */
	for(i=0; i<6; i++)
	    cptr->c_fq[i] = 0.0;
					/* save device parameters */
	cptr->c_params = (struct anl_model_s *) 
			     sim_alloc(sizeof(struct anl_model_s), S_CAZM);
	cptr->c_params->sp_device = (struct generic_s *)fsp;
	cptr->c_name = (char *) sim_str_alloc(strlen(fsp->name), S_CAZM);
	strcpy(cptr->c_name,fsp->name);
	cptr->c_type = type;
	cptr->c_numnodes = 3; /* 3 because we ignore the bulk for device
			       * calculations; (for assembly purposes) 
			       */

	/* Set the SUBSTRATE node of a three terminal BJT to Global Ground */
	if(cptr->c_type == DISCRETE_BIPOLAR) {
	    fsp->snode = (char *) sim_str_alloc(strlen(GLOBAL_GND), S_CAZM);
	    strcpy(fsp->snode, GLOBAL_GND);
	}
		
	/* hash bjt's subtrate node */
	cptr->c_nodes[BULK] = hash_nodes(fsp->snode, &node_num,
					hash_tab, &(sub_level->s_node_names));
	cptr->c_nodes[COLLECTOR] = hash_nodes(fsp->cnode, &node_num,
					hash_tab, &(sub_level->s_node_names));

	cptr->c_nodes[EMITTER] = hash_nodes(fsp->enode, &node_num,
					hash_tab, &(sub_level->s_node_names));
	cptr->c_nodes[BASE] = hash_nodes(fsp->bnode, &node_num,
					hash_tab, &(sub_level->s_node_names));

					/* check for zero areas, perimeters*/
	if (fsp->areafactor == ZEROSET)
	    fsp->areafactor = DEFAULT_AREAFACTOR;

					/* check to see if we loaded table */
	hash_device(gp, fsp->modelname, (struct sp_mosfet_s *) fsp, modellist, 
		cptr, BIPOLAR);


					/* link to list */
	cptr->c_next = *c_head;
	*c_head = cptr;

	return(node_num);
}

/*
-------------------------------------------------------------
|   JFET_PARSE
|   Front end set up for the jfet transistor, returns new node_num
|
-------------------------------------------------------------
*/
int
jfet_parse(gp, fsp, c_head, modellist, sub_level, hash_tab, node_num)
Param *gp;
struct sp_jfet_s *fsp;
struct circuit_s **c_head;
struct modellist_s *modellist;
struct sub_level_s *sub_level;	/* pointer to current level */
struct hash_table_s **hash_tab;
int node_num;
{
	struct circuit_s *cptr;
	int i;
					/* allocate circuit entry */
	cptr = (struct circuit_s *) 
			     sim_alloc(sizeof(struct circuit_s), S_CAZM);

				/* initialize the c_fq[6] array */
	for(i=0; i<6; i++)
	    cptr->c_fq[i] = 0.0;
					/* save device parameters */
	cptr->c_params = (struct anl_model_s *) 
			     sim_alloc(sizeof(struct anl_model_s), S_CAZM);
	cptr->c_params->sp_device = (struct generic_s *)fsp;
	cptr->c_name = (char *) sim_str_alloc(strlen(fsp->name), S_CAZM);
	strcpy(cptr->c_name,fsp->name);
	cptr->c_type = JFET;
	cptr->c_numnodes = 3;

	cptr->c_nodes[GATE] = hash_nodes(fsp->gnode, &node_num,
					hash_tab, &(sub_level->s_node_names));
	cptr->c_nodes[DRAIN] = hash_nodes(fsp->dnode, &node_num,
					hash_tab, &(sub_level->s_node_names));
	cptr->c_nodes[SOURCE] = hash_nodes(fsp->snode, &node_num,
					hash_tab, &(sub_level->s_node_names));

					/* check for zero areas, perimeters*/
	if (fsp->areafactor == ZEROSET)
	    fsp->areafactor = DEFAULT_AREAFACTOR;

					/* check to see if we loaded table */
	hash_device(gp, fsp->modelname, (struct sp_mosfet_s *)fsp, modellist, 
		cptr, JFET);


					/* link to list */
	cptr->c_next = *c_head;
	*c_head = cptr;

	return(node_num);
}

/*
-------------------------------------------------------------
|   MESFET_PARSE
|   Front end set up for the mesfet transistor, returns new node_num
|
-------------------------------------------------------------
*/
int
mesfet_parse(gp, fsp, c_head, modellist, sub_level, hash_tab, node_num, type)
Param *gp;
struct sp_mesfet_s *fsp;
struct circuit_s **c_head;
struct modellist_s *modellist;
struct sub_level_s *sub_level;	/* pointer to current level */
struct hash_table_s **hash_tab;
int node_num;
int type;
{
	struct circuit_s *cptr;
	int i;
					/* allocate circuit entry */
	cptr = (struct circuit_s *) 
			     sim_alloc(sizeof(struct circuit_s), S_CAZM);

				/* initialize the c_fq[6] array */
	for(i=0; i<6; i++)
	    cptr->c_fq[i] = 0.0;
					/* save device parameters */
	cptr->c_params = (struct anl_model_s *) 
			     sim_alloc(sizeof(struct anl_model_s), S_CAZM);
	cptr->c_params->sp_device = (struct generic_s *)fsp;
	cptr->c_name = (char *) sim_str_alloc(strlen(fsp->name), S_CAZM);
	strcpy(cptr->c_name,fsp->name);
	cptr->c_type = type;
	cptr->c_numnodes = 4; 

	/* Set the BULK node of a three terminal MESFET to Global Ground */
	if(cptr->c_type == DISCRETE_MESFET) {
	    fsp->bnode = (char *) sim_str_alloc(strlen(GLOBAL_GND), S_CAZM);
	    strcpy(fsp->bnode, GLOBAL_GND);
	}
		

	cptr->c_nodes[BULK] = hash_nodes(fsp->bnode, &node_num,
					hash_tab, &(sub_level->s_node_names));
	cptr->c_nodes[GATE] = hash_nodes(fsp->gnode, &node_num,
					hash_tab, &(sub_level->s_node_names));
	cptr->c_nodes[DRAIN] = hash_nodes(fsp->dnode, &node_num,
					hash_tab, &(sub_level->s_node_names));
	cptr->c_nodes[SOURCE] = hash_nodes(fsp->snode, &node_num,
					hash_tab, &(sub_level->s_node_names));

					/* check to see if we loaded table */
	hash_device(gp, fsp->modelname, (struct sp_mosfet_s *)fsp, modellist, 
		cptr, MESFET);

					/* link to list */
	cptr->c_next = *c_head;
	*c_head = cptr;

	return(node_num);
}

diode_parse(gp, fsp, c_head, modellist, sub_level, hash_tab, err_cnt, node_num)
Param *gp;
struct sp_diode_s *fsp;
struct circuit_s **c_head;
struct modellist_s *modellist;
struct sub_level_s *sub_level;  /* pointer to current level */
struct hash_table_s **hash_tab;
int *err_cnt;
int node_num;
{
	struct circuit_s *cptr;
	int i;

	cptr = (struct circuit_s *) 
		 sim_alloc(sizeof(struct circuit_s), S_CAZM);

			    /* initialize the c_fq[6] array */
	for(i=0; i<6; i++)
	    cptr->c_fq[i] = 0.0;

	/* Device info structure */
	cptr->c_params = (struct anl_model_s *)
		 sim_alloc(sizeof(struct anl_model_s), S_CAZM);

	cptr->c_params->sp_device = (struct generic_s *) fsp;
	cptr->c_name = (char *) sim_str_alloc(strlen(fsp->name), S_CAZM);
	strcpy(cptr->c_name,fsp->name);
	cptr->c_type = DIODE;
	cptr->c_numnodes = 2;

			    /* add nodes to hash table and get */
			    /* an unique node number */
	cptr->c_nodes[DNODE1] = hash_nodes(fsp->dioposnode,
	    &node_num, hash_tab, &sub_level->s_node_names);
	cptr->c_nodes[DNODE2] = hash_nodes(fsp->dionegnode,
	    &node_num, hash_tab, &sub_level->s_node_names);

			    /* check for zero areas, perimeters*/
	if (fsp->dioarea == ZEROSET)
	    fsp->dioarea = 1.0;
	if (fsp->dioperim == ZEROSET)
	    fsp->dioperim = 1.0;
			    /* check to see if we loaded table */
	hash_device(gp, fsp->modelname, (struct sp_mosfet_s *)fsp,
	    modellist, cptr, DIODE);


			    /* link to list */
	cptr->c_next = *c_head;
	*c_head = cptr;


	return(node_num);	

}


resistor_parse(fsp, c_head, sub_level, hash_tab, err_cnt, node_num, type)
struct sp_resistor_s *fsp;
struct circuit_s **c_head;
struct sub_level_s *sub_level;  /* pointer to current level */
struct hash_table_s **hash_tab;
int *err_cnt;
int node_num;
int type;
{
	struct circuit_s *cptr;
	int i;

	if (fsp->resvalue > 0)  {
	    cptr = (struct circuit_s *) 
		    sim_alloc(sizeof(struct circuit_s), S_CAZM);

		    /* initialize the c_fq[6] array */
	    for(i=0; i<6; i++)
		cptr->c_fq[i] = 0.0;

	    if (fsp->tc1 == ZEROSET) fsp->tc1 = 0.0;
	    if (fsp->tc2 == ZEROSET) fsp->tc2 = 0.0;

	    /* Device info structure */
	    cptr->c_params = (struct anl_model_s *)
		 sim_alloc(sizeof(struct anl_model_s), S_CAZM);

	    cptr->c_params->sp_device = (struct generic_s *) fsp;
	    cptr->c_name = (char *) sim_str_alloc(strlen(fsp->resname), S_CAZM);
	    cptr->c_type = type;

	    strcpy(cptr->c_name,fsp->resname);

	    if ( cptr->c_type == RESISTOR ) {

	       cptr->c_type = TEMP_RESISTOR;
	       cptr->c_val = 1.0 / fsp->resvalue;

	    } else if ( cptr->c_type == RC_RESISTOR ) {

	       cptr->c_type = RC_RESISTOR;
	       if ( fsp->scale == ZEROSET ) fsp->scale = 1.0;
	       if ( fsp->multiplier == ZEROSET ) fsp->multiplier = 1.0;
	       if ( fsp->dtemp == ZEROSET ) fsp->dtemp = 0.0;
	    }

	    cptr->c_numnodes = 2;

		    /* add nodes to hash table and get unique */
		    /* node number */
	    cptr->c_nodes[0] = hash_nodes(fsp->resnode1,&node_num,
			    hash_tab, &sub_level->s_node_names);
	    cptr->c_nodes[1] = hash_nodes(fsp->resnode2,&node_num,
			    hash_tab, &sub_level->s_node_names);

		    /* append to end of circuit list */
	    cptr->c_next = *c_head;
	    *c_head = cptr;

	} else {
	    sim_error(S_FATAL, S_CAZM, 
		    "Illegal resistance %f :line %d",
			    fsp->resvalue, sp_gb->lineno);
	    *err_cnt++;
	}

	return(node_num);

}

capacitor_parse(fsp, c_head, sub_level, hash_tab, err_cnt, node_num)
struct sp_capacitor_s *fsp;
struct circuit_s **c_head;
struct sub_level_s *sub_level;  /* pointer to current level */
struct hash_table_s **hash_tab;
int *err_cnt;
int node_num;
{
	struct circuit_s *cptr;
	int i;

			    /* initialize circuit entry for cap */
	cptr = (struct circuit_s *) 
		sim_alloc(sizeof(struct circuit_s), S_CAZM);

		/* initialize the c_fq[6] array */
	for(i=0; i<6; i++)
	    cptr->c_fq[i] = 0.0;

	cptr->c_params = NULL;
	cptr->c_name = (char *) sim_str_alloc(strlen(fsp->capname), S_CAZM);
	strcpy(cptr->c_name,fsp->capname);
	cptr->c_type = CAPACITOR;
	cptr->c_val = fsp->capvalue;
	cptr->c_numnodes = 2;

		    /* add nodes to hash table and get unique */
		    /* node number */
	cptr->c_nodes[0] = hash_nodes(fsp->capnode1, &node_num,
			    hash_tab, &sub_level->s_node_names);
	cptr->c_nodes[1] = hash_nodes(fsp->capnode2, &node_num,
			    hash_tab, &sub_level->s_node_names);

		    /* add capacitor to circuit list */
	cptr->c_next = *c_head;
	*c_head = cptr;

	if (fsp->capvalue <= 0) {
	    sim_error(S_FATAL, S_CAZM, 
		    "Illegal capacitance %f :line %d",
			    fsp->capvalue, sp_gb->lineno);
	    *err_cnt++;
	}

	return(node_num);
}


inductor_parse(fsp, c_head, sub_level, hash_tab, err_cnt, node_num)
struct sp_inductor_s *fsp;
struct circuit_s **c_head;
struct sub_level_s *sub_level;  /* pointer to current level */
struct hash_table_s **hash_tab;
int *err_cnt;
int node_num;
{
	struct circuit_s *cptr;
	struct circuit_s *cptr1;
	struct circuit_s *cptr2;
	struct inductor_s *lptr; 
	struct hash_table_s *hash_p;	/* temporary ptr */
	struct hash_table_s *find_name();	
	struct hash_table_s *hash_ind();
	double *indval;
	char *name;
	int global_gnd;
	int cap_node;
	int i;


		    /* Check for a unique inductor name */
	hash_p = find_name(fsp->indname, INDUCTOR, sub_hash);
	if (hash_p != NULL ) {
	    sim_error(S_WARNING, S_CAZM, 
		"Two inductors with the same name \"%s\". :line %d",
			 fsp->indname, sp_gb->lineno);
	}
		    /* Create a model for the inductor.
		     * Add a capacitor and two voltage 
		     * controlled  current sources.
		     */
	cptr = (struct circuit_s *) 
		sim_alloc(sizeof(struct circuit_s), S_CAZM);
	cptr->c_params = NULL;
	cptr->c_name = NULL;
	cptr->c_type = CAPACITOR;
	cptr->c_val = fsp->indvalue;
	cptr->c_numnodes = 2;

		    /* First character of the capacitor node
		     * name is a space. The space is used for
		     * reckonizing an internal node.
		     */
	name = (char *)
		sim_alloc(strlen(fsp->indnode1)+12+1, S_CAZM);
	sprintf(name," %s_%d",fsp->indnode1, node_num);

	cap_node = hash_nodes(name, &node_num,
			    hash_tab, &sub_level->s_node_names);

	global_gnd = hash_nodes(GLOBAL_GND, &node_num, hash_tab,
			     &sub_level->s_node_names);
		    /* attach the capacitor to GLOBAL_GND */
	cptr->c_nodes[0] = cap_node;
	cptr->c_nodes[1] = global_gnd;
	cptr->c_next = *c_head;
	*c_head = cptr;

	cptr1 = (struct circuit_s *) 
		sim_alloc(sizeof(struct circuit_s), S_CAZM);
	cptr1->c_name = (char *) sim_str_alloc(strlen(fsp->indname), S_CAZM);
	strcpy(cptr1->c_name,fsp->indname);
	cptr1->c_params = NULL;
	indval = (double *) sim_alloc(sizeof(double), S_CAZM);
	*indval = fsp->indvalue;
	cptr1->c_modelF = (struct sim_model_s *) indval;
	cptr1->c_type = IND_VOLT_CURR;
	cptr1->c_val = -1;
	cptr1->c_numnodes = 4;
	cptr1->c_nodes[0] = hash_nodes(fsp->indnode1, &node_num,
			    hash_tab, &sub_level->s_node_names);
	cptr1->c_nodes[1] = hash_nodes(fsp->indnode2, &node_num,
			    hash_tab, &sub_level->s_node_names);
	cptr1->c_nodes[2] = cap_node;
	cptr1->c_nodes[3] = global_gnd;
	cptr1->c_next = *c_head;
	*c_head = cptr1;

	cptr2 = (struct circuit_s *) 
		sim_alloc(sizeof(struct circuit_s), S_CAZM);
	cptr2->c_params = NULL;
	cptr2->c_name = NULL;
	cptr2->c_type = VOLT_CURR;
	cptr2->c_val = 1;
	cptr2->c_numnodes = 4;
	cptr2->c_nodes[0] = cap_node;
	cptr2->c_nodes[1] = global_gnd;
	cptr2->c_nodes[2] = hash_nodes(fsp->indnode1, &node_num,
			    hash_tab, &sub_level->s_node_names);
	cptr2->c_nodes[3] = hash_nodes(fsp->indnode2, &node_num,
			    hash_tab, &sub_level->s_node_names);
	
		    /* add inductor to circuit list */
	cptr2->c_next = *c_head;
	*c_head = cptr2;

		    /* add inductor model name, current sources
		     * and inductor value to hash table for
		     * mutual inductor access.
		     */
	lptr = (struct inductor_s *) 
		sim_alloc(sizeof(struct inductor_s), S_CAZM);
	lptr->cap = cptr;
	lptr->indval = fsp->indvalue;
	    /* include this new inductor */
	(void) hash_ind(fsp->indname, lptr);

	return(node_num);
}


transmission_parse(gp, fsp, c_head, sub_level, hash_tab, err_cnt, node_num)
Param *gp;
struct sp_transmission_s *fsp;
struct circuit_s **c_head;
struct sub_level_s *sub_level;  /* pointer to current level */
struct hash_table_s **hash_tab;
int *err_cnt;
int node_num;
{
	struct circuit_s *cptr;
	double *delay;
	struct vqueue_s *vqueue;

			    /* initialize circuit entry for tline */
	cptr = (struct circuit_s *) 
		sim_alloc(sizeof(struct circuit_s), S_CAZM);
	cptr->c_name = (char *) sim_str_alloc(strlen(fsp->transname), S_CAZM);
	strcpy(cptr->c_name,fsp->transname);

	cptr->c_type = TRANSMISSION;
	cptr->c_val = fsp->imped;

	/* use Q space for delay */
	delay = (double *) sim_alloc((sizeof(double)), S_CAZM);

	if (fsp->delay == ZEROSET) {
	    if (fsp->nlength == ZEROSET)
		fsp->nlength=0.25;
	    if (fsp->freq == ZEROSET)
		fsp->freq=1.0e9;
	    *delay = fsp->nlength / fsp->freq;
	}
	else
	    *delay = fsp->delay;

		    /* restrict time step */
	if (gp->p_transmission_step == 0.0)
	    gp->p_transmission_step = 0.50 * *delay;
	else
	if (gp->p_transmission_step > 0.50 * *delay)
	    gp->p_transmission_step = 0.50 * *delay;

	cptr->c_modelQ = (struct sim_model_s *) delay;

	/* use F space for voltage queue */
	vqueue = (struct vqueue_s *) 
		    sim_alloc((sizeof(struct vqueue_s)), S_CAZM);
	cptr->c_modelF = (struct sim_model_s *) vqueue;

	/* initalize voltage queue to zero at both ends */
	queue_init(vqueue);
	queue_update(vqueue, -(*delay),0.0,0.0,*delay);
	queue_update(vqueue, 0.0,0.0,0.0,*delay);

	cptr->c_numnodes = 4;

		    /* add nodes to hash table and get unique */
		    /* node number */
	cptr->c_nodes[0] = hash_nodes(fsp->tnode1, &node_num,
			    hash_tab, &sub_level->s_node_names);
	cptr->c_nodes[1] = hash_nodes(fsp->tnode2, &node_num,
			    hash_tab, &sub_level->s_node_names);
	cptr->c_nodes[2] = hash_nodes(fsp->tnode3, &node_num,
			    hash_tab, &sub_level->s_node_names);
	cptr->c_nodes[3] = hash_nodes(fsp->tnode4, &node_num,
			    hash_tab, &sub_level->s_node_names);

		    /* add transmission line to circuit list */
	cptr->c_next = *c_head;
	*c_head = cptr;

			    /* check value */
	if (fsp->delay <= 0) {
	    sim_error(S_FATAL, S_CAZM, 
		    "Illegal time delay %f",fsp->delay);
	    err_cnt++;
	}

	return(node_num);
}


bsim_resistor_parse(gp, fsp, c_head, modellist, sub_level, hash_tab, err_cnt, node_num)
Param *gp;
struct sp_bsim_resistor_s *fsp;
struct circuit_s **c_head;
struct modellist_s *modellist;
struct sub_level_s *sub_level;  /* pointer to current level */
struct hash_table_s **hash_tab;
int *err_cnt;
int node_num;
{
	struct circuit_s *cptr;
	int i;

	if (fsp->length > 0.0) {

	    cptr = (struct circuit_s *) 
		    sim_alloc(sizeof(struct circuit_s), S_CAZM);

		    /* initialize the c_fq[6] array */
	    for(i=0; i<6; i++)
		cptr->c_fq[i] = 0.0;

	    if (fsp->tc1 == ZEROSET) fsp->tc1 = 0.0;
	    if (fsp->tc2 == ZEROSET) fsp->tc2 = 0.0;

	    /* Device info structure */
	    cptr->c_params = (struct anl_model_s *)
		 sim_alloc(sizeof(struct anl_model_s), S_CAZM);

	    cptr->c_params->sp_device = (struct generic_s *) fsp;
	    cptr->c_name = (char *) sim_str_alloc(strlen(fsp->resname), S_CAZM);
	    strcpy(cptr->c_name,fsp->resname);
	    cptr->c_type = BSIM_RESISTOR;
	    cptr->c_numnodes = 2;

			    /* add nodes to hash table and get */
			    /* an unique node number */
	    cptr->c_nodes[0] = hash_nodes(fsp->resnode1, &node_num,
			    hash_tab, &sub_level->s_node_names);
	    cptr->c_nodes[1] = hash_nodes(fsp->resnode2, &node_num,
			    hash_tab, &sub_level->s_node_names);

			    /* check to see if we loaded model */
	    hash_device(gp, fsp->modelname, (struct sp_mosfet_s *)fsp,
		modellist, cptr, BSIM_RESISTOR);


			    /* link to list */
	    cptr->c_next = *c_head;
	    *c_head = cptr;

	} else {
	    sim_error(S_FATAL, S_CAZM, 
		    "Illegal BSIM resistor: length =%f :line %d",
			    fsp->length, sp_gb->lineno);
	    err_cnt++;
	}

	return(node_num);
}
    

bsim_capacitor_parse(gp, fsp, c_head, modellist, sub_level, hash_tab, err_cnt, node_num)
Param *gp;
struct sp_bsim_capacitor_s *fsp;
struct circuit_s **c_head;
struct modellist_s *modellist;
struct sub_level_s *sub_level;  /* pointer to current level */
struct hash_table_s **hash_tab;
int *err_cnt;
int node_num;
{
	struct circuit_s *cptr;
	int i;

	cptr = (struct circuit_s *) 
		 sim_alloc(sizeof(struct circuit_s), S_CAZM);

		/* initialize the c_fq[6] array */
	for(i=0; i<6; i++)
	    cptr->c_fq[i] = 0.0;

	/* Device info structure */
	cptr->c_params = (struct anl_model_s *)
		 sim_alloc(sizeof(struct anl_model_s), S_CAZM);

	cptr->c_params->sp_device = (struct generic_s *) fsp;

	cptr->c_name = (char *) sim_str_alloc(strlen(fsp->capname), S_CAZM);
	strcpy(cptr->c_name,fsp->capname);
	cptr->c_type = BSIM_CAPACITOR;
	cptr->c_numnodes = 2;

			    /* add nodes to hash table and get */
			    /* an unique node number */
	cptr->c_nodes[0] = hash_nodes(fsp->capnode1, &node_num,
			    hash_tab, &sub_level->s_node_names);
	cptr->c_nodes[1] = hash_nodes(fsp->capnode2, &node_num,
			    hash_tab, &sub_level->s_node_names);

			    /* check to see if we loaded model */
	hash_device(gp, fsp->modelname, (struct sp_mosfet_s *)fsp, modellist,
	    cptr, BSIM_CAPACITOR);


			    /* link to list */
	cptr->c_next = *c_head;
	*c_head = cptr;

	return(node_num);
}


macro_parse(gp, fsp, c_head, modellist, sub_level, hash_tab, err_cnt, node_num)
Param *gp;
struct sp_macro_s *fsp;
struct circuit_s **c_head;
struct modellist_s *modellist;
struct sub_level_s *sub_level;  /* pointer to current level */
struct hash_table_s **hash_tab;
int *err_cnt;
int node_num;
{
	struct circuit_s *cptr;
	struct sp_pinlist_s *xp;
	int node_cnt;		/* count of nodes */
	int i;

	xp =fsp->pinlist;

			    /* allocate circuit entry */
	cptr = (struct circuit_s *) 
		 sim_alloc(sizeof(struct circuit_s), S_CAZM);
	cptr->c_params = NULL;

	cptr->c_name = (char *) sim_str_alloc(strlen(fsp->macname), S_CAZM);
	strcpy(cptr->c_name,fsp->macname);

	node_cnt = 0;
	for (xp; xp != NULL; xp=xp->next)
	{
			    /* add nodes to hash table and get */
	    cptr->c_nodes[node_cnt] = hash_nodes(xp->name, 
		    &node_num, hash_tab, &sub_level->s_node_names);
	    node_cnt++;
	}

	if (node_cnt == 2)
	    cptr->c_type = TWOTERM;
	else
	if (node_cnt == 3) 
	    cptr->c_type = THREETERM;
	else 
	if (node_cnt == 4) 
	    cptr->c_type = FOURTERM;
	else {
	    sim_error(S_FATAL, S_CAZM,
		"can't handle more than four terminal devices\n");
	    exit(1);
	}
	cptr->c_numnodes = node_cnt;
	hash_device(gp, fsp->mactech, (struct sp_mosfet_s *)NULL, modellist,
	    cptr, cptr->c_type);

			    /* link to list */
	cptr->c_next = *c_head;
	*c_head = cptr;

	return(node_num);

}

/*
-------------------------------------------------------------
|   MUTUAL_IND_CREATE
|   Create mutual inductor equivalant circuit
|
-------------------------------------------------------------
*/
mutual_ind_create(fsp, c_head, sub_level)
struct sp_minductor_s *fsp;
struct circuit_s **c_head;
struct sub_level_s *sub_level;  /* pointer to current level */
{
	struct hash_table_s *hash_t;
	struct inductor_s *lptr1, *lptr2;
	struct circuit_s *cptr;
	double m;		/* mutual inductor value */

				/* Check the coupling coeficient */
	if (fsp->couplevalue < 0.0 || fsp->couplevalue > 1.0) {
	    sim_error(S_FATAL, S_CAZM, 
		"Illegal Mutual inductance value %g :line %d",
			fsp->couplevalue, sp_gb->lineno);
	     exit(1);
	}

		    
	if ((hash_t = hash_ind(fsp->inductor1,
			(struct inductor_s *)NULL)) == NULL) {
	    sim_error(S_FATAL, S_CAZM, 
		"Unknown inductor for mutual inductor %s :line %d",
			 fsp->inductor1, sp_gb->lineno);
	    exit(1);
	}
	lptr1 = (struct inductor_s *) hash_t->h_info;

	if ((hash_t = hash_ind(fsp->inductor2,
			(struct inductor_s *)NULL)) == NULL) {
	    sim_error(S_FATAL, S_CAZM, 
		    "Unknown inductor for mutual inductor %s :line %d",
			 fsp->inductor1, sp_gb->lineno);
	    exit(1);
	}
	lptr2 = (struct inductor_s *) hash_t->h_info;

				/* Calculate M */
	m = fsp->couplevalue * sqrt(lptr1->indval * lptr2->indval);

			    /* add a capacitor between the two inductor
			     * models and add m to the model's capacitors.
			     */

	cptr = (struct circuit_s *) 
			    sim_alloc(sizeof(struct circuit_s), S_CAZM);
	cptr->c_params = NULL;
	cptr->c_type = CAPACITOR;
	cptr->c_val = -m;
	cptr->c_numnodes = 2;
	cptr->c_nodes[0] = lptr1->cap->c_nodes[0];
	cptr->c_nodes[1] = lptr2->cap->c_nodes[0];

		/* Add the mutual inductance */ 
	lptr1->cap->c_val += m;
	lptr2->cap->c_val += m;

	cptr->c_next = *c_head;
	*c_head = cptr;


}

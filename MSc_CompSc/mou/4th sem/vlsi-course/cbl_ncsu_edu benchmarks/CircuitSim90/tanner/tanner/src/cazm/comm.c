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

	This file contains the main subroutines used to parse the command
	file.

----------------------------------------------------------------------------*/
#include <math.h>
#include "Hmain.h"
#include "Hcmd.h"
#include "sim.h"
#include "sp.h"
#include "spcmd.h"
#include "mod.h"
#include "parse.h"
#include "bhash.h"

/*
-----------------------------------------------------------
|    COMMAND_PARSE
|    Reads in the command file and sets parameters 
|
------------------------------------------------------------
$Header: comm.c,v 1.8 87/10/30 16:08:50 erdman Locked $
$Log:	comm.c,v $
 * Revision 1.8  87/10/30  16:08:50  erdman
 * October release version
 * 
 * Revision 1.6  87/03/25  13:22:06  erdman
 * release version
 * 
 * Revision 1.5  86/09/08  14:33:40  erdman
 * Adding current sources
 * 
 * Revision 1.3  86/05/28  13:22:39  erdman
 * Adding new Spice parser
 * 
 * Revision 1.2  86/03/20  21:46:51  erdman
 * Adding the debug ability to output spice commands
 * 
*/

extern int cz_debug;

command_build(gp,pass)
Param *gp;
struct pass_s *pass;
{
	struct prim_s *p;
	struct boundary_s *b_ptr;	/* temporary pointer */
	struct boundary_s *b_tail;	/* Tail of the voltage boundary list */
	struct boundary_s *b_taili;	/* Tail of the current boundary list */
	struct boundary_s *b_headi;	/* Head of the current boundary list */
	struct volt_volt_s *v_ptr;
	struct volt_volt_s *v_tail;	/* Tail of Voltage-cntl-Voltage list */
	struct volt_volt_s *v_head;	/* Head of Voltage-cntl-Voltage list */
	struct vectlst_s {		/* holds the vector and bus descript */
	    struct vectlst_s *v_next;	/* ptr to next vector */
	    char *v_bus;		/* bus name */
	    struct name_s *v_names;	/* names of nodes on bus */
	    struct cmd_wave_bit_s *v_bits;	/* waveform description */	
	    int v_bitcnt;		/* bit count for funct creation */
	} ;
	struct vectlst_s *vectlst_h;	/* head of the vector list */
	struct vectlst_s *vectlst_t;	/* tail of the vector list */
	int error_cnt;			/* number of errors found */
	int num_nodes = gp->p_num_nodes;

	
			/* Voltage sources */
	for (b_ptr = gp->p_boundary; b_ptr->b_next != NULL; b_ptr =
			b_ptr->b_next);
	b_tail = b_ptr;

			/* Current sources */
	b_headi = (struct boundary_s *)
	    sim_alloc(sizeof(struct boundary_s), S_CAZM);
	b_taili = b_headi;
	b_taili->b_next = NULL;

			/* Voltage controlled Voltage sources */
	v_head = (struct volt_volt_s *)
	    sim_alloc(sizeof(struct volt_volt_s), S_CAZM);
	v_tail = v_head;
	v_tail->v_next = NULL;

		/* initialize vector list */
	vectlst_h = NULL;
	vectlst_t = NULL;

					/* number of errors = 0 */
	error_cnt = 0;
					/*-----------------------------*/
					/* Beginning of main parse loop*/
					/*-----------------------------*/


	/* Parse sources */
	if(pass->cmd_sources != NULL)
	for (p = pass->cmd_sources ;p != NULL; p = p->next) {

	    switch(p->sp->type) {

		case CMD_SIN:
		case CMD_SINI:
		    {
		    struct sp_sin_s *ptr;
		    struct other_wavef_s *o_ptr;
		    char *node;

					/* Recast it */
		    ptr = (struct sp_sin_s *)p->sp;
		    o_ptr = (struct other_wavef_s *)
			  sim_alloc(sizeof(struct other_wavef_s), S_CAZM);
		    o_ptr->o_type = p->sp->type;

				/* Allocate name  */
		    if(ptr->sinname != NULL) {
			o_ptr->o_name = (char *)
			    sim_str_alloc(strlen(ptr->sinname), S_CAZM);
			strcpy(o_ptr->o_name,ptr->sinname);
		    }
		    else
			o_ptr->o_name = NULL;

		    o_ptr->o_value = (double *)sim_alloc(sizeof(double) * 5,
					S_CAZM);

				/* hash the nodes */
		    node = (char *) 
			    sim_str_alloc(strlen(ptr->sinnode1), S_CAZM);
		    strcpy(node,ptr->sinnode1);
		    o_ptr->o_node1 = hash_nodes(node, &num_nodes,
			node_hash, &node_names);
		
		    if (ptr->sinnode2 != NULL) {
			node = (char *) 
				sim_str_alloc(strlen(ptr->sinnode2), S_CAZM);
			strcpy(node,ptr->sinnode2);
			o_ptr->o_node2 = hash_nodes(node, &num_nodes,
			    node_hash, &node_names);
		    }
		    else 
			o_ptr->o_node2 = GNDNUM;	/* default is ground */

		    o_ptr->o_value[0] = ptr->offset;
		    o_ptr->o_value[1] = ptr->amp;
		    o_ptr->o_value[2] = ptr->freq * 2.0 * PI;
		    o_ptr->o_value[3] = ptr->delay;
		    o_ptr->o_value[4] = ptr->damp;

		    if (gp->p_maxsinfreq < ptr->freq)
				gp->p_maxsinfreq = ptr->freq;


		    /* Link the voltage functions */
		    if(o_ptr->o_type == CMD_SIN) {
				/* Make sure the voltage source is not */
				/* connected to itself */
		        if (o_ptr->o_node2 == o_ptr->o_node1) {
			    sim_error(S_WARNING, S_CAZM,
			    "Voltage source line %d, connected to itself\n",
			    cmd_gb->lineno);
			    break;
		        }
			if (gp->p_other_v == NULL) {
			    o_ptr->o_next = NULL;
			    gp->p_other_v = o_ptr;
			} else {
			    o_ptr->o_next = gp->p_other_v;
			    gp->p_other_v = o_ptr;
			}
                                     		/* AC ANALYSIS */
			if (ptr->acmag != ZEROSET || ptr->acphase != ZEROSET){
			    add_acvolt(gp, o_ptr->o_node1, o_ptr->o_node2,
				o_ptr->o_name, ptr->acmag, ptr->acphase,
				(struct boundary_s *)NULL, o_ptr);
			}	
		    }
		    /* Link the current functions */
		    else {
			if (gp->p_other_i == NULL) {
			    o_ptr->o_next = NULL;
			    gp->p_other_i = o_ptr;
			} else {
			    o_ptr->o_next = gp->p_other_i;
			    gp->p_other_i = o_ptr;
			}
		    }
		    if (gp->p_debug_num == 0) 
			cmd_print((struct cmd_head_s *)p->sp);

		    }
		    break;
		case CMD_PWL :
		case CMD_PWLI :
				/* set up for piecewise linear funct */	
		    {
		    struct sp_pwl_s *ptr;
		    struct sp_point_s *pnt;
		    char *node;
		    double time;
		    int i;

							/* Recast it */
		    ptr = (struct sp_pwl_s *)p->sp;

					/* Check the time grid */
		    if (ptr->num_pts <= 1) {
		       sim_error(S_FATAL, S_CAZM, 
		       "Piecewise wave \"%s\" has insufficient time points.",
			    ptr->pwlnode1);
			error_cnt++;
			break;
		    }

		    time = -1;
		    for(pnt = ptr->pnts; pnt != NULL;
					    pnt = pnt->next) {
		       if(pnt->time <= time){
			   sim_error(S_FATAL, S_CAZM, 
			   "Piecewise wave \"%s\" has an incorrect time point.",
				ptr->pwlnode1);
			    error_cnt++;
			    break;
			}
			time = pnt->time;
		    }

		    b_ptr = (struct boundary_s *)
			sim_alloc(sizeof(struct boundary_s), S_CAZM);

				/* Allocate name  */
		    if(ptr->pwlname != NULL) {
			b_ptr->b_name = (char *)
			    sim_str_alloc(strlen(ptr->pwlname), S_CAZM);
			strcpy(b_ptr->b_name,ptr->pwlname);
		    }
		    else
			b_ptr->b_name = NULL;

				/* hash the nodes */
		    node = (char *) 
			    sim_str_alloc(strlen(ptr->pwlnode1), S_CAZM);
		    strcpy(node,ptr->pwlnode1);
		    b_ptr->b_node1 = hash_nodes(node, &num_nodes,
			node_hash, &node_names);
		
		    if (ptr->pwlnode2 != NULL) {
			node = (char *) 
				sim_str_alloc(strlen(ptr->pwlnode2), S_CAZM);
			strcpy(node,ptr->pwlnode2);
			b_ptr->b_node2 = hash_nodes(node, &num_nodes,
			    node_hash, &node_names);
		    }
		    else 
			b_ptr->b_node2 = GNDNUM;	/* default is ground */

		    b_ptr->b_length = ptr->num_pts;

			/* Piecewise has no delay */
		    b_ptr->b_delay = 0;

				/* allocate memory for piecewise funct */
		    b_ptr->b_value = (double *) 
					sim_alloc(sizeof(b_ptr->b_value[0])
		 	                * b_ptr->b_length, S_CAZM);
		    b_ptr->b_grid = (double *) 
					sim_alloc(sizeof(b_ptr->b_grid[0])
		 			* b_ptr->b_length, S_CAZM);

							/* copy values */
		    for(i=0, pnt = ptr->pnts; pnt != NULL;
					    pnt = pnt->next, i++) {
			b_ptr->b_grid[i] = pnt->time;
			b_ptr->b_value[i] = pnt->value;
		    }

				/* add to correct list */
		    if (p->sp->type == CMD_PWL) {
				/* Make sure the voltage source is not */
				/* connected to itself */
		        if (b_ptr->b_node2 == b_ptr->b_node1) {
			    sim_error(S_WARNING, S_CAZM,
			    "Voltage source line %d, connected to itself\n",
			    cmd_gb->lineno);
			    break;
		        }
		    	b_tail->b_next = b_ptr;
		    	b_tail = b_ptr;
		    } else {
		    	b_taili->b_next = b_ptr;
		    	b_taili = b_ptr;
		    }
		    if (gp->p_debug_num == 0) 
			cmd_print((struct cmd_head_s *)p->sp);
			
		    }
		    break;
		case CMD_BIT:
		case CMD_BITI:
		    {
		    struct cmd_wave_bit_s *ptr;
		    int bit_count;			/* number of bits */

							/* Recast it */
		    ptr = (struct cmd_wave_bit_s *)p->sp;

		    /* Set the defaults */
		    if(ptr->pw == ZEROSET)
			ptr->pw = PULSE_WIDTH;
		    if(ptr->rt == ZEROSET)
			ptr->rt = RISE_TIME;
		    if(ptr->ft == ZEROSET)
			ptr->ft = RISE_TIME;
		    if (ptr->lt == ZEROSET)
			ptr->lt = ptr->pw;
		    if (ptr->ht == ZEROSET)
			ptr->ht = ptr->pw;
		    if(ptr->on == ZEROSET && p->sp->type == CMD_BIT)
			ptr->on = VDD_DEFAULT;
							/* check values */
		    if (ptr->rt > ptr->pw) {
			sim_error(S_FATAL, S_CAZM, 
			    "rise time %e is greater than pulse width %e",
				ptr->rt, ptr->pw);
			error_cnt++;
		    }
		    if (ptr->ft > ptr->pw) {
			sim_error(S_FATAL, S_CAZM, 
			    "fall time %e is greater than pulse width %e",
				ptr->ft, ptr->pw);
			error_cnt++;
		    }
		    if (ptr->ft <= 0) {
			sim_error(S_WARNING, S_CAZM, 
			    "fall time %e is invalid, default value used ",
				ptr->ft);
			ptr->ft =RISE_TIME;
		    }
		    if (ptr->rt <= 0) {
			sim_error(S_WARNING, S_CAZM, 
			    "Rise time %e is invalid, default value used ",
				ptr->rt);
			ptr->rt =RISE_TIME;
		    }
		    if (ptr->pw <= 0) {
			sim_error(S_WARNING, S_CAZM, 
			    "Pulse width %e is invalid, default value used ",
				ptr->pw);
			ptr->pw =1.0e-8;
		    }
			
		    b_ptr = (struct boundary_s *)
		            sim_alloc(sizeof(struct boundary_s), S_CAZM);
				
				/* Allocate name  */
		    if(ptr->name != NULL) {
			b_ptr->b_name = (char *)
			    sim_str_alloc(strlen(ptr->name), S_CAZM);
			strcpy(b_ptr->b_name,ptr->name);
		    }
		    else
			b_ptr->b_name = NULL;

					/* create function */
					/* count and print bits */
		    bit_count = bit_print(ptr->bits);
		    eval_bits(b_ptr, ptr, bit_count, &error_cnt, &num_nodes);

		    			
				/* add to correct list */
		    if (b_ptr->b_node1 >= 0)
		    if (p->sp->type == CMD_BIT) {
				/* Make sure the voltage source is not */
				/* connected to itself */
		        if (b_ptr->b_node2 == b_ptr->b_node1) {
			    sim_error(S_WARNING, S_CAZM,
			    "Voltage source line %d, connected to itself\n",
			    cmd_gb->lineno);
			    break;
		        }
		    	b_tail->b_next = b_ptr;
		    	b_tail = b_ptr;
		    } else {
		    	b_taili->b_next = b_ptr;
		    	b_taili = b_ptr;
		    }

		    if (gp->p_debug_num == 0) 
			cmd_print((struct cmd_head_s *)p->sp);
		    }
		    break;
		case CMD_BUS:
		case CMD_BUSI:
		    {
		    struct cmd_wave_bit_s *ptr;
		    struct vectlst_s *vp;		/* loop var */
		    int found;				/* search flag */
		    int bit_count;			/* number of bits */

							/* Recast it */
		    ptr = (struct cmd_wave_bit_s *)p->sp;

		    /* Set the defaults */
		    if(ptr->pw == ZEROSET)
			ptr->pw = PULSE_WIDTH;
		    if(ptr->rt == ZEROSET)
			ptr->rt = RISE_TIME;
		    if(ptr->ft == ZEROSET)
			ptr->ft = RISE_TIME;
		    if (ptr->lt == ZEROSET)
			ptr->lt = ptr->pw;
		    if (ptr->ht == ZEROSET)
			ptr->ht = ptr->pw;
		    if(ptr->on == ZEROSET && p->sp->type == CMD_BUS)
			ptr->on = VDD_DEFAULT;


		    /* count and print bits */
		    bit_count = bit_print(ptr->bits);


					/* look for vector */
		    found = FALSE;
		    for (vp = vectlst_t; vp != NULL; vp =vp->v_next)
			if (strcmp(vp->v_bus, ptr->node1) == 0) {
						/* copy new values */
			   vp->v_bits = (struct cmd_wave_bit_s *) sim_alloc(
				sizeof(struct cmd_wave_bit_s), S_CAZM);
			   vp->v_bits->pw = ptr->pw;
			   vp->v_bits->on = ptr->on;
			   vp->v_bits->off = ptr->off;
			   vp->v_bits->rt = ptr->rt;
			   vp->v_bits->ft = ptr->ft;
			   vp->v_bits->lt = ptr->lt;
			   vp->v_bits->ht = ptr->ht;
			   vp->v_bits->delay = ptr->delay;
			   vp->v_bits->bits = ptr->bits;
			   vp->v_bits->type = ptr->type;
			   vp->v_bitcnt = bit_count;
			   found = TRUE;
			}

		    if (!found) {		/* see if we have found it */
						/* add to vector list */
			if (vectlst_h == NULL) {
			    vectlst_h = (struct vectlst_s *) sim_alloc(
				sizeof(struct vectlst_s), S_CAZM);
			    vectlst_t = vectlst_h;
			} else {
			    vectlst_h->v_next = (struct vectlst_s *) sim_alloc(
				sizeof(struct vectlst_s), S_CAZM);
			    vectlst_h = vectlst_h->v_next;
			}
			vectlst_h->v_bits = ptr;
			vectlst_h->v_bits = (struct cmd_wave_bit_s *) sim_alloc(
				sizeof(struct cmd_wave_bit_s), S_CAZM);
			vectlst_h->v_bits->pw = ptr->pw;
			vectlst_h->v_bits->on = ptr->on;
			vectlst_h->v_bits->off = ptr->off;
			vectlst_h->v_bits->rt = ptr->rt;
			vectlst_h->v_bits->ft = ptr->ft;
			vectlst_h->v_bits->lt = ptr->lt;
			vectlst_h->v_bits->ht = ptr->ht;
			vectlst_h->v_bits->delay = ptr->delay;
			vectlst_h->v_bits->bits = ptr->bits;
			vectlst_h->v_bits->type = ptr->type;
			vectlst_h->v_names = NULL;
			vectlst_h->v_bus = (char *)
				sim_str_alloc(strlen(ptr->node1), S_CAZM);
			strcpy(vectlst_h->v_bus, ptr->node1);
			vectlst_h->v_bitcnt = bit_count;
			vectlst_h->v_next = NULL;
		    }

		    if (gp->p_debug_num == 0) 
			cmd_print((struct cmd_head_s *)p->sp);
		    			
		    }
		    break;
		case CMD_VECTOR:
		    {
		    struct cmd_vector_s *vect;
		    struct name_s *np;			/* name loop var */
		    struct vectlst_s *vp;		/* loop var */
		    int found;				/* search flag */

							/* Recast it */
		    vect = (struct cmd_vector_s *)p->sp;

						/* look for vector */
		    found = FALSE;
		    for (vp = vectlst_t; vp != NULL; vp =vp->v_next)
			if (strcmp(vp->v_bus, vect->v_name) == 0) {
			   vp->v_names = vect->v_nodes;
			   found = TRUE;
			}

		    if (!found) {		/* see if we have found it */
						/* add info to list */
			if (vectlst_h == NULL) {
			    vectlst_h = (struct vectlst_s *) sim_alloc(
				sizeof(struct vectlst_s), S_CAZM);
			    vectlst_t = vectlst_h;
			} else {
			    vectlst_h->v_next = (struct vectlst_s *) sim_alloc(
				sizeof(struct vectlst_s), S_CAZM);
			    vectlst_h = vectlst_h->v_next;
			}
			vectlst_h->v_bits = NULL;
			vectlst_h->v_names = vect->v_nodes;
			vectlst_h->v_bus = (char *)
				sim_str_alloc(strlen(vect->v_name), S_CAZM);
			strcpy(vectlst_h->v_bus, vect->v_name);
			vectlst_h->v_next = NULL;
		    }
		    if (gp->p_debug_num == 0) 
			cmd_print((struct cmd_head_s *)p->sp);
		    			
		    }
		    break;
		case CMD_VOLT :
				/* Constant voltage sources are stored as
				 * piecewise linear functions with two points
				 * and of slope 0 
				 */
		    {
		    struct sp_volt_s *volt;
		    char *node; 
		    int i;
							/* Recast it */
		    volt = (struct sp_volt_s *)p->sp;

		    b_ptr = (struct boundary_s *)
		            sim_alloc(sizeof(struct boundary_s), S_CAZM);
		    b_ptr->b_length = 2;
		    b_ptr->b_delay = 0;

				/* Allocate name  */
		    if(volt->voltname != NULL) {
			b_ptr->b_name = (char *)
			    sim_str_alloc(strlen(volt->voltname), S_CAZM);
			strcpy(b_ptr->b_name,volt->voltname);
		    }
		    else
			b_ptr->b_name = NULL;

				/* Hash nodes */
		    node = (char *) 
			    sim_str_alloc(strlen(volt->voltnode1), S_CAZM);
		    strcpy(node,volt->voltnode1);

		    b_ptr->b_node1 = hash_nodes(node,&num_nodes,
			node_hash, &node_names);

		    if (volt->voltnode2 != NULL) {
			node = (char *) 
				sim_str_alloc(strlen(volt->voltnode2), S_CAZM);
			strcpy(node,volt->voltnode2);
			b_ptr->b_node2 = hash_nodes(node,&num_nodes,
			    node_hash, &node_names);
	 	    } else {	
			b_ptr->b_node2 = GNDNUM;
		    }
				/* Make sure the voltage source is not */
				/* connected to itself */
		    if (b_ptr->b_node2 == b_ptr->b_node1) {
			sim_error(S_WARNING, S_CAZM,
			"Voltage source line %d, connected to itself\n",
			cmd_gb->lineno);
			break;
		    }

					/* allocate memory for piecewise fn*/
		    b_ptr->b_value = (double *) sim_alloc(sizeof(double)
		 	              * b_ptr->b_length, S_CAZMWAV);
		    b_ptr->b_grid = (double *) sim_alloc(sizeof(double)
		 	              * b_ptr->b_length, S_CAZMWAV);

							/* copy values */
		    for (i = 0; i < b_ptr->b_length ; i++) {
			b_ptr->b_grid[i] = (double)i * 20.0;
			b_ptr->b_value[i] = volt->voltvalue;
		    }
		    b_ptr->b_row = 0;
		    b_tail->b_next = b_ptr;
		    b_tail = b_ptr;

                                     		/* AC ANALYSIS */
		    if (volt->acmag != ZEROSET || volt->acphase != ZEROSET){
			add_acvolt(gp, b_ptr->b_node1, b_ptr->b_node2,
				b_ptr->b_name, volt->acmag, volt->acphase,
				b_ptr, (struct other_wavef_s *)NULL);
		    }	

		    if (gp->p_debug_num == 0)
			cmd_print((struct cmd_head_s *)p->sp);
		    }
		    break;
		case CMD_VV :
		    {
				/* voltage controlled voltage source */
		    struct sp_vv_s *vv;
		    char *node;

					/* Recast it */
		    vv = (struct sp_vv_s *)p->sp;
		    v_ptr = (struct volt_volt_s *)
			  sim_alloc(sizeof(struct volt_volt_s), S_CAZM);
		    v_ptr->v_type = p->sp->type;

				/* Allocate name  */
		    if(vv->vvname != NULL) {
			v_ptr->v_name = (char *)
			    sim_str_alloc(strlen(vv->vvname), S_CAZM);
			strcpy(v_ptr->v_name,vv->vvname);
		    }
		    else
			v_ptr->v_name = NULL;

				/* Hash nodes */
		    node = (char *) 
			    sim_str_alloc(strlen(vv->posnode1), S_CAZM);
		    strcpy(node,vv->posnode1);
		    v_ptr->v_node1 = hash_nodes(node,&num_nodes,
			node_hash, &node_names);

		    node = (char *) 
			    sim_str_alloc(strlen(vv->negnode2), S_CAZM);
		    strcpy(node,vv->negnode2);
		    v_ptr->v_node2 = hash_nodes(node,&num_nodes,
			node_hash, &node_names);

		    node = (char *) 
			    sim_str_alloc(strlen(vv->posnode3), S_CAZM);
		    strcpy(node,vv->posnode3);
		    v_ptr->v_node3 = hash_nodes(node,&num_nodes,
			node_hash, &node_names);

		    node = (char *) 
			    sim_str_alloc(strlen(vv->negnode4), S_CAZM);
		    strcpy(node,vv->negnode4);
		    v_ptr->v_node4 = hash_nodes(node,&num_nodes,
			node_hash, &node_names);

		    v_ptr->v_value = vv->vvvalue;
				/* Make sure the voltage source is not */
				/* connected to itself */
		    if (v_ptr->v_node3 == v_ptr->v_node4) {
			sim_error(S_WARNING, S_CAZM,
			"Voltage source line %d, connected to itself\n",
			cmd_gb->lineno);
			break;
		    }
		    v_tail->v_next = v_ptr;
		    v_tail = v_ptr;

		    if (gp->p_debug_num == 0) 
			cmd_print((struct cmd_head_s *)p->sp);

		    }
		    break;
		case CMD_CURRENT :
		    {
		    struct sp_current_s *cur;
		    char *node;
		    int i;
				/*
				* Constant current sources are stored as
				* piecewise linear functions with two points
				* and of slope 0 if it is a voltage dependent
				* current source the information is stored
				* in the circuit list
				*/
				/* Recast it */
		    cur = (struct sp_current_s *)p->sp;
				/* constant current */
		    b_ptr = (struct boundary_s *)
			sim_alloc(sizeof(struct boundary_s), S_CAZM);

				/* Allocate name  */
		    if(cur->currentname != NULL) {
			b_ptr->b_name = (char *)
			    sim_str_alloc(strlen(cur->currentname), S_CAZM);
			strcpy(b_ptr->b_name,cur->currentname);
		    }
		    else
			b_ptr->b_name = NULL;

				/* hash nodes  */
		    node = (char *) 
			    sim_str_alloc(strlen(cur->posnode1), S_CAZM);
		    strcpy(node,cur->posnode1);
		    b_ptr->b_node1 = hash_nodes(node,&num_nodes,
			node_hash, &node_names);

		    node = (char *) 
			    sim_str_alloc(strlen(cur->negnode2), S_CAZM);
		    strcpy(node,cur->negnode2);
		    b_ptr->b_node2 = hash_nodes(node,&num_nodes,
			node_hash, &node_names);

		    b_ptr->b_length = 2;
		    b_ptr->b_delay = 0;

				    /* allocate memory for piecewise fn*/
		    b_ptr->b_value = (double *) sim_alloc(sizeof(double)
				  * b_ptr->b_length, S_CAZMWAV);
		    b_ptr->b_grid = (double *) sim_alloc(sizeof(double)
				  * b_ptr->b_length, S_CAZMWAV);

						    /* copy values */
		    for (i = 0; i < b_ptr->b_length ; i++) {
			b_ptr->b_grid[i] = (double)i * 20.0;
				/* Current flows positive to negative */
			b_ptr->b_value[i] = cur->currentvalue;
		    }
		    b_taili->b_next = b_ptr;
		    b_taili = b_ptr;

                                     		/* AC ANALYSIS */
	            if (cur->acmag != ZEROSET || cur->acphase != ZEROSET){
			add_accur(gp, b_ptr->b_node1,
				b_ptr->b_node2, b_ptr->b_name,
				cur->acmag, cur->acphase);
		    }

		    if (gp->p_debug_num == 0) 
			cmd_print((struct cmd_head_s *)p->sp);

		    }
		    break;
		case CMD_VC :
		    {
		    struct sp_vc_s *vc;
		    struct circuit_s *cp;
		    char *node;

			/* recast it */
		    vc = (struct sp_vc_s *)p->sp;

				/* voltage controlled current source */
		    cp = (struct circuit_s *)
		    	sim_alloc(sizeof(struct circuit_s), S_CAZM);

		    if(vc->vcname != NULL) {
			cp->c_name = (char *)
			    sim_str_alloc(strlen(vc->vcname), S_CAZM);
			strcpy(cp->c_name, vc->vcname);
		    }
		    else
			cp->c_name = NULL;

				/* Hash nodes */
		    node = (char *) 
			    sim_str_alloc(strlen(vc->posnode1), S_CAZM);
		    strcpy(node,vc->posnode1);
		    cp->c_nodes[0] = hash_nodes(node,&num_nodes,
			node_hash, &node_names);

		    node = (char *) 
			    sim_str_alloc(strlen(vc->negnode2), S_CAZM);
		    strcpy(node,vc->negnode2);
		    cp->c_nodes[1] = hash_nodes(node,&num_nodes,
			node_hash, &node_names);

		    node = (char *) 
			    sim_str_alloc(strlen(vc->posnode3), S_CAZM);
		    strcpy(node,vc->posnode3);
		    cp->c_nodes[3] = hash_nodes(node,&num_nodes,
			node_hash, &node_names);

		    node = (char *) 
			    sim_str_alloc(strlen(vc->negnode4), S_CAZM);
		    strcpy(node,vc->negnode4);
		    cp->c_nodes[2] = hash_nodes(node,&num_nodes,
			node_hash, &node_names);

				/* Current flows positive to negative */
		    cp->c_val = vc->vcvalue;
		    cp->c_numnodes = 4;
		    cp->c_type = VOLT_CURR;
		    cp->c_next = gp->p_circuit;
		    gp->p_circuit = cp;

		    if (gp->p_debug_num == 0) 
			cmd_print((struct cmd_head_s *)p->sp);
		    }
		    break;
		default:
		    break;
	    }
	}

	/* Parse command primitives.  */
	if(pass->sp_commands != NULL)
	for (p = pass->sp_commands ;p != NULL; p = p->next) {

	    switch(p->sp->type) {

		case SP_PRINT :
		    {
		    struct spcmd_plot_s *pcmd;

				/* Recast it */
		    pcmd = (struct spcmd_plot_s *)p->sp;

				/* Store plot sets by filename */
		    plot_parse(gp, pcmd);

                    if (gp->p_debug_num == 0) 
			sp_print(p->sp);
		    }
		    break;
		case SP_IC:
		    {
		    struct spcmd_ic_s *ic;

				/* Recast it */
		    ic = (struct spcmd_ic_s *)p->sp;

		    ic_setup(gp, ic, num_nodes, &error_cnt);

		       
		    if (gp->p_debug_num == 0) 
			sp_print(p->sp);
		       
		    }
		    break;
                case SP_DCG :
                    {
		    struct spcmd_dcg_s *dcg;

                                /* Recast it */
                    dcg = (struct spcmd_dcg_s *)p->sp;

		    dcg_setup(gp, dcg, num_nodes, &error_cnt);

                    if (gp->p_debug_num == 0) 
			sp_print(p->sp);

                    }
                    break;
		case SP_TRANSIENT:
		    {
		    struct spcmd_transient_s *tr_sp;
		    struct transient_s *tr;

				/* Recast it */
		    tr_sp = (struct spcmd_transient_s *)p->sp;

		    tr_sp->type = CMD_TRANSIENT;
		    transient_parse(gp, tr_sp);

		    if (gp->p_debug_num == 0) 
			sp_print(p->sp);

		    }
		    break;
		case SP_TRANSFER :
		    {
		    struct spcmd_transfer_s *tr_cmd;

				/* Recast it */
		    tr_cmd = (struct spcmd_transfer_s *)p->sp;

		    transfer_parse(gp, tr_cmd);

		    if (gp->p_debug_num == 0) 
			sp_print(p->sp);

		    }
		    break;
		case SP_AC:    	/* AC analysis is requested  */
		    {
		    struct spcmd_ac_s *ac_cmd;

				/* Recast it */
		    ac_cmd = (struct spcmd_ac_s *)p->sp;

		    ac_parse(gp, ac_cmd);

		    if (gp->p_debug_num == 0) 
			sp_print(p->sp);
		    }
		    break;
		case SP_TEMPERATURE :
		    {
		    struct spcmd_temperature_s *t_cmd;
		    struct spcmd_tpoints_s *ts;
		    struct temperature_s *t;
							/* Recast it */
		    t_cmd = (struct spcmd_temperature_s *)p->sp;

				    /* Set the first temperature */ 
		    t = (struct temperature_s *)
			    sim_alloc(sizeof(struct temperature_s), S_CAZM);

		    t->tpoints = t_cmd->tpoints;

				/* Link it */
		    t->next = gp->p_temp;
		    gp->p_temp = t;

		    if (gp->p_debug_num == 0) 
			cmd_print((struct cmd_head_s *)p->sp);
		    }
		    break;
		case SP_OPTIONS :
		    {
		    struct sp_options_s *opt;
							/* Recast it */
		    opt = (struct sp_options_s *)p->sp;

		    if(opt->numdgt != ZEROSET)
			gp->p_decimal = opt->numdgt;

				/* Only set these variables if they are
				 * LARGER than the default value.
				 */
		    if(opt->itl1 != ZEROSET)
			if((int)opt->itl1 > gp->p_max_dc)
			    gp->p_max_dc = (int)opt->itl1;

		    if(opt->itl2 != ZEROSET)
			if((int)opt->itl2 > gp->p_max_dc)
			    gp->p_max_dc = (int)opt->itl2;

		    if(opt->itl3 != ZEROSET)
			if((int)opt->itl3 > gp->p_max_tr)
			    gp->p_max_tr = (int)opt->itl3;


				/* Only set these variables if they are
				 * SMALLER than the default value 
				 */
		    if(opt->reltol != ZEROSET)
			if(opt->reltol < gp->p_relative)
			    gp->p_relative = opt->reltol;

		    if(opt->abstol != ZEROSET)
			if(opt->abstol < gp->p_abs)
			    gp->p_abs = opt->abstol;

		    if(opt->chgtol != ZEROSET)
			if(opt->chgtol < gp->p_chargetol)
			gp->p_chargetol = opt->chgtol;
		   

		    if (gp->p_debug_num == 0) 
			cmd_print((struct cmd_head_s *)p->sp);
		    }
		default:
		    break;
	    }
	}


	/* Parse command primitives.  */
	if(pass->cmd_commands != NULL)
	for (p = pass->cmd_commands ;p != NULL; p = p->next) {

	    switch(p->sp->type) {

		case CMD_VRANGE:
		    {
			struct cmd_vrange_s *vrange;
			double vmax;

			/* Recast it */
			vrange = (struct cmd_vrange_s *)p->sp;
			vmax   = vrange->vmax;

			switch (vrange->device) {
			    case SP_MOSFET:
				mod_setup(MOD_MOSFET,vmax,
					gp->p_tab_size);
				break;
			    case SP_BIPOLAR:
				mod_setup(MOD_BIPOLAR,vmax,
					gp->p_tab_size);
				break;
			    case SP_JFET:
				mod_setup(MOD_JFET,vmax,
					gp->p_tab_size);
				break;
			    case SP_MESFET:
				mod_setup(MOD_MESFET,
					vmax,gp->p_tab_size);
				break;
			    case SP_DIODE:
				mod_setup(MOD_DIODE,
					vmax,gp->p_tab_size);
				break;
			}

		    if (gp->p_debug_num == 0)
			cmd_print((struct cmd_head_s *)p->sp);
		    }
		    break;

		case CMD_GRID:
		    {
			struct cmd_gridsize_s *grid;
			int    dims[SIM_MAXTERM];

			/* Recast it */
			grid = (struct cmd_gridsize_s *)p->sp;
			
			switch (grid->device) {
			    case SP_MOSFET:
					/* Source is ref node */
				dims[0] = grid->dim1;	/* Drain */
				dims[1] = grid->dim2;	/* Gate */
				dims[3] = grid->dim3;	/* Bulk */
				if (dims[0] == 0 || dims[1] == 0 ||
				    dims[3] == 0) {
				    sim_error(S_WARNING, S_CAZM,
					"Improper gridsize specification; using defaults");
				} else
				    mod_gsize(gp->p_tab_size,MOD_MOSFET,
						dims );
			    break;
			    case SP_BIPOLAR:
					/* Source is ref node */
					/* Emitter is ref node */
				dims[0] = grid->dim1;	/* Collector */
				dims[1] = grid->dim2;	/* Base */
				if (dims[0] == 0 || dims[1] == 0 ) {
				    sim_error(S_WARNING, S_CAZM,
					"Improper gridsize specification; using defaults");
				} else
				    mod_gsize(gp->p_tab_size,MOD_BIPOLAR,
					dims);
			    break;
			    case SP_JFET:
					/* Source is ref node */
				dims[0] = grid->dim1;	/* Drain */
				dims[1] = grid->dim2;	/* Gate */
				if (dims[0] == 0 || dims[1] == 0 ) {
				    sim_error(S_WARNING, S_CAZM,
					"Improper gridsize specification; using defaults");
				} else
				    mod_gsize(gp->p_tab_size,MOD_JFET,
					dims);
			    break;
			    case SP_MESFET:
					/* Source is ref node */
				dims[0] = grid->dim1;	/* Drain */
				dims[1] = grid->dim2;	/* Gate */
				dims[2] = grid->dim3;	/* bulk */
				if (dims[0] == 0 || dims[1] == 0 ) {
				    sim_error(S_WARNING, S_CAZM,
					"Improper gridsize specification; using defaults");
				} else
				    mod_gsize(gp->p_tab_size,MOD_MESFET,
					dims);
			    break;
			    case SP_DIODE:
					/* Cathode is ref node */
				dims[0] = grid->dim1;	/* Anode */
				if (dims[0] == 0 ) {
				    sim_error(S_WARNING, S_CAZM,
					"Improper gridsize specification; using defaults");
				} else
				    mod_gsize(gp->p_tab_size, MOD_DIODE, 
					dims);
			    break;
			}

		    if (gp->p_debug_num == 0)
			cmd_print((struct cmd_head_s *)p->sp);
		    }
		    break;
		case CMD_TABLE :
		    {
		    struct cmd_table_s *fsp;

				/* Recast it */
		    fsp = (struct cmd_table_s *)p->sp;

		    hash_model(fsp->name, fsp->ffile, fsp->qfile, 
			gp->p_modellist, (struct sp_model_s *)NULL,
				FOURTERM);

		    if (gp->p_debug_num == 0)
			cmd_print((struct cmd_head_s *)p->sp);
		    }
		    break;
		case CMD_PLOT :
		    {
		    struct spcmd_plot_s *pcmd;

				/* Recast it */
		    pcmd = (struct spcmd_plot_s *)p->sp;

				/* Store plot sets by filename */
		    plot_parse(gp, pcmd);

                    if (gp->p_debug_num == 0) 
			cmd_print((struct cmd_head_s *)p->sp);
		    }
		    break;
                case CMD_DCOPPT :
                    {
                    struct cmd_dcoppt_s *dcoppt;

                                /* Recast it */
                    dcoppt = (struct cmd_dcoppt_s *)p->sp;

                    if (gp->p_debug_num == 0) 
			cmd_print((struct cmd_head_s *)p->sp);

                    gp->p_dcoppt = dcoppt;
                    }
                    break;
                case CMD_DCG :
                    {
		    struct spcmd_dcg_s *dcg;

                                /* Recast it */
                    dcg = (struct spcmd_dcg_s *)p->sp;

		    dcg_setup(gp, dcg, num_nodes, &error_cnt);

                    if (gp->p_debug_num == 0) 
			cmd_print((struct cmd_head_s *)p->sp);

                    }
                    break;
		case CMD_IC:
		    {
		    struct spcmd_ic_s *ic;

				/* Recast it */
		    ic = (struct spcmd_ic_s *)p->sp;

		    ic_setup(gp, ic, num_nodes, &error_cnt);

		       
		    if (gp->p_debug_num == 0) 
			cmd_print((struct cmd_head_s *)p->sp);
		       
		    }
		    break;
		case CMD_AC:    	/* AC analysis is requested  */
		    {
		    struct spcmd_ac_s *ac_cmd;

				/* Recast it */
		    ac_cmd = (struct spcmd_ac_s *)p->sp;

		    ac_parse(gp, ac_cmd);

		    if (gp->p_debug_num == 0) 
			cmd_print((struct cmd_head_s *)p->sp);
		    }
		    break;
		case CMD_ACMODEL:    	/* AC models are requested  */
		    {
		    struct cmd_acmodel_s *acp;

				/* Recast it */
		    acp = (struct cmd_acmodel_s *)p->sp;

			/* set the filename if undefined */
		    if(acp->filename == NULL) {
			acp->filename = (char *)
			    sim_str_alloc(strlen(NONAME), S_CAZM);
			strcpy(acp->filename, NONAME);
		    }
		    ac_plotsetup(gp, acp);

		    if (gp->p_debug_num == 0) 
			cmd_print((struct cmd_head_s *)p->sp);

		    }
		    break;
		case CMD_PREVIEW:
		case CMD_POWERUP:
	    	case CMD_TRANSIENT :	/* Transient analysis is requested */
		    {
		    struct spcmd_transient_s *tr_cmd;

				/* Recast it */
		    tr_cmd = (struct spcmd_transient_s *)p->sp;
		    transient_parse(gp, tr_cmd);

		    if (gp->p_debug_num == 0) 
			cmd_print((struct cmd_head_s *)p->sp);

		    }
		    break;
		case CMD_TRANSFER :
		    {
		    struct spcmd_transfer_s *tr_cmd;

				/* Recast it */
		    tr_cmd = (struct spcmd_transfer_s *)p->sp;

		    transfer_parse(gp, tr_cmd);

		    if (gp->p_debug_num == 0) 
			cmd_print((struct cmd_head_s *)p->sp);

		    }
		    break;
		case CMD_TEMPERATURE :
		    {
		    struct spcmd_temperature_s *t_cmd;
		    struct spcmd_tpoints_s *ts;
		    struct temperature_s *t;
							/* Recast it */
		    t_cmd = (struct spcmd_temperature_s *)p->sp;

				    /* Set the first temperature */ 
		    t = (struct temperature_s *)
			    sim_alloc(sizeof(struct temperature_s), S_CAZM);

		    t->tpoints = t_cmd->tpoints;

				/* Link it */
		    t->next = gp->p_temp;
		    gp->p_temp = t;

		    if (gp->p_debug_num == 0) 
			cmd_print((struct cmd_head_s *)p->sp);
		    }
		    break;
		case CMD_POWER:
		    {
		    struct cmd_power_s *power;
		    struct cmd_power_s *pt;

							/* Recast it */
		    power = (struct cmd_power_s *)p->sp;
		    pt = (struct cmd_power_s *) sim_alloc(sizeof(struct
			cmd_power_s), S_CAZM);

		    pt->p_nodes[0] = get_node_num(gp, num_nodes, node_hash,
				 power->p_node1, &error_cnt);
		    pt->p_nodes[1] = get_node_num(gp, num_nodes, node_hash,
				 power->p_node2, &error_cnt);

			/* copy some stuff */
		    pt->p_node1 = (char *)
			sim_str_alloc(strlen(power->p_node1), S_CAZM);
		    pt->p_node2 = (char *)
			sim_str_alloc(strlen(power->p_node2), S_CAZM);
		    strcpy(pt->p_node1, power->p_node1);
		    strcpy(pt->p_node2, power->p_node2);

		    pt->start_time = power->start_time;
		    pt->final_time = power->final_time;
		    pt->power_sum = 0;
		    pt->power_max = 0;
		    pt->power_min = HUGE;
		    pt->min_time = 0;
		    pt->max_time = 0;
		

			                      /* check for an error */
	            if (pt->p_nodes[0] >= 0 && pt->p_nodes[1] >= 0)
			pt->p_next = gp->p_power;
			gp->p_power = pt;

		    if (gp->p_debug_num == 0) 
			cmd_print((struct cmd_head_s *)p->sp);

		    }
		    break;
		case CMD_OPTIONS :
		    {
		    struct cmd_options_s *opt;

						/* Recast it */
		    opt = (struct cmd_options_s *)p->sp;


		    if(opt->numnd != ZEROSET)
			gp->p_max_dc = opt->numnd;

		    if(opt->numnt != ZEROSET)
			gp->p_max_tr = opt->numnt;

		    if(opt->debug != ZEROSET)
			gp->p_debug_num = opt->debug;

		    if(opt->reltol != ZEROSET)
			gp->p_relative = opt->reltol;

		    if(opt->abstol != ZEROSET)
			gp->p_abs = opt->abstol;

		    if(opt->chargetol != ZEROSET)
			gp->p_chargetol = opt->chargetol;

		    if(opt->relchargetol != ZEROSET)
			gp->p_relchargetol = opt->relchargetol;

		    if(opt->lsolver != ZEROSET)
			gp->p_linear_equ = opt->lsolver;

		    if(opt->moscap != ZEROSET)
			gp->p_moscap = TRUE;

		    if(opt->decimal != ZEROSET)
			gp->p_decimal = opt->decimal;

		    if(opt->tdelay != ZEROSET)
			gp->p_tdelay = opt->tdelay;

		    if (gp->p_debug_num == 0)  
			cmd_print((struct cmd_head_s *)p->sp);
		    }
		    break;
		default:
		    break;
	    }
	}

					/* set up wave functs for busses */
	for (vectlst_t ; vectlst_t != NULL ; vectlst_t = vectlst_t->v_next) {
	    if (vectlst_t->v_bits == NULL ) {
	    	sim_error(S_FATAL, S_CAZM,"Missing bus declaration for %s",
		    vectlst_t->v_bus);
		exit(1);
	    }
	    else 
	    if (vectlst_t->v_names == NULL) {
	    	sim_error(S_FATAL, S_CAZM,"Missing vector declaration for %s"
		    ,vectlst_t->v_bus);
		exit(1);
	    }
	    else {			/* we are clear to create */
		b_ptr = (struct boundary_s *)
		            sim_alloc(sizeof(struct boundary_s), S_CAZM);
		b_ptr->b_next = NULL;
		create_bus(vectlst_t->v_bits, vectlst_t->v_names, 
			b_ptr, vectlst_t->v_bitcnt, &error_cnt, &num_nodes);

				/* add information to correct list */
		if (vectlst_t->v_bits->type == CMD_BUS) {
		    	b_tail->b_next = b_ptr;
		    	b_tail = b_ptr;
					/* find tail again */
			for (b_tail; b_tail->b_next != NULL ; 
				b_tail = b_tail->b_next);
		} else {
		    	b_taili->b_next = b_ptr;
		    	b_taili = b_ptr;
					/* find tail again */
			for (b_taili; b_taili->b_next != NULL ; 
				b_taili = b_taili->b_next);
		}
	    }
	}
		
			/* terminate the lists */
	b_tail->b_next = NULL;
	v_tail->v_next = NULL;

			/* Link the new currents in the list */
	if(b_headi->b_next != NULL) {
			/* Nothing in the old list */
	    if (gp->p_currb == NULL) {
		gp->p_currb = b_headi->b_next;
		b_taili->b_next = NULL;
	    }
	    else {
			/* else, go to the end of the list */
		for (b_ptr = gp->p_currb; b_ptr->b_next != NULL;
				b_ptr = b_ptr->b_next)
		    {;}

			/* Link new to old list */
		b_ptr->b_next = b_headi->b_next;
		b_taili->b_next = NULL;
	    }
	}

			/* Link the new voltage-cntl-voltage in the list */
	if(v_head->v_next != NULL) {
			/* Nothing in the old list */
	    if (gp->p_volt_v == NULL) {
		gp->p_volt_v = v_head->v_next;
		v_tail->v_next = NULL;
	    }
	    else {
			/* else, go to the end of the list */
		for (v_ptr = gp->p_volt_v; v_ptr->v_next != NULL;
				v_ptr = v_ptr->v_next)
		    {;}

			/* Link new to old list */
		v_ptr->v_next = v_head->v_next;
		v_tail->v_next = NULL;
	    }
	}
		/* Update number of nodes */
	gp->p_num_nodes = num_nodes;
			/* Check all plot lists */
	plot_setup(gp, &error_cnt);
	transfer_setup(gp, &error_cnt);
	temperature_check(gp);
			/* Free the hash tables */
			/*
	bhash_free();
	chash_free();
	*/


			/*----------------------------*/
			/* End of Parse loop, now     */
			/* clean up loose ends        */
			/* exit if parse errors exist */
			/*----------------------------*/
	if (error_cnt > 0) {
	    sim_error(S_FATAL, S_CAZM,"%d errors found\n", error_cnt);
	    exit(1);
	}

			/* dump spice output */
	if (gp->p_debug_num == 1) {
	    output_spice(gp->p_boundary, node_names);
	}
}

transfer_setup(gp, error_cnt)
Param *gp;	/* system structure */ 
int *error_cnt; 
{
	struct boundary_s *b;
	struct bhash_table_s *h;
	struct bhash_table_s *hash_boundary();
	struct transfer_s *tr;
	struct cmd_transfer_s *tr_cmd;
	int i;

	if(gp->p_transfer == NULL)
		return;

	tr = gp->p_transfer;


	for(i=0; i< 3; i++) {

	    if( tr->src[i] != NULL) {

		if (tr->src[i]->inc == 0) {
		    sim_error(S_FATAL, S_CAZM,
			    "Zero increment in transfer command.");
		    gp->p_transfer = NULL;
		    error_cnt++;
		    return;
		}

		    /* look for a boundary DC source, if a voltage
		     * or current source was not found return error.
		     */
		h = hash_boundary(tr->src[i]->name,
			(struct boundary_s *)NULL, NULL);
		if(h == NULL) {
		    sim_error(S_FATAL, S_CAZM,
			"Device name \"%s\" does not select a DC source.",
			    tr->src[i]->name);
		    gp->p_transfer = NULL;
		    error_cnt++;
		    return;
		}
		else  {
			    /* Save the type and pointer */
		    if(h->b_type == CMD_VOLT || h->b_type == CMD_SIN || 
		       h->b_type == CMD_CURRENT || h->b_type == CMD_SINI) {
			tr->b[i] = (struct boundary_s *)h->b;
			tr->type[i] = h->b_type;
		    }
		    else {
			sim_error(S_FATAL, S_CAZM,
			    "Illegal DC source type \"%s\".",
				tr->src[i]->name);
			gp->p_transfer = NULL;
			error_cnt++;
			return;
		    }
		}
	    }
	}


}

/*
-----------------------------------------------------------------
TEMPERATURE_CHECK()
	Set the default temperature if not parsed in.
-----------------------------------------------------------------
*/
temperature_check(gp)
Param *gp;
{
	struct spcmd_temperature_s *temp;
	struct spcmd_tpoints_s *ts;
	struct temperature_s *t;

	if(gp->p_temp == NULL) {

	    t = (struct temperature_s *)
		    sim_alloc(sizeof(struct temperature_s), S_CAZM);
	    ts = (struct spcmd_tpoints_s *)
		    sim_alloc(sizeof(struct spcmd_tpoints_s), S_CAZM);

		    /* Set the default temperature */
	    ts->temperature = 27.0;

	    t->tpoints = ts;
	    gp->p_temp = t;
	}
	
}

/*
-----------------------------------------------------------------
|    EVAL_BITS
|    takes bit structure and determines a piecewise linear function
-----------------------------------------------------------------
*/
eval_bits(b_ptr, bit_cmd, bit_count, error_cnt, num_nodes)
struct boundary_s *b_ptr;		/* structure to contain function */
struct cmd_wave_bit_s *bit_cmd;		/* structure containing Phase, ON
					 * off voltages and the function
					 * description */
int bit_count;				/* number of bits */
int *error_cnt;
int *num_nodes;
{
	int tn_l, tn_h;			/* time units HIGH/LOW*/
	int gn;				/* grid units */
	int i;
	double shift;		/* shift waveform so we can repeat it */

				/* bit waveforms are set up as piecewise
				 * linear pulses with sloped changes of state.
				 */

	b_ptr->b_length = 2 * bit_count + 1;
							/* hash node  */
	b_ptr->b_node1 = hash_nodes(bit_cmd->node1,
		    num_nodes, node_hash, &node_names);

			       /* check for an error */
	if (b_ptr->b_node1 == -1)
	    return;

	if (bit_cmd->node2 != NULL) {
	b_ptr->b_node2 = hash_nodes(bit_cmd->node2,
		    num_nodes, node_hash, &node_names);
	    if (b_ptr->b_node2 == -1)	/* ignore node */
		return;
	}
	else 
	    b_ptr->b_node2 = GNDNUM;	/* default is ground */

					/* allocate memory for piecewise fn */
	b_ptr->b_value = (double *) sim_alloc(sizeof(double)
			 * (b_ptr->b_length + 3), S_CAZMWAV);
	b_ptr->b_grid = (double *) sim_alloc(sizeof(double)
		 	 * (b_ptr->b_length + 3), S_CAZMWAV);
		    			
					/* create function */
	tn_l = tn_h = 0;
	gn = 0;
	bit_create(b_ptr, &gn, &tn_h, &tn_l, bit_cmd->on, bit_cmd->off, 
	    bit_cmd->lt, bit_cmd->ht, bit_cmd->rt, bit_cmd->ft, bit_cmd->bits);

			/* If the first and last bit value are equal
			 * then a smooth transition will occur.
			 */
	if (b_ptr->b_value[gn-1] == b_ptr->b_value[0]){

	    b_ptr->b_grid[gn] = tn_h * bit_cmd->ht + tn_l * bit_cmd->lt;

	    b_ptr->b_value[gn] = b_ptr->b_value[gn - 1];
	    b_ptr->b_length = gn + 1;
	    shift = 0.0;

	} else {
			/* Else ensure smooth transitions for repeating
			*	waveforms by adding the falling or
			*	rising waveforms to match the
			*	initial bit value.
			*/
	    b_ptr->b_grid[gn] = tn_h * bit_cmd->ht + tn_l * bit_cmd->lt;

	    if (b_ptr->b_value[0] == bit_cmd->off) {
		b_ptr->b_value[gn] = bit_cmd->on;
		b_ptr->b_value[gn + 1] = bit_cmd->off;
	    	b_ptr->b_grid[gn + 1] = b_ptr->b_grid[gn] + bit_cmd->ft;
		shift = bit_cmd->ft; 
	    } else {
		b_ptr->b_value[gn] = bit_cmd->off;
		b_ptr->b_value[gn + 1] = bit_cmd->on;
	    	b_ptr->b_grid[gn + 1] = b_ptr->b_grid[gn] + bit_cmd->rt;
		shift = bit_cmd->rt;
	    }
	    b_ptr->b_length = gn + 2;

			/* Shift the waveform so it will repeat */ 
	    for (i = 1 ; i< b_ptr->b_length; i++)
	        b_ptr->b_grid[i] -= shift;


			/* Special case.
			 *	When (rt or ft) = pw; b_grid[0] and
			 *	b_grid[1] will both be zero. That's bad! 
			 *	So the fix is to add a real small percentage
			 * 	of the pulse width to b_grid[1].
			 */
	    if ( b_ptr->b_grid[0] == b_ptr->b_grid[1] 
			&& b_ptr->b_value[0] == b_ptr->b_value[1]) 
	    	b_ptr->b_grid[1] += bit_cmd->lt / 1.0e+6;
	}
			/* Add shift to delay to compensate time */ 
	b_ptr->b_delay = bit_cmd->delay + shift;
	   
}
/*
--------------------------------------------------------------
|    BIT_CREATE
|    recursive routine to create pw function for bit input
--------------------------------------------------------------
*/
bit_create(b_ptr, gn, tn_h, tn_l, on, off, lt, ht, rt, ft, bits)
struct boundary_s *b_ptr;
int *gn;				/* grid number */
int *tn_h, *tn_l;			/* current high/low time increment */
double on, off, lt, ht;			/* HI, LOW, and pulse widths */
double rt, ft;				/* rise and fall time of pulse */
struct bit_s *bits;			/* structure containing bits */
{
	int i;				/* loop index */
	struct bit_s *bp;		/* loop variable */
	double time;

	for (bp = bits; bp != NULL ; bp = bp->b_next)
				/* check for descendents */
	    if (bp->b_son != NULL) {
		for (i = 0; i < bp->b_mult; i++)
		    bit_create(b_ptr, gn, tn_h, tn_l, on, off, lt, ht, rt, ft, bp->b_son);
		
	    } else {
				/* evaluate list */
				/* check boundary meeting */
		if (*gn == 0) {
		   b_ptr->b_grid[*gn] = 0.0;
		   if (bp->b_val[0] == '0') {
			b_ptr->b_value[*gn] = off;
			(*tn_l)++;
		   } else {
			b_ptr->b_value[*gn] = on;
			(*tn_h)++;
		   }
		   *gn = *gn + 1;
		} else {
					/* check to see if previous bit was
					 * different */
		   time = *tn_h * ht + *tn_l *lt;
		   if ((b_ptr->b_value[*gn-1] == off && bp->b_val[0] == '1')
			|| (b_ptr->b_value[*gn-1] == on && bp->b_val[0] == '0')
 			) {
			b_ptr->b_grid[*gn] = time;
			if (bp->b_val[0] == '0') {
				b_ptr->b_grid[*gn + 1] = time + ft;
				b_ptr->b_value[*gn] = on;
				b_ptr->b_value[*gn + 1] = off;
				(*tn_h)++;
			} else {
				b_ptr->b_grid[*gn + 1] = time + rt;
				b_ptr->b_value[*gn] = off;
				b_ptr->b_value[*gn + 1] = on;
				(*tn_l)++;
			}
			*gn += 2;
		    } else
		    if (bp->b_val[0] == '0')
				(*tn_l)++;
		    else
				(*tn_h)++;
		}

		for (i = 1; i < strlen(bp->b_val); i++) {
		   time = *tn_h * ht + *tn_l *lt;
		   if (bp->b_val[i] != bp->b_val[i - 1]) {
			    b_ptr->b_grid[*gn] = time;
			    if (bp->b_val[i] == '0') {
			        b_ptr->b_grid[*gn + 1] = time + ft;
				b_ptr->b_value[*gn] = on;
				b_ptr->b_value[*gn + 1] = off;
				(*tn_l)++;
			    } else {
			    b_ptr->b_grid[*gn + 1] = time + rt;
				b_ptr->b_value[*gn] = off;
				b_ptr->b_value[*gn + 1] = on;
				(*tn_h)++;
			    }
			    *gn += 2;
		    } else 		/* increment time counter */
		    if (bp->b_val[i] == '0')
				(*tn_l)++;
		    else
				(*tn_h)++;
	       }
				
	    }
}
/*
-----------------------------------------------------------
|   BIT_PRINT
|   Prints out the bit structure and returns an integer that estimates the
|   size of the piecewise linear function needed to describe it.
-----------------------------------------------------------
*/
int
bit_print(bit_head)
struct bit_s *bit_head;		/* head of the bit structure */
{
	struct bit_s *bp;	/* loop variable */
	int tot;		/* used to count number of bits */

	tot = 0;
	for (bp = bit_head; bp != NULL ; bp = bp->b_next)
				/* check for descendents */
	    if (bp->b_son != NULL) {
		tot += bp->b_mult * bit_print(bp->b_son);
	    } else {
		tot += strlen(bp->b_val);
	    }
	return(tot);
}
/*
--------------------------------------------------------------------
|     CREATE_BUS
|     Steps through vector node list and creates function for each
|     each bit.
-------------------------------------------------------------------
*/
create_bus(wave, nodes, b_ptr, b_cnt, error_cnt, num_nodes)
struct cmd_wave_bit_s *wave;		/* bus bit description */
struct name_s *nodes;			/* node name list */
struct boundary_s *b_ptr;		/* structure to return boundary list */
int b_cnt;				/* bit count */
int *error_cnt;
int *num_nodes;
{
	char *bit_c;			/* string of bits */
	struct name_s *np;		/* loop var */
	struct bit_s t_bits;		/* temporary bit struct */
	struct bit_s *t_bits_p;		/* temporary bit struct pointer */
	int index;			/* index into bit array */
	int bitn;			/* bit number */
	int num_n;			/* number of nodes */

					/* count number of input nodes */
	num_n = 0;
	for (np = nodes; np != NULL; np = np->next, num_n++) ;
						/* allocate bit string */
	bit_c = (char *) sim_alloc(b_cnt + 1, S_CAZM);
						/* init bit structure */
	t_bits.b_son = NULL;
	t_bits.b_next = NULL;
	t_bits_p = wave->bits;
	wave->bits = &t_bits;
	bitn = 0; 			/* first str pos is high order bit */

					/* Set node2 equal to "gnd" */ 
	wave->node2 = (char *) sim_str_alloc(strlen(GND4), S_CAZM);
	strcpy(wave->node2, GND4);

	for (np = nodes; np != NULL; np = np->next, bitn++) {
	    
					/* create bit string */
	    index = 0;
	    bit_sep(t_bits_p, bit_c, bitn, &index, num_n);
	    bit_c[index] = '\0';
					/* create function */
	    t_bits.b_val = bit_c;

					/* Copy node1 */
	    wave->node1 = (char *) sim_str_alloc(strlen(np->node1), S_CAZM);
	    strcpy(wave->node1, np->node1);

	    eval_bits(b_ptr, wave, b_cnt, error_cnt, num_nodes);
					/* link to boundary nodes */
	    if (b_ptr->b_node1 >= 0)
	    if (np->next != NULL) {
		b_ptr->b_next = (struct boundary_s *) sim_alloc(
			sizeof(struct boundary_s), S_CAZM);
		b_ptr = b_ptr->b_next;
		b_ptr->b_next = NULL;
	    }
	}
	if (b_ptr->b_node1 < 0) {
	    sim_error(S_FATAL, S_CAZM, 
		"Vector list has undefined nodes ");
	    exit(1);
	}

}
/*
-----------------------------------------------------------
|   BIT_SEP
|   Separates out the bit structure for one node in a bus and returns
|   the structure
-----------------------------------------------------------
*/
bit_sep(bit_head, bit_c, bitn, index, num_n)
struct bit_s *bit_head;		/* head of the bit structure */
char *bit_c;			/* new bit structure */
int bitn;			/* bit number, 0 = LSB */
int *index;			/* index of bit_s */
int num_n;			/* number of nodes on bus */
{
	struct bit_s *bp;	/* loop variable */
	int i;
	int len;		/* bit pattern length */

	for (bp = bit_head; bp != NULL ; bp = bp->b_next)
				/* check for descendents */
	    if (bp->b_son != NULL) {
		for (i = 0; i < bp->b_mult ; i++)
		    bit_sep(bp->b_son, bit_c, bitn, index, num_n);
	    } else {
				/* check for not enough bits for all input */
		len = strlen(bp->b_val);
		if (len >= num_n - bitn) {
		    bit_c[*index] = bp->b_val[len - num_n + bitn];
		} else {
				/* pad with 0's */
		    bit_c[*index] = '0';
		}
		*index = *index + 1;
	    }
}
/*
---------------------------------------------------------------------
|   OUTPUT_SPICE
|   Output pwl functions of the boundary conditions
|
|   Selected by degbug_num == 1 
----------------------------------------------------------------------
*/

output_spice(b_ptr, node_names)
struct boundary_s *b_ptr;
char **node_names;
{
	struct boundary_s *b;		/* boundary loop var */
	int i;				/* grid loop var */

	for (b = b_ptr; b != NULL; b=b->b_next) {
	     fprintf(stdout, "V");
	     spice_fprintf(stdout, node_names[b->b_node1]); 
	     fprintf(stdout, "%d %d pwl (", b->b_node1, b->b_node2);
	     for (i = 0 ; i < b->b_length ; i++) {
		fprintf(stdout, "%5.5e %5.3f ", b->b_grid[i], b->b_value[i]);
		if ((i % 4) == 0) 
		   fprintf(stdout, "\n+");
	     }
	     fprintf(stdout,")\n");
	}

}

ic_setup(gp, ic, num_nodes, error_cnt)
Param *gp;
struct spcmd_ic_s *ic;
int num_nodes;
int *error_cnt;
{
	struct spcmd_assign_s *ass;
	struct circuit_s *cp;
	int found;

				    /* add nodes numbers to init */
	for (ass = ic->iclist; ass != NULL; ass = ass->next) {
	    if (ass->type == SPCMD_IC_CURRENT) {
				    /* go through circuit list and*/
				    /* find inductor */
		found = FALSE;
		for (cp = gp->p_circuit; cp != NULL; cp=cp->c_next){
		    if (cp->c_type == IND_VOLT_CURR && 
			strcmp(cp->c_name, ass->name) == 0) {
			ass->node_num = cp->c_nodes[2];
			found = TRUE;
			break;
		    }
		}
		if (!found) {
		    sim_error(S_WARNING, S_CAZM, 
		    "Inductor %s not found for initial current assignment",
			ass->name);
		    ass->node_num = GNDNUM;
		}
	    } else {

		ass->node_num = get_node_num(gp, num_nodes,
		    node_hash, ass->name, error_cnt);
		if (ass->node_num == -1) {
		   ass->node_num = GNDNUM;
		   ass->value = 0;
		}
	    }
	}

				/* Link it */
	if (gp->p_ic == NULL)
	   gp->p_ic = ic->iclist;
	else {
			    /* go to the end of the list */
	   for (ass = ic->iclist; ass->next != NULL; ass=ass->next);

	   ass->next = gp->p_ic;
	   gp->p_ic = ic->iclist;
	}
	   
}

dcg_setup(gp, dcg, num_nodes, error_cnt)
Param *gp;
struct spcmd_dcg_s *dcg;
int num_nodes;
int *error_cnt;
{
	struct spcmd_assign_s *ass;

				    /* add nodes numbers to init */
	for (ass = dcg->dcglist; ass != NULL; ass = ass->next) {
	    ass->node_num = get_node_num(gp, num_nodes, node_hash,
		     ass->name, &error_cnt);
				    /* check for illegal node */
	    if (ass->node_num == -1) {
	       ass->node_num = GNDNUM;
	       ass->value = 0;
	    }
	}

				/* Link it */
	if (gp->p_dcg == NULL)
	   gp->p_dcg = dcg->dcglist;
	else {
			    /* go to the end of the list */
	   for (ass = dcg->dcglist; ass->next != NULL; ass=ass->next);

	   ass->next = gp->p_dcg;
	   gp->p_dcg = dcg->dcglist;
	}
}


/*
---------------------------------------------------------------------
|   SPICE_FPRINTF
|   Output strings without underscores 
|
|   Selected by degbug_num == 1 
----------------------------------------------------------------------
*/
spice_fprintf(fp,str)
FILE *fp;
char	*str;
{
	char	*tmp;

	/* NOTE:
	 * Spice thinks "_"'s are illegal characters. So
	 * we will stuff them with "-"'s.
	 */

	tmp = str;
	for ( ; *tmp != NULL ; tmp++ )	/* find last dot in string */
	{
		if (*tmp == '_')
		{
			*tmp = '-';
		}
	}

	fprintf(fp, "%s ", str);
} 


/*
---------------------------------------------------------------------
|   GET_NODE_NUM
|   Search hash table and subcircuit list for node name. Prints error 
|   if not found (and returns -1).
|
----------------------------------------------------------------------
*/
int
get_node_num(gp, num_nodes, node_hash, name, error_cnt)
Param *gp;
int num_nodes;
struct hash_table_s **node_hash;
char *name;
int *error_cnt;
{
	int old_num;
	int node_num;

	old_num = num_nodes;
						/* get node number */
						/* from hash table */
	node_num = hash_nodes(name, &(old_num), node_hash, (char ***)NULL);
	if (num_nodes != old_num || node_num >= num_nodes) {
					/* did not find node in hash table */
					/* so it could be in a subcircuit */
	if((node_num = plot_find(gp, name)) == NULL || node_num >= num_nodes) {
	    sim_error(S_WARNING, S_CAZM, 
		"Node %s is not in this circuit.", name);
	       *error_cnt++;
	    return (-1);
	 }
	}
	return (node_num);
}


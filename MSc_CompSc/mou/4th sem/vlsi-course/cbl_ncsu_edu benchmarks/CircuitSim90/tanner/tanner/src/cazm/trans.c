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

	This file contains the main routine for transfer analysis

----------------------------------------------------------------------------*/
#include <math.h>
#include "Hmain.h"
#include "Hcmd.h"
#include "sim.h"
/*
------------------------------------------------------------------------
|     TRANSFER
|     The front end for transfer analysis, contains outer loop which steps
|     through the chosen voltages.
|
|     Continuation is used to compute the transfer curves as described
|     by the transfer analysis section of the CAzM paper.
|
-------------------------------------------------------------------------
$Header: trans.c,v 1.4 87/10/30 16:10:39 erdman Locked $
$Log:	trans.c,v $
 * Revision 1.4  87/10/30  16:10:39  erdman
 * October release version
 * 
 * Revision 1.2  87/03/25  13:23:20  erdman
 * release version
 * 
 * Revision 1.1  86/10/22  22:48:47  erdman
 * Initial revision
 * 
*/
transfer(gp, val_double, val_int)
register struct param_s *gp;	/* pointer to information structure */
Val_Double *val_double;			/* pointer to double storage arrays */
Val_Int *val_int;			/* pointer to int storage arrays */
{
	double ea;			/* absolute error */
	double er;			/* relative error */
	double s1;			/* initial arc length */
	double s2;			/* final arc length */
	double *up;			/* u' */
	double *gl;			/* partial with respect to lambda */
	double *uold;			/* initial voltage */

	struct transf_s **srcs;		/* increment pointer */
	int num_nodes;			/* number of nodes in circuit */
	int num_ind;			/* number of non_boundary nodes */
	int notdone;			/* transfer loop flag */
	register int i;

	int sign;		/* Direction for autostepping first node */

					/* decls for val_double */
	double *uo, *ui, *ug, *umid, *fo, *fg, *fi, *qo, *qg, *qi, *a, *u, *tu;
	double *x, *gu, *state_info;
					/* decls for val_init */
	int *ja, *la, *ju, *perm, *iperm, *list, *q;


	uo = val_double->uo;		/* array of initial voltages */
	ui = val_double->ui;
	ug = val_double->ug;
	umid = val_double->umid;	/* final value at the middle of the
					   2 steps */
	fo = val_double->fo; 		/* initial fs */
	fg = val_double->fg; 		/* f(n + gamma) */
	fi = val_double->fi; 		/* new fs */
	qo = val_double->qo;		/* initial Q's */
	qg = val_double->qg; 		/* q(n + gamma) */
	qi = val_double->qi;		/* new Q's */
	a = val_double->a;		/* Jacobian values */
	u = val_double->u;		/* factored Jacobian array */
	tu = val_double->tu;		/* double scratch array */
	x = val_double->x;		/* newton direction */
	gu = val_double->gu;		/* g(u) for newton */
	state_info = val_double->state_info;	/* array of state information
						   returned */
					/* calling routine , power, timestep */
	ja = val_int->ja;		/* sparse matrix pointer */
	la = val_int->la;		/* lower triangle pointer */
	ju = val_int->ju;		/* factored sparse matrix pointer */
	perm = val_int->perm;		/* permutation array */
	iperm = val_int->iperm;		/* inverse of permutation array */
	list = val_int->list;		/* scratch array for sparse solve */
	q = val_int->q;			/* second integer scratch array */
	
	num_nodes = gp->p_num_nodes;
	num_ind = gp->p_num_ind;
					/* get space already allocated */
	up = fg;
	gl = qi;
	uold = fi;

					/* set initial simulation values */
	g_time = 0.0;
	er = gp->p_relative;
	ea = gp->p_abs;
	val_double->reltol = er * 1.0e-2;
	val_double->abstol = ea;
	val_int->maxcnt = gp->p_max_dc;
	val_int->maxu = ju[num_ind] * 2 - num_ind;

					/* Transfer stuff */
	srcs = gp->p_transfer->src;

					/* Initialize sources */
	init_sources(gp, val_int, srcs);

					/* call DC operating point */
	dc_op(gp, val_double, val_int, gp->p_dcg);

	for (i = 0; i < num_nodes ; i++)
	    ui[i] = uold[i] = ug[i] = uo[i];

			/* set initial change in arc-length */
	s1 = 0;
	s2 = 0.1;

	if (srcs[0]->start > srcs[0]->end)
		sign = -1;
	else
		sign = 1;	

		/* print header and dc operating point result */
	print_head(gp, TRANS);

						/*------------------------*/
						/* beginning of main loop */
						/*------------------------*/
	notdone = TRUE;
	while (notdone) {

	    outputvalues(0.0, 0.0, ug, gp, TRANS, fi, qo,val_double);

	    val_int->type = TRANS;
			/* set initial u' */
	    initup(gp,val_double,val_int);
						/*------------*/
						/* inner loop */
						/*------------*/
	    while (((srcs[0]->inc > 0) &&
		(srcs[0]->val + srcs[0]->meps < srcs[0]->end )) || 
		 ((srcs[0]->inc < 0) &&
		  (srcs[0]->val - srcs[0]->meps > srcs[0]->end ))) {

	        val_double->s1 = s1;
	        val_double->s2 = s2;
			/* produce an initial guess using forward Euler */
	        for (i = 0; i < num_ind; i++)
		    ug[i] = uold[i] + sign * (s2 - s1) * up[i]; 

			/* Increment the first boundary src */
		inc_sources(gp, srcs, 0);

		newton(gp, val_double, val_int);
		lambda_calc(gp, val_double, val_int);

	        if (val_int->failed) {
		    sim_error(S_FATAL, S_CAZM,
		    "transfer analysis failed, max number of Newton iterations exceeded");
		    exit(1);
		}

		outputvalues(0.0, 0.0, ui, gp, TRANS, fi, qo,val_double);
	 	for (i = 0; i < num_nodes; i++)
		    uold[i] = ui[i];
	    }
				/* now check other ranges and restart */
	    if (srcs[1] != NULL) {
			/* Reset first the boundary src */
		reset_sources(gp, srcs, 0);

		if (((srcs[1]->inc > 0) &&
	            (srcs[1]->val + srcs[1]->meps < srcs[1]->end )) ||
		   ((srcs[1]->inc < 0) &&
	            (srcs[1]->val - srcs[1]->meps > srcs[1]->end ))) {

			    /* Increment second the boundary src */
		    inc_sources(gp, srcs, 1);
		}
		else {

		    if (srcs[2] != NULL) {
				/* Reset second the boundary src */
			reset_sources(gp, srcs, 1);

			if (((srcs[2]->inc > 0) &&
			    (srcs[2]->val + srcs[2]->meps < srcs[2]->end )) || 
			   ((srcs[2]->inc < 0) &&
			    (srcs[2]->val - srcs[2]->meps > srcs[2]->end ))) {

				    /* Increment third the boundary src */
			    inc_sources(gp, srcs, 2);
			}
			else
			    notdone = FALSE;
		    }
		    else
			notdone = FALSE;
		}
		if (notdone) {		/* find new starting point */
	            if (gp->p_csdf) print_head(gp, TRANS);
		    newton(gp, val_double, val_int);
		    lambda_calc(gp, val_double, val_int);

		    if (val_int->failed) {
			sim_error(S_FATAL, S_CAZM,"transfer analysis failed, max number of Newton iterations exceeded");
			exit(1);
		    }
					/* save new starting point */
		    for (i = 0; i < num_nodes ; i++)
			ug[i] = uold[i] = ui[i];
		}
	    }
	    else
		notdone = FALSE;

	} /* end while notdone */
	
		/* restore original source values for other analysis */
	restore_sources(gp, val_int, srcs);

}

init_sources(gp, val_int, srcs)
register struct param_s *gp;	/* pointer main structure */
Val_Int *val_int;			/* pointer storage arrays */
struct transf_s **srcs;			/* pointer */
{

	struct boundary_s *b[3];	/* increment pointer */
	struct other_wavef_s *o[3];
	int i;

		/* Save old boundary source values */
		/* Initialize boundary sources */
	for(i=0; srcs[i] != NULL; i++) {
	    switch(gp->p_transfer->type[i]) {
		case CMD_VOLT: 
		case CMD_CURRENT: 
		    {
			b[i] = gp->p_transfer->b[i];
			srcs[i]->orig = b[i]->b_value[0];
			srcs[i]->val = srcs[i]->start;
			srcs[i]->meps = MACH_EPS * srcs[i]->inc;
			b[i]->b_value[0] = srcs[i]->start;
			b[i]->b_value[1] = srcs[i]->start;
			if(i == 0)
			    val_int->transfer_node = b[i]->b_node1;
		    }
		    break;
		case CMD_SIN:
		case CMD_SINI:
		    {
			o[i] = (struct other_wavef_s *)
				gp->p_transfer->b[i];
			srcs[i]->orig = o[i]->o_value[0]; /* Save offset */
			srcs[i]->val = srcs[i]->start;
			srcs[i]->meps = MACH_EPS * srcs[i]->inc;
			o[i]->o_value[0] = srcs[i]->start;
			if(i == 0)
			    val_int->transfer_node = o[i]->o_node1;
		}
	    }
	}
}

inc_sources(gp, srcs, num)
register struct param_s *gp;	/* pointer main structure */
struct transf_s **srcs;			/* pointer */
int num;
{

	struct boundary_s *b[3];	/* increment pointer */
	struct other_wavef_s *o[3];

		/* Save old boundary source values */
		/* Initialize boundary sources */
	    switch(gp->p_transfer->type[num]) {
		case CMD_VOLT: 
		case CMD_CURRENT: 
		    {
			b[num] = gp->p_transfer->b[num];
			srcs[num]->val += srcs[num]->inc;
			b[num]->b_value[0] += srcs[num]->inc;
			b[num]->b_value[1] += srcs[num]->inc;
		    }
		    break;
		case CMD_SIN:
		case CMD_SINI:
		    {
			o[num] = (struct other_wavef_s *)
				gp->p_transfer->b[num];
			srcs[num]->val += srcs[num]->inc;
			o[num]->o_value[0] += srcs[num]->inc;
		}
	    }
}

reset_sources(gp, srcs, num)
register struct param_s *gp;	/* pointer main structure */
struct transf_s **srcs;			/* pointer */
int num;
{

	struct boundary_s *b[3];	/* increment pointer */
	struct other_wavef_s *o[3];

		/* Save old boundary source values */
		/* Initialize boundary sources */
	    switch(gp->p_transfer->type[num]) {
		case CMD_VOLT: 
		case CMD_CURRENT: 
		    {
			b[num] = gp->p_transfer->b[num];
			srcs[num]->val = srcs[num]->start;
			b[num]->b_value[0] = srcs[num]->start;
			b[num]->b_value[1] = srcs[num]->start;
		    }
		    break;
		case CMD_SIN:
		case CMD_SINI:
		    {
			o[num] = (struct other_wavef_s *)
				gp->p_transfer->b[num];
			srcs[num]->val = srcs[num]->start;
			o[num]->o_value[0] = srcs[num]->start;
		}
	    }
}


restore_sources(gp, val_int, srcs)
register struct param_s *gp;	/* pointer main structure */
Val_Int *val_int;			/* pointer storage arrays */
struct transf_s **srcs;			/* pointer */
{

	struct boundary_s *b[3];	/* increment pointer */
	struct other_wavef_s *o[3];
	int i;

		/* Save old boundary source values */
		/* Initialize boundary sources */
	for(i=0; srcs[i] != NULL; i++) {
	    switch(gp->p_transfer->type[i]) {
		case CMD_VOLT: 
		case CMD_CURRENT: 
		    {
			b[i] = gp->p_transfer->b[i];
			b[i]->b_value[0] = srcs[i]->orig;
			b[i]->b_value[1] = srcs[i]->orig;
		    }
		    break;
		case CMD_SIN:
		case CMD_SINI:
		    {
			o[i] = (struct other_wavef_s *)
				gp->p_transfer->b[i];
			o[i]->o_value[0] = srcs[i]->orig;
		}
	    }
	}
}

/*
----------------------------------------------------------------------------
|  TRAN_RM_BOUND
|  Removes Vdd, GND, gnd if the user specifies these as input nodes
|
---------------------------------------------------------------------------
*/
/*
tran_rm_bound(node, gp)
struct transf_s *node;		
struct param_s *gp;
{
	struct boundary_s *bp, *prev_bp;

	prev_bp = NULL;
	for (bp = gp->p_boundary; bp != NULL; ) {
	    if (bp->b_node1 == node->node_num ) {
					 delete boundary info 
		if (prev_bp != NULL) {
		    prev_bp->b_next = bp->b_next;
		    bp = prev_bp->b_next;
		} else {
		    gp->p_boundary = bp->b_next;
		    bp = bp->b_next;
		}
	    } else {
		prev_bp = bp;
		bp = bp->b_next;
	    }
	}
}
*/

/*
----------------------------------------------------------------------------
|  LAMBDA_CALC
|  Calculate next lambda and u' for tranfer analysis 
|
---------------------------------------------------------------------------
*/
lambda_calc(gp, val_double, val_int)
struct param_s *gp;
Val_Double *val_double;
Val_Int *val_int;
{
	int num_ind, i;
	double sum1;
	double lmbdap;
	double *u, *y, *gl, *tu, *up;
	int *ju, *perm;

	up = val_double->fg; 		/* u' - was f(n + gamma) */
	gl = val_double->qi;		/* g(lambda) - was new Q's */
	u = val_double->u;		/* factored Jacobian array */
	tu = val_double->tu;		/* double scratch array */
	y = val_double->x;		/* euler direction - was x */
	ju = val_int->ju;		/* factored sparse matrix pointer */
	perm = val_int->perm;		/* permutation array */
	
	num_ind = gp->p_num_ind;
	i = 0;
	SNS(&num_ind, perm, ju, u, y, gl, tu, &i);

	sum1 = 0.0;
	for (i = 0; i< num_ind; i++)
  	    sum1 += y[i] * y[i];
	sum1 = sqrt(sum1) + 1.0;

		/* Assume that lambda is increasing !!! */
	lmbdap = 1.0 / sqrt(sum1);

	for (i = 0; i< num_ind; i++)
   	    up[i] = -lmbdap * y[i];

	val_double->lmbdap = lmbdap;
}
/*
------------------------------------------------------------
|     INITUP
|     Initialize u' and lambda' for transfer analysis
|
------------------------------------------------------------
*/
initup(gp,val_double,val_int)
struct param_s *gp;
Val_Double *val_double;
Val_Int *val_int;
{
	int num_ind, i;
	int ierror;
	int maxu;
	double lmbdap;
	double sum1, gunorm, damp;
	double *uo, *up, *gl, *a, *u, *tu, *y;
	int *ja, *ju, *perm, *list, *q;

	up = val_double->fg; 		/* u' - was f(n + gamma) */
	gl = val_double->qi;		/* g(lambda) - was new Q's */
	u = val_double->u;		/* factored Jacobian array */
	tu = val_double->tu;		/* double scratch array */
	y = val_double->x;		/* euler direction - was x */
	ju = val_int->ju;		/* factored sparse matrix pointer */
	perm = val_int->perm;		/* permutation array */
	uo = val_double->uo;		/* array of initial voltages */
	a = val_double->a;		/* Jacobian values */
	ja = val_int->ja;		/* sparse matrix pointer */
	list = val_int->list;		/* scratch array for sparse solve */
	q = val_int->q;			/* second integer scratch array */
	
	num_ind = gp->p_num_ind;
	val_int->type = TRANS;
	val_double->coef = 1.0;
					/* get space already allocated */
        lmbdap = val_double->lmbdap;
        maxu = val_int->maxu;
        gunorm = 1;
        damp = 0.1;

        assem(gp, val_double, val_int);

				/* Do sparse numeric factorization */
	i = 0;
	SNF(&num_ind, perm, ja, a, ju, u, &maxu, tu, &tu[num_ind],
     		list, q, &i, &ierror);

				/* Check for singularity of matrix */
				/* Should be okay from DC operating point */
	if (ierror != 0) {
	    deflat(a, gunorm, damp, num_ind);
	    SNF(&num_ind, perm, ja, a, ju, u, &maxu, tu, &tu[num_ind],
     		list, q, &i, &ierror);
	}

				/* Do sparse numeric solve of Gu y = gl */
	i = 0;
	SNS(&num_ind, perm, ju, u, y, gl, tu, &i);


				/* Compute u' and lambda' */
	sum1 = 0.0;
        for (i =0; i < num_ind; i++) 
  	    sum1 += y[i] * y[i];
	sum1 = sqrt(sum1) + 1.0;

				/* Assume that lambda is increasing !!! */
	lmbdap = 1.0 / sqrt(sum1);

        for (i =0; i < num_ind; i++) 
   	    up[i] = -lmbdap * y[i];
        val_double->lmbdap = lmbdap;
}

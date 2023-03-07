 
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
                    	Gary Nifong - MCNC
                    	Freda Locklear - Duke University
                    	Donald Erdman - Duke University
			Steve Kenkel - MCNC

	Copyright 1989, 1990 by the Microelectronics Center of North 
	Carolina, Don Erdman, and Don Rose.

        This copy, serial #00, of MCNC proprietary software, is made  
        available under license agreement.  Please heed all non-  
        disclosure and internal use restrictions.  
-----------------------------------------------------------------------------

	This file contains the routines used to parse the command line
	and the main routine which controls all subroutines.

----------------------------------------------------------------------------*/
#include <math.h>
#include "Hmain.h"
#include "Hcmd.h"
#include "sim.h"
#include "mod.h"
#include "sp.h"
#include "spcmd.h"

struct complex cmplxmult();
struct complex cmplxadd();
struct complex cmplxminus();

/*
---------------------------------------------------------------------------
|    AC_ANALYSIS()
|	Allocate memory for the FQ2 sparse matrix.
|	Then allocate the JF jacobian and call sparse_create.
|	Compute the DC operating point.
|	Free numerical arrays that are unnessary for AC analysis.
|	Call the SSF symbolic factorization routine.
|	Assemble the Jacobian for F2 and Q2 at the DC operating point.
|	Call the ac_solve routine.   
|
---------------------------------------------------------------------------
*/

ac_analysis(gp, val_double, val_int) 
Param *gp;
Val_Double *val_double;
Val_Int *val_int; 
{
	int *cz_irealloc();		/* integer realloc routine */
	int *jf;			/* sparse matrix for full matrix */

	int num_nodes;			/* number of nodes in circuit */
	int num_ind;			/* number of non_boundary nodes */

	
					/* gnd and global gnd are removed */
					/* both as nodes and current rows */
	num_nodes = gp->p_num_nodes - NUM_GNDS;
	num_ind = gp->p_num_ind;

	jf = (int *) sim_calloc(num_nodes * 11, sizeof(int), S_CAZM);
	val_int->jf = jf;

        			/* set up sparse matrix pointer for F1 and Q1
				 * using the old "u" and "a" arrays
				 */	
	val_double->F = val_double->a;
	val_double->Q = val_double->u;


				/* compute DC operating point if the 
				 * dcoppt command was not specified.
				 */
	if (gp->p_dcoppt == NULL)
	    dc_front(gp, val_double, val_int, FALSE);

				/* Free some useless erdman arrays */
	sim_free((char *)val_double->uo, S_CAZM);
	sim_free((char *)val_double->umid, S_CAZM);
	sim_free((char *)val_double->fo, S_CAZM);
	sim_free((char *)val_double->fg, S_CAZM);
	sim_free((char *)val_double->fi, S_CAZM);
	sim_free((char *)val_double->qo, S_CAZM);
	sim_free((char *)val_double->qg, S_CAZM);
	sim_free((char *)val_double->qi, S_CAZM);
	sim_free((char *)val_double->x, S_CAZM);
	sim_free((char *)val_double->gu, S_CAZM);
	sim_free((char *)val_double->cont, S_CAZM);


				/* assemble F Q */
	val_int->type = AC;
	val_double->coef = 1.0;
	val_int->jasize = num_ind;
	assem(gp, val_double, val_int);

					/* call sparse create  and build
					 * the jf jacobian matrix
					 */
	val_int->jasize = num_nodes;
	sparse_create(gp, val_int, jf, AC);
	if (jf[num_nodes] >  num_nodes * 11) {
	        sim_error(S_FATAL, S_CAZM, 
		   "jf allocation error %d, %d", jf[num_nodes], num_nodes*11);
	}


	val_double->F2 = (double *)
	sim_calloc(jf[num_nodes] * 2 - num_nodes + 2, sizeof(double), S_CAZM);
					/* allocate space for non zeros */
	val_double->Q2 = (double *)
	sim_calloc(jf[num_nodes] * 2 - num_nodes + 2, sizeof(double), S_CAZM);

				/* reallocate jf (don't trust realloc) 
				 * and store the pointer
				 */
	if (gp->p_linear_equ == GAUSS) 
	    jf = cz_irealloc(jf,jf[num_nodes]* 2 - num_nodes);
	val_int->jf = jf;

					/* reset variables */
					/* assemble full Jacobian matrices 
					 * for F2 and Q2 at the dc operating
					 * point
					 */
	assem(gp, val_double, val_int);

					/* Print AC STATS */
	ac_printmodel(gp, val_double, val_int);

					/* Solve the set of matrices for
					 * different frequencies.
					 */
	ac_solve(gp, val_double, val_int); 

}

/*
---------------------------------------------------------------------------
|    AC_SOLVE()
|	Allocate complex arrays:
|		a[]	AC voltages.
|		ia[]	AC currents.
|		b[]	Right hand vector.
|		z[]	Solution vector.
|
|	Compute b[] by adding  b[] = a[] - ia[]
|	Compute fq2[] by adding fq2 = [F2 + jwQ2] 
|	Then solve for z[] for each frequency:
|		[fq2][z] = b[]
|
---------------------------------------------------------------------------
*/
ac_solve(gp, val_double, val_int) 
Param *gp;
Val_Double *val_double;
Val_Int *val_int; 
{
	struct main_ac_s *ac;
	struct factored_s *fact;

        int i;
	int m;
        int flag;
        int num_nodes, num_ind;
	int *jf, *ja, *ju;
	int h, h2, len, len2;
	int loopcount;
	int vsrc_cnt;

	double fstart,fstop;
        double freq, finc;
        double decades;
        double fmult;
	double *vmag;			/* input voltage magnitudes */
	double *vphase;			/* input voltage phase shifts */
	double *imag;			/* current magnitudes */
	double *iphase;			/* current phase shifts */
        double *f, *q; 
        double *f2, *q2; 
	double jw;
	double max_real_diag;


				/* compute b[]:
				 *	b = -[a] - [ai] 
				 *  then solve for vector z[]:
				 *	[fq2][z] = b[]
				 */
	struct complex *fq;		/* large right complex conductance */
	struct complex *fq2;		/* large right complex conductance */
	struct complex *a;	 	/* the complex voltage input array */
	struct complex *ia; 		/* the complex current input array */
	struct complex *b;		/* the combined current vector */
	struct complex *z;		/* the computed voltage vector */
	struct complex cx;
	struct complex *rhs;
	struct complex *tmp;


	struct complex *u, *tu;
	struct polar *vmp, *imp;

	ac = gp->p_ac;
	num_nodes = val_int->jasize;
	num_ind = gp->p_num_ind;

	/*
	printf("Independent nodes = %d\n", num_ind);
	printf("Total       nodes = %d\n", num_nodes);
	*/

	ja = val_int->ja;
	jf = val_int->jf;
	ju = val_int->ju;

			/* Allocate complex scratch matrices */
	u  =  (struct complex *)
		sim_calloc((ju[num_ind] * 2 - num_ind + 1),
			sizeof(struct complex), S_CAZM);
	tu =  (struct complex *)
		sim_calloc(((3 * num_ind) + 1),
			sizeof(struct complex), S_CAZM);

	f = val_double->F;
	q = val_double->Q;
	f2 = val_double->F2;
	q2 = val_double->Q2;
					/* count the number of voltage */
                                        /* sources */
	vsrc_cnt = 0;
        for (fact = gp->p_fact; fact != NULL; fact = fact->f_next)
            vsrc_cnt++;

			/* find the maximum real diagonal value */
			/* assumes they are positive */
	max_real_diag = 1.0e-3;
	for (i = 0 ; i < num_ind; i++)
	    if ( max_real_diag < f[i])
		max_real_diag = f[i];

	max_real_diag *= 1.0e-10;

	fq =  (struct complex *)
		sim_calloc((ja[num_ind] * 2) - num_ind + 2,
			sizeof(struct complex), S_CAZM);
	fq2 =  (struct complex *)
		sim_calloc((jf[num_nodes] * 2) - num_nodes + 2,
			sizeof(struct complex), S_CAZM);


	a = (struct complex *) sim_calloc(num_nodes + vsrc_cnt, 
		sizeof(struct complex), S_CAZM);
	ia = (struct complex *) sim_calloc(num_nodes + vsrc_cnt, 
		sizeof(struct complex), S_CAZM);
	b = (struct complex *) sim_calloc(num_nodes + vsrc_cnt, 
		sizeof(struct complex), S_CAZM);
	z = (struct complex *) sim_calloc(num_nodes + vsrc_cnt, 
		sizeof(struct complex), S_CAZM);

		/* allocate vector of magnitudes and phases for
		 * the voltage and current inputs
		 */
	vmp = (struct polar *) sim_calloc((num_nodes + 1 + vsrc_cnt), 
		sizeof(struct polar), S_CAZM);
	tmp = (struct complex *) vmp;
	imp = (struct polar *) sim_calloc((num_nodes + 1 + vsrc_cnt), 
		sizeof(struct polar), S_CAZM);
	rhs = (struct complex *) imp;


			/* initialize mag and phase vectors */
	create_phmag(gp, vmp, imp);

		/*    calculate complex a from amplitude and phase shift 
		 *    convert delta array from degrees to radians
		 */
	polar2cmplx_array(vmp,a,num_nodes+vsrc_cnt,val_double->pi);
	polar2cmplx_array(imp,ia,num_nodes+vsrc_cnt,val_double->pi);
	

	fstart = ac->fstart;
	fstop  = ac->fstop; 

		/* Check frequency ranges */
	if(fstop == ZEROSET) {
		/* Set INC to fstart, Linear increments */ 
	    loopcount = ac->num;
	    finc = fstart;
	}
	else if(fstop == fstart) {
		/* Only one count */ 
	    loopcount = 1;
	    finc = 0.0;
	}
	else {
	    if ( ac->type == SPCMD_LIN) {
		if(ac->num > 1) {  
		    finc = (fstop - fstart) / (ac->num - 1);
		    loopcount = ac->num ;
		}
		else {
		    finc = fstart;
		    loopcount = 1;
		}
	    }
	    else if ( ac->type == SPCMD_DEC) {
		fmult = pow(10.0,(1.0/(double)ac->num));
		finc = (fstart * fmult) - fstart;
		decades = ceil((log(fstop) - log(fstart))/log(10.0));
		if(decades < 1)
		    decades = 1.0;
		loopcount = (decades * ac->num) + 1;
	    }
	    else if ( ac->type == SPCMD_OCT) {
		fmult = pow(2.0,(1.0/(double)ac->num));
		finc = (fstart * fmult) - fstart;
		decades = ceil((log(fstop) - log(fstart))/log(2.0));
		if(decades < 1)
		    decades = 1.0;
		loopcount = (decades * ac->num) + 1;
	    }
	}
	if(loopcount < 1) {
	    loopcount = 1;
	    finc = 0.0;
	}

		/* set some loop variables */
	freq = fstart;
	h = ja[num_ind] - ja[0];
	len = num_ind + (2 * h) +1;
	h2 = jf[num_nodes] - jf[0];
	len2 = num_nodes + (2 * h2) +1;

				/* Print an AC file header */
	ac_printheader(gp);

	/*
		 Print the node names 
	for( i=0; i < num_ind; i++) {
		printf("%s\t", node_names[i]);
	}
	*/

	for ( m = 0; m < loopcount; m++) {

		/* Compute the jw multiplying term  */
		jw = 2.0 * val_double->pi * freq;

		/*   Create fq2 = [F2 + jwQ2] */
		cmplxfq(fq, f, q, jw, len);

		/*   Create fq2 = [F2 + jwQ2] */
		cmplxfq(fq2, f2, q2, jw, len2);

		/* Add the transmission line to fq1 and fq2 */ 
		ac_transmission_assem(gp, val_double, val_int,
			fq, fq2, freq); 

			    /* store "h" at FQ2[n+1] = number of
			     * non-zero off diagonals on the upper
			     * triangle of FQ2
			     */
		fq2[num_nodes].real = h2;


		/*
		printcmplx(fq2, jf, num_nodes, "FQ2");
		printcmplxarray(a, num_nodes, "A");
		*/
			    /* Clear the B complex array */
		for (i = 0; i < num_nodes+vsrc_cnt; i++) {
			b[i].real = 0.0;
			b[i].imag = 0.0;
		}

			    /* add in the AC current vector */
		for (i = 0; i < num_nodes+vsrc_cnt; i++) 
			b[i] = cmplxminus(a[i],ia[i]);

		/*
		printcmplxarray(b, num_nodes + vsrc_cnt, "B");
		*/

		/*  Do factor and solve for voltage vector */
		/*  Factor fq1 and solve [fq1][z] = [b] */
		solve_ac_system(gp, val_double, val_int, z, b, tmp,
			u, tu, fq, fq2, max_real_diag);

		/*
		printcmplxarray(z, num_nodes + vsrc_cnt, "Z");
		*/

		ac_output(gp, val_double, val_int, z, ia, fq2, freq);

		if (ac->type == SPCMD_LIN)
		    freq += finc;
		else {
				/* Modify finc if DEC or OCT */
		    finc = (freq * fmult) - freq;
		    freq += finc;
		}
	}
	if (gp->p_csdf) fprintf(gp->p_plot->fd, "#;\n");
}

/*
---------------------------------------------------------------------------
|    CREATE_PHMAG()
|	Create the arrays of polar voltages and currents.
|	Save the AC voltage in the row stored in the boundary structure.
|
---------------------------------------------------------------------------
*/
create_phmag(gp, vmp, imp)
Param *gp;
struct polar *vmp;
struct polar *imp;
{
	struct ac_volt_s *acv;		/* small signal voltage input */
	struct ac_curr_s *acc;		/* small signal current input */ 
	struct boundary_s *b;
	struct main_ac_s *ac;		/* AC structure pointer */ 
	int node1, node2;
	int row;
	int i;

	ac = gp->p_ac;

					/* Small signal voltage input */
	if (gp->p_ac_volt != NULL ) {
	    for (acv = gp->p_ac_volt; acv != NULL; acv = acv->next) {
		    if(acv->b_ptr != NULL)
			row = acv->b_ptr->b_row;
		    else if(acv->o_ptr != NULL)
			row = acv->o_ptr->o_row;

		    vmp[row].mag = acv->acmag;
		    vmp[row].deg = acv->acphase;
	    }	
	}
					/* Small signal current input */
	if (gp->p_ac_curr != NULL ) {
	    for (acc = gp->p_ac_curr; acc != NULL; acc = acc->next) {
		if (acc->node_num1 < gp->p_num_nodes -NUM_GNDS) {
		    imp[acc->node_num1].mag = acc->acmag;
		    imp[acc->node_num1].deg = acc->acphase;
		}
		if (acc->node_num2 < gp->p_num_nodes -NUM_GNDS) {
		    imp[acc->node_num2].mag = -acc->acmag;
		    imp[acc->node_num2].deg = acc->acphase;
		}
    	    }
	}

        if (gp->p_ac_volt == NULL  && gp->p_ac_curr == NULL)
	    sim_error(S_FATAL, S_CAZM, "Missing small-signal input");
}


add_acvolt(gp, node1, node2, name, acmag, acphase, b_ptr, o_ptr)
Param *gp;
int node1, node2;
char *name;
double acmag, acphase;
struct boundary_s *b_ptr;
struct other_wavef_s *o_ptr;
{
	struct ac_volt_s *ac_volt_t;    /* tail of the ac volt list */

	ac_volt_t = (struct ac_volt_s *)     
		sim_alloc(sizeof(struct ac_volt_s), S_CAZM); 
	ac_volt_t->node_num1 = node1;
	ac_volt_t->node_num2 = node2;

	if (acmag == ZEROSET)
	    ac_volt_t->acmag = 0.0;
	else
	    ac_volt_t->acmag = acmag;

	if (acphase == ZEROSET)
	    ac_volt_t->acphase = 0.0;
	else
	    ac_volt_t->acphase = acphase;

				/* add to head of linked list */
	ac_volt_t->next = gp->p_ac_volt;		
	gp->p_ac_volt = ac_volt_t;

		/* Store the source structure pointer */
	ac_volt_t->b_ptr = b_ptr;
	ac_volt_t->o_ptr = o_ptr;
}

add_accur( gp, node1, node2, name, acmag, acphase)
Param *gp;
int node1, node2;
char *name;
double acmag, acphase;
{
	struct ac_curr_s *ac_curr_t;    /* tail of the ac current list */

	ac_curr_t = (struct ac_curr_s *)     
		sim_alloc(sizeof(struct ac_curr_s), S_CAZM); 
	ac_curr_t->node_num1 = node1;
	ac_curr_t->node_num2 = node2;

	if (acmag == ZEROSET)
	    ac_curr_t->acmag = 0.0;
	else
	    ac_curr_t->acmag = acmag;

	if (acphase == ZEROSET)
	    ac_curr_t->acphase = 0.0;
	else
	    ac_curr_t->acphase = acphase;

				/* add to head of linked list */
	ac_curr_t->next = gp->p_ac_curr;		
	gp->p_ac_curr = ac_curr_t;
}
 
/*
---------------------------------------------------------------------------
|
|	POLAR2CMPLX()
|
|	    converts a set of vectors from polar to complex notation
|
---------------------------------------------------------------------------
*/
polar2cmplx_array(vmp, a, num, pi)
struct polar *vmp;
struct complex *a;
int num;
double pi;
{
	int i;

					/* Convert degrees to radians */
	for (i = 0; i < num; i++) {
	   a[i].real = vmp[i].mag * cos((pi*vmp[i].deg)/180.0);
	   a[i].imag = vmp[i].mag * sin((pi*vmp[i].deg)/180.0);
	}
	
}

/*
---------------------------------------------------------------------------
|
|	CMPLXCLEAN()
|
|	    Zero's the real or imaginary part of the complex number that
|	is very small relative to it's counterpart.
|
---------------------------------------------------------------------------
*/
struct complex 
cmplxclean( a)
struct complex a;
{
		/* Zero insignificant imaginary */
	if(fabs(a.real) > fabs(1.0e+14 * a.imag))
		a.imag = 0.0;

		/* Zero insignificant real */
	if(fabs(a.imag) > fabs(1.0e+14 * a.real))
		a.real = 0.0;

	return(a);
}

/*
---------------------------------------------------------------------------
|
|	CMPLX2POLAR()
|
|	    converts a single vector from complex to polar notation
|
---------------------------------------------------------------------------
*/
struct polar
cmplx2polar(a, pi)
struct complex a;
double pi;
{

	struct polar p;
	double arc;

	if(a.real == 0.0 && a.imag == 0.0)
	    arc = 0.0;
	else if(a.real == 0.0) {
	    if(a.imag < 0.0)
		arc = -pi/2.0;
	    else if(a.imag > 0.0)
		arc = pi/2.0;
	}
	else if(a.imag == 0.0)
	    arc = 0.0;
	else
	    arc = atan(a.imag/a.real);

				/* fix the arctan quadrant */
	if((a.imag >= 0.0 && a.real >= 0.0) || (a.imag <= 0.0 && a.real >= 0.0))
	    p.deg = (180.0 * arc)/pi;
	else if( a.imag >= 0.0 && a.real < 0.0 )
	    p.deg = (180.0 * arc)/pi + 180;
	else if( a.imag < 0.0 && a.real < 0.0 )
	    p.deg = (180.0 * arc)/pi - 180;

	p.mag = sqrt( (a.real * a.real) + (a.imag * a.imag) );

	return(p);
}

cmplxfq(fq, f, q, jw, num)
struct complex *fq;
double *f;
double *q;
double jw;
int num;
{
	int i;

	for (i = 0; i <= num; i++) {
	    fq[i].real = f[i]; 
	    fq[i].imag = jw * q[i];
	}
}

	
struct complex
cmplxminus( x, y)
struct complex x;
struct complex y;
{
	struct complex a;

	a.real = x.real - y.real;
	a.imag = x.imag - y.imag;
	return(a);
}

struct complex
cmplxadd( x, y)
struct complex x;
struct complex y;
{
	struct complex a;

	a.real = x.real + y.real;
	a.imag = x.imag + y.imag;
	return(a);
}

struct complex
cmplxmult( x, y)
struct complex x;
struct complex y;
{
	struct complex a;

	a.real = (x.real * y.real) - (x.imag * y.imag);
	a.imag = (x.real * y.imag) + (y.real * x.imag);

	return(a);
}

struct complex
cmplxdivide(x, y)
struct complex x;
struct complex y;
{
	struct complex a;
	double denom;
	
	denom = (y.real * y.real) + (y.imag * y.imag);

	if(denom == 0.0) {
		a.real = 0.0;
		a.imag = 0.0;
	}
	else {

	    a.real = ((x.real * y.real) + (x.imag * y.imag)) / denom;
	    a.imag = ((x.imag * y.real) - (x.real * y.imag)) / denom;
	}

	return(a);
}

struct complex 
cmplxvectmult( x, y, num)
struct complex *x;
struct complex *y;
int num;
{
	struct complex a;
	int i;

	a.real = 0.0;
	a.imag = 0.0;
	
	for(i=0; i< num; i++) {
	    a.real += (x[i].real * y[i].real) - (x[i].imag * y[i].imag);
	    a.imag += (x[i].real * y[i].imag) + (y[i].real * x[i].imag);
	}

	return(a);

}



/*
----------------------------------------------------------------
|     PRINT_CMPLX
|     Print the complex jacobian matrix.
|
----------------------------------------------------------------
*/
printcmplx(a, ja, num, s)
struct complex *a;
int *ja;
int num;
char *s;
{
	int i;
	int j,k, h;
	double zero=0.0;

	h = a[num].real;
        fprintf(stderr," printing complex matrix %s \n", s);
        fprintf(stderr," h = %d\n", h);


	for (i = 0 ; i< num; i++) {
	    for (j = 0; j < num; j++)
		if ( i == j ) 
		    fprintf(stderr,"(%10.3e, %10.3e) ", a[j].real,a[j].imag);
		else 
		if ( j > i) { 
		    for (k = ja[i]; (k < ja[i+1])  && ja[k - 1] != j+1; k++);
		    if ( ja[k - 1] == j+1 && k < ja[i+1])
			fprintf(stderr,"(%10.3e, %10.3e) ",
				a[k-1].real,a[k-1].imag);
		    else
			fprintf(stderr,"(%2.1g, %2.1g) ", zero, zero);
			
		} else {
		    for (k = ja[j]; (k < ja[j+1]) && ja[k -1] != i+1; k++);
		    if ( ja[k-1] == i+1 && k < ja[j+1])
			fprintf(stderr,"(%10.3e, %10.3e) ",
				a[k + h-1].real,a[k+h-1].imag);
		    else
			fprintf(stderr,"(%2.1g, %2.1g) ", zero, zero);
		}
		fprintf(stderr,"\n");
	}
	fprintf(stderr,"\n");
}

printcmplxarray(a, num, s)
struct complex *a;
int num;
char *s;
{
	int i;

        fprintf(stderr," printing complex array %s \n", s);
	for (i = 0; i < num; i++)
		fprintf(stderr,"(%g, %g) ", a[i].real, a[i].imag);
	fprintf(stderr,"\n");
	fprintf(stderr,"\n");

}
/*
----------------------------------------------------------------
|     SOLVE_AC_SYSTEM
|     The system is solved sans the voltage sources. See the
|     technical report on this topic for more details.
|
----------------------------------------------------------------
*/
solve_ac_system( gp, val_double, val_int, z, b, tmp, u, tu, fq, fq2, max_real_diag)
struct param_s *gp;
Val_Double *val_double;
Val_Int * val_int;
struct complex *z;
struct complex *b;
struct complex *tmp;
struct complex *u;
struct complex *tu;
struct complex *fq, *fq2;
double max_real_diag;
{
	struct factored_s *f;
	int flag, ierror;
	int i,j;
	int num_nodes;
	int num_ind;
	int *jf, *ju, *perm;
	int *ja;
	int maxju;
	int *list, *q; 

	perm = val_int->perm;
	list = val_int->list;
	ju   = val_int->ju;
	q    = val_int->q;
	ja    = val_int->ja;
	jf    = val_int->jf;
	ju    = val_int->ju;
	num_ind = gp->p_num_ind;
	num_nodes = val_int->jasize;
	maxju = ju[num_ind] * 2 - num_ind + 1;
				/* have the pay the price for not pivoting */
	for (i = 0; i < num_ind; i++) {
	     if (fq[i].real == 0.0 && fq[i].imag == 0.0)
                  fq[i].real += max_real_diag;
	}

	flag = 0;
	CSNF(&num_ind, perm, ja, fq, ju, u,
			&maxju, tu, &tu[num_ind], list, q, &flag, &ierror);

	if (ierror != 0) {
				/* have the pay a heavier price */
		max_real_diag *=100;
		for (i = 0; i < num_ind; i++) {
		    fq[i].real += max_real_diag;
		}

		flag = 0;
		CSNF(&num_ind, perm, ja, fq, ju, u,
			&maxju, tu, &tu[num_ind], list, q, &flag, &ierror);

		if (ierror != 0) {
	            sim_error(S_FATAL, S_CAZM, 
			"Complex factor and solve failed!");
	    	    exit(ierror);
		}
	}

	for (i = 0; i < num_nodes; i++) {
	     tu[i].real = 0.0;
	     tu[i].imag = 0.0;
	}
			/* set up "x" to generate current input from voltages */
			/* propagate voltages */
	prop_volt(tu, b, gp->p_fact_rev, num_nodes);
	for (i = 0; i < num_ind; i++) {
	     tu[i].real = 0.0;
	     tu[i].imag = 0.0;
	}

			/* generate voltage source current input*/
	gen_vsrc_curr(fq2, jf, num_nodes, num_ind, tmp, tu);
/*
printcmplxarray(tmp, num_nodes, "voltage source currents");
*/

	for (i = 0; i < num_nodes; i++) 
	     tmp[i] = cmplxminus(b[i],tmp[i]);

			/* propagate currents */
	prop_curr(tmp, gp->p_fact);
		
/*
printcmplxarray(tmp, num_nodes, "tmp propagated currents");
*/

			/* solve FQ z = b */
	CSNS(&num_ind, perm, ju, u, z, tmp, tu, &flag);

/*
printcmplxarray(z, num_ind, "z after solve ");
*/
			/* propagate voltages */
	prop_volt(z, b, gp->p_fact_rev, num_nodes);
		
/*
printcmplxarray(z, num_nodes, "z after propagated ");
*/

			/* generate voltage source current solution */
	gen_vsrc_curr(fq2, jf, num_nodes, num_ind, tmp, z);

	for (i = 0; i < num_nodes; i++) 
	     tmp[i] = cmplxminus(b[i],tmp[i]);
/*
printcmplxarray(tmp, num_nodes, "tmp after current");
*/

			/* propagate currents */
	prop_curr(tmp,  gp->p_fact);

/*
printcmplxarray(tmp, num_nodes, "tmp after propagating current");
*/
			/* store the currents */
	j = num_nodes;
	for (f = gp->p_fact; f != NULL; f = f->f_next) {
	     if (*f->node1 == *f->node2)
		continue;
	     z[j].real = -tmp[*f->node1].real;
	     z[j].imag = -tmp[*f->node1].imag;
	     j++;
	}
/*
printcmplxarray(z, j, "z final ");
*/
}
/*
--------------------------------------------------------------------
|  GEN_VSRC_CURR
|  A v = tmp
|
|
--------------------------------------------------------------------
*/
gen_vsrc_curr(a, ja, num_nodes, num_ind, tmp, x)
struct complex *a;
int *ja;
int num_nodes, num_ind;
struct complex *tmp;
struct complex *x;
{
	int i, j, k, h;

                /*  multiply the diagonals of a */
        for (i = 0; i < num_nodes; i++)
            tmp[i] = cmplxmult(a[i],x[i]);

                /*  now multiply off diagonals */
        h = ja[num_nodes] - ja[0];
        for (i = 0; i < num_nodes; i++) {
            for (j = ja[i]-1; j < ja[i+1]-1; j++) {
                k = ja[j] - 1;
                tmp[i] = cmplxadd(tmp[i], cmplxmult(a[j] , x[k]));
                tmp[k] = cmplxadd(tmp[k], cmplxmult(a[j + h] , x[i]));
            }
        }
}
/*
--------------------------------------------------------------------
|  PROP_CURR
|  Propagate currents across voltage sources 
|
--------------------------------------------------------------------
*/
prop_curr(tmp, f)
struct complex *tmp;
struct factored_s *f;
{
	for (f ; f != NULL; f = f->f_next) {
	     if (*f->node1 == *f->node2)
		continue;
	     tmp[*f->node2] = cmplxadd(tmp[*f->node2], tmp[*f->node1]);
	}
}
/*
--------------------------------------------------------------------
|  PROP_VOLT
|  Propagate voltages across voltage sources 
|
--------------------------------------------------------------------
*/
prop_volt(z, b, f, num_nodes)
struct complex *z;
struct complex *b;
struct factored_s *f;
int num_nodes;
{
	int row;
	
	for (f ; f != NULL; f = f->f_prev) {
	     if (*f->node1 == *f->node2)
		continue;
	     row = *f->row;
	     if (*f->node2 < num_nodes) 
	         z[*f->node1] = cmplxadd(b[row], z[*f->node2]);
	     else
	         z[*f->node1] = b[row];
	}
}

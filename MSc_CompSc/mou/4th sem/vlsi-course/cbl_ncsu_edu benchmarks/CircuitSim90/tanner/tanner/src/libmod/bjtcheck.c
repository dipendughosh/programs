/****************************************************************************

    =========       ========        ===========    ===== =======   =======
   ==      ===     ===     ==       ==     ===        ===     === =     ===
  ==       ===     ===   =====      =     ===         ==       ===       ===
  ==               =====   ===          ===           ==       ===       ===
  ==              ===      ===         = =    =       ==       ===       ===
   ==        =    ===      ===       ===      =       ==       ===       ===
    =========      ======== ====    ===========    =======   =======  =======

*****************************************************************************

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
******************************************************************************/

/*###########################################################################

	This file contains initialisation and precomputing for the 
	Spice BJT model.

###########################################################################*/
#include	<ctype.h>
#include	<math.h>
#include	"sim.h"
#include	"sp.h"
#include	"newmod.h"

/* MOD_BJT_SETUP() - The following code implements SPICE model parameter
 *		setup, check parameter validity, sets defaults, and
 *		calculates missing parameter values.
 */

struct mod_bjtmodel_s *
mod_bjt_setup(sp, temp)

struct sp_bjtmodel_s *sp;
double temp;			/* Temperature in degrees centigrate */

{
	register struct mod_bjtmodel_s *mp;

	/* Allocate compute model structure */
	mp = (struct mod_bjtmodel_s *)
		sim_alloc(sizeof(struct mod_bjtmodel_s),S_MOD);

	if (sp == (struct sp_bjtmodel_s *) NULL) {
		sim_error(S_FATAL, S_MOD,
			"\t BJT model is NULL!\n"); 
		exit(1);
	}

	/* transfer model name and model type */

	strcpy(mp->modelname, sp->modelname);
	mp->modeltype = sp->modeltype;

	/* Check type of model */
	if (mp->modeltype == SP_NPNTYPE )
		mp->sign = NPN_SIGN;
	else if (mp->modeltype == SP_PNPTYPE )
		mp->sign = PNP_SIGN;
	else {
		sim_error(S_FATAL, S_MOD,
			"\tIllegal BJT type !\n"); 
		exit(1);
	}
	
	mod_bjt_check(sp, mp, temp);

	mod_bjt_model_compute(mp);

	return(mp);
}



/* MOD_BJT_CHECK() - The following code implements SPICE model parameter
 *		checking, sets defaults, and reports missing
 *		parameter values.
 */

mod_bjt_check(sp, mp, temp)

struct sp_bjtmodel_s *sp;
struct mod_bjtmodel_s *mp;
double temp;

{

	/* Check if optional parameters for Gummel-Poon are specified */

	if((sp->c2 == ZEROSET) || (sp->c2 == 0.0))
		mp->mod_c2_given = MOD_FALSE;
	else {
		mp->mod_c2_given = MOD_TRUE;
		mp->c2 = sp->c2;
	}

	if((sp->c4 == ZEROSET) || (sp->c4 == 0.0))
		mp->mod_c4_given = MOD_FALSE;
	else {
		mp->mod_c4_given = MOD_TRUE;
		mp->c4 = sp->c4;
	}

	if((sp->vaf == ZEROSET) || (sp->vaf == 0.0))
		mp->mod_vaf_given = MOD_FALSE;
	else {
		mp->mod_vaf_given = MOD_TRUE;
		mp->vaf = sp->vaf;
	}


	if((sp->var == ZEROSET) || (sp->var == 0.0))
		mp->mod_var_given = MOD_FALSE;
	else {
		mp->mod_var_given = MOD_TRUE;
		mp->var = sp->var;
	}

	if((sp->ikf == ZEROSET) || (sp->ikf == 0.0))
		mp->mod_ikf_given = MOD_FALSE;
	else {
		mp->mod_ikf_given = MOD_TRUE;
		mp->ikf = sp->ikf;
	}


	if((sp->ikr == ZEROSET) || (sp->ikr == 0.0))
		mp->mod_ikr_given = MOD_FALSE;
	else {
		mp->mod_ikr_given = MOD_TRUE;
		mp->ikr = sp->ikr;
	}

	if(sp->ise == ZEROSET)
		mp->mod_ise_given = MOD_FALSE;
	else {
		mp->mod_ise_given = MOD_TRUE;
		mp->ise = sp->ise;
	}


	if(sp->isc == ZEROSET)
		mp->mod_isc_given = MOD_FALSE;
	else {
		mp->mod_isc_given = MOD_TRUE;
		mp->isc = sp->isc;
	}


	if((sp->vtf == ZEROSET) || (sp->vtf == 0.0))
		mp->mod_vtf_given = MOD_FALSE;
	else {
		mp->mod_vtf_given = MOD_TRUE;
		mp->vtf = sp->vtf;
	}
	if(sp->rbm == ZEROSET) {
		mp->mod_rbm_given = MOD_FALSE;
		mp->rbm = mp->rb;
	} else {
		mp->mod_rbm_given = MOD_TRUE;
		mp->rbm = sp->rbm;
	}
	if(sp->rb == ZEROSET)
		mp->rb = 0.0;
	else
		mp->rb = sp->rb;


	if((sp->irb == ZEROSET) ) {
		mp->mod_irb_given = MOD_FALSE;
	} else 
        if (sp->irb == 0) {
			/* Using very complex things like L'hospital rule */
			/* and algebra, the high current base resistor */
			/* becomes a constant resistor of value rbm */
		mp->mod_irb_given = MOD_FALSE;
		mp->rb = mp->rbm;
	} else {
	
		mp->mod_irb_given = MOD_TRUE;
		mp->irb = sp->irb;
	}





	/*  Set default values as specified in "SPICE Version 
	 *  2G User's Guide" for unspecified parameters.
	 */

	if(sp->is == ZEROSET)
		mp->is = 1.0e-16;
	else
		mp->is = sp->is;

	if(sp->bf == ZEROSET)
		mp->bf = 100.0;
	else
		mp->bf = sp->bf;

	if(sp->nf == ZEROSET)
		mp->nf = 1.0;
	else
		mp->nf = sp->nf;

	if(sp->ne == ZEROSET)
		mp->ne = 1.5;
	else
		mp->ne = sp->ne;

	if(sp->br == ZEROSET)
		mp->br = 1.0;
	else
		mp->br = sp->br;

	if(sp->nr == ZEROSET)
		mp->nr = 1.0;
	else
		mp->nr = sp->nr;

	if(sp->nc == ZEROSET)
		mp->nc = 2.0;
	else
		mp->nc = sp->nc;

	if(sp->re == ZEROSET)
		mp->re = 0.0;
	else
		mp->re = sp->re;

	if(sp->rc == ZEROSET)
		mp->rc = 0.0;
	else
		mp->rc = sp->rc;

	if(sp->cje == ZEROSET)
		mp->cje = 0.0;
	else
		mp->cje = sp->cje;

	if(sp->vje == ZEROSET)
		mp->vje = 0.75;
	else
		mp->vje = sp->vje; 

	if(sp->mje == ZEROSET)
		mp->mje = 0.33;
	else
		mp->mje = sp->mje;

	if(sp->tf == ZEROSET)
		mp->tf = 0.0;
	else
		mp->tf = sp->tf;

	if(sp->xtf == ZEROSET)
		mp->xtf = 0.0;
	else
		mp->xtf = sp->xtf;

	if(sp->itf == ZEROSET)
		mp->itf = 0.0;
	else
		mp->itf = sp->itf;

	if(sp->ptf == ZEROSET)
		mp->ptf = 0.0;
	else
		mp->ptf = sp->ptf;

	if(sp->cjc == ZEROSET)
		mp->cjc = 0.0;
	else
		mp->cjc = sp->cjc;

	if(sp->vjc == ZEROSET)
		mp->vjc = 0.75;
	else
		mp->vjc = sp->vjc; 

	if(sp->mjc == ZEROSET)
		mp->mjc = 0.33;
	else
		mp->mjc = sp->mjc;

	if(sp->xcjc == ZEROSET)
		mp->xcjc = 1.0;
	else
		mp->xcjc = sp->xcjc;

	if(sp->tr == ZEROSET)
		mp->tr = 0.0;	
	else
		mp->tr = sp->tr;

	if(sp->cjs == ZEROSET)
		mp->cjs = 0.0;
	else
		mp->cjs = sp->cjs;

	if(sp->vjs == ZEROSET)
		mp->vjs = 0.75;
	else
		mp->vjs = sp->vjs;

	if(sp->mjs == ZEROSET)
		mp->mjs = 0.0;
	else
		mp->mjs = sp->mjs;

	if(sp->xtb == ZEROSET)
		mp->xtb = 0.0;	
	else
		mp->xtb = sp->xtb;

	if(sp->eg == ZEROSET)
		mp->eg = 1.1;
	else
		mp->eg = sp->eg;

	if(sp->xti == ZEROSET)
		mp->xti = 3.0;
	else
		mp->xti = sp->xti;

	if(sp->kf == ZEROSET)
		mp->kf = 0.0;
	else
		mp->kf = sp->kf;

	if(sp->af == ZEROSET)
		mp->af = 1.0;
	else
		mp->af = sp->af;

	if(sp->fc == ZEROSET)
		mp->fc = 0.5;
	else
		mp->fc = sp->fc;

	if (sp->subs == ZEROSET) {
	    if (mp->modeltype == SP_NPNTYPE )
		mp->subs = 1;
	    else
		mp->subs = -1;
	} else
	    mp->subs = sp->subs;

	if(temp == ZEROSET)
		mp->tnew = 27.0;
	else
		mp->tnew = temp;

	/* Set reference temperature */
	mp->tref = 27.0;


	/* The following parameters are not used in the
	 * BJT model.
	 */
	if(sp->ptf != ZEROSET)
		mod_bjt_nouse("PTF");	/* not used */
	if(sp->kf != ZEROSET)
		mod_bjt_nouse("KF");	/* not used */
	if(sp->af != ZEROSET)
		mod_bjt_nouse("AF");	/* not used */
	
}

mod_bjt_nouse(param)
char *param;
{
	sim_error(S_WARNING, S_MOD,
		"\tParameter %s is not used in the BJT model.\n", param); 
}


mod_bjt_error(param)
char *param;
{
	sim_error(S_WARNING, S_MOD,
		"\tModel parameter %s must be defined!\n", param); 
}
	

/* MOD_BJT_MODEL_COMPUTE() - Compute parameters if they have 
 *		             not been specified.
 */
mod_bjt_model_compute(mp)
struct mod_bjtmodel_s *mp;
{

	double tref2;
	double tnew2;
	double egref;
	double egnew;

	double ktref;
	double ktnew;
	double btqnew;

	double ratio;
	double sratio;
	double xti_ratio;
	double xtb_ratio;
	double egfactor;
	double isnew;

	double ni_ref;
	double ni_term;
	double ni;
	double vj_term;

	double ise_ratio;
	double isc_ratio;
	double isref;

	/* New and reference temperatures */

	isref= mp->is;

	mp->tnew = mp->tnew + KELVIN;
	mp->tref = mp->tref + KELVIN;

	tref2  = mp->tref * mp->tref;
	tnew2  = mp->tnew * mp->tnew;

	ratio  = (mp->tnew/mp->tref);

	/* Compute Eg at temperature.
	 * 
	 */

	egref = 1.16 - (7.02e-4 * tref2)/(mp->tref + 1108.0);
	egnew = 1.16 - (7.02e-4 * tnew2)/(mp->tnew + 1108.0); 


	/* New and reference (300 K) Vts */

	ktref = BOLTZMAN * mp->tref;
	ktnew = BOLTZMAN * mp->tnew;
	btqnew =  ktnew / CHARGE;

	mp->btq = btqnew;


	/* Calculate intrinsic carrier conc. ni at temperature.
	 * ni is currently unused; ni_term is used for temp
	 * effects on junction potentials.
	 */

	sratio  = ratio * sqrt(ratio);
	ni_term = exp((0.5/btqnew) * (-egnew + 1.1151*ratio));

	/*
	 * ni_ref  = 1.45e10;
	 * ni      = ni_ref * sratio * ni_term;
	 *
	 */


	/* Misc. temperature factors */

	xti_ratio = exp(mp->xti * log(ratio));
	xtb_ratio = exp(mp->xtb * log(ratio));

	egfactor = exp((mp->eg)*(mp->tnew/mp->tref -1)/(btqnew));


	/* Temperature effects for fwd and rev Betas */	

	mp->bf = mp->bf * xtb_ratio;
	mp->br = mp->br * xtb_ratio;

	/* Temperature effect for saturation current */
	/* Is */
	/* isnew  = mp->is * xti_ratio * egfactor/xtb_ratio; */
	isnew  = mp->is * xti_ratio * egfactor;
	mp->is = isnew;


	/* Nonlinear gain coeffs and saturation currents */

	if (mp->mod_ise_given == MOD_FALSE) {

		if (mp->mod_c2_given == MOD_TRUE)
			mp->ise = mp->c2 * mp->is;
		else
			mp->ise = 0.0;
	}

	/* Temperature effect for Ise */
/*	isnew   = mp->ise * xti_ratio * egfactor * exp(-mp->ne) / xtb_ratio; */
/* wrr fixed temp. dependence of ise per Semicon. Device Modeling, p. 102 */
	ise_ratio = exp( (1.0/mp->ne) * log( mp->is / isref ) );
	isnew   = mp->ise * ise_ratio / xtb_ratio;
	mp->ise = isnew;


	if (mp->mod_isc_given == MOD_FALSE) {

		if (mp->mod_c4_given == MOD_TRUE)
			mp->isc = mp->c4 * mp->is;
		else
			mp->isc = 0.0;
	}
	/* Temperature effect for Isc */
/*	isnew = mp->isc * xti_ratio * egfactor * exp(-mp->nc) / xtb_ratio; */
/* wrr fixed temp. dependence of ise per Semicon. Device Modeling, p. 102 */
	isc_ratio = exp( (1.0/mp->nc) * log( mp->is / isref ) );
	isnew   = mp->isc * isc_ratio / xtb_ratio;
	mp->isc = isnew;


	/* Temperature effects for junction potentials */

/*	vj_term = 2.0 * btqnew * log(sratio * ni_term); */

	vj_term = 2.0 * btqnew * log(sratio) + ( ratio*egref - egnew );
	mp->vje = mp->vje * ratio - vj_term;
	mp->vjc = mp->vjc * ratio - vj_term;
	mp->vjs = mp->vjs * ratio - vj_term;

	/* Other useful precomputes */

	mp->vte  = mp->ne * btqnew;
	mp->vtc  = mp->nc * btqnew;
	mp->vtnf = mp->nf * btqnew;
	mp->vtnr = mp->nr * btqnew;

	if (mp->mod_vaf_given == MOD_TRUE)
		mp->inv_vaf = 1.0/(mp->vaf);
	else
		mp->inv_vaf = 0.0;

	if (mp->mod_var_given == MOD_TRUE)
		mp->inv_var = 1.0/(mp->var);
	else
		mp->inv_var = 0.0;

	if (mp->mod_vtf_given == MOD_TRUE)
		mp->inv_vtf = 1.0/(mp->vtf);
	else
		mp->inv_vtf = 0.0;


	/* Attach diode model for substrate diode */
	mp->diomodel = (struct mod_diomodel_s *) mod_bjt_diode(mp);

/*
printf("\nName\tValue\n\n");
printf(" IS\t%11.5e\n", mp->is);
printf(" BF\t%11.5e\n", mp->bf);
printf(" NF\t%11.5e\n", mp->nf);
printf(" VAF\t%11.5e\n", mp->vaf);
printf(" IKF\t%11.5e\n", mp->ikf);
printf(" ISE\t%11.5e\n", mp->ise);
printf(" NE\t%11.5e\n", mp->ne);
printf(" BR\t%11.5e\n", mp->br);
printf(" NR\t%11.5e\n", mp->nr);
printf(" VAR\t%11.5e\n", mp->var);
printf(" IKR\t%11.5e\n", mp->ikr);
printf(" ISC\t%11.5e\n", mp->isc);
printf(" NC\t%11.5e\n", mp->nc);
printf(" RB\t%11.5e\n", mp->rb);
printf(" IRB\t%11.5e\n", mp->irb);
printf(" RBM\t%11.5e\n", mp->rbm);
printf(" RE\t%11.5e\n", mp->re);
printf(" RC\t%11.5e\n", mp->rc);
printf(" CJE\t%11.5e\n", mp->cje);
printf(" VJE\t%11.5e\n", mp->vje);
printf(" MJE\t%11.5e\n", mp->mje);
printf(" CJC\t%11.5e\n", mp->cjc);
printf(" VJC\t%11.5e\n", mp->vjc);
printf(" MJC\t%11.5e\n", mp->mjc);
printf(" XCJC\t%11.5e\n", mp->xcjc);
printf(" CJS\t%11.5e\n", mp->cjs);
printf(" VJS\t%11.5e\n", mp->vjs);
printf(" MJS\t%11.5e\n", mp->mjs);
printf(" FC\t%11.5e\n", mp->fc);
printf(" AF\t%11.5e\n", mp->af);
printf(" KF\t%11.5e\n", mp->kf);
*/

}



/* MOD_BJT_COMPUTE() - This routine pre-computes various constants.
 *		       Returns new structure with pre-computes.
 */

struct mod_bipolar_s * 
mod_bjt_compute(mp, bjtp)
struct mod_bjtmodel_s *mp;
struct sp_bipolar_s *bjtp;
{
	struct mod_bipolar_s *bjt;

	/* Allocate a transistor structure and fill in values */
	bjt = (struct mod_bipolar_s *)
		sim_alloc(sizeof(struct mod_bipolar_s),S_MOD);
	bjt->area = bjtp->areafactor;

	/* Check for illegal area */
	if (bjt->area < 0.0) {
		sim_error(S_FATAL, S_MOD,
		          "\tBJT area is negative.\n"); 
		exit(1);
	} else if ((bjt->area == 0.0) || (bjt->area == ZEROSET)) {
		bjt->area = 1.0;
	}


	/* Area effects on current parameters */

	bjt->csat = mp->is  * bjt->area;
	bjt->ise  = mp->ise * bjt->area;
	bjt->isc  = mp->isc * bjt->area;
	bjt->itf  = mp->itf * bjt->area;

	/*  Modification by SWK--hope its right! */
	if (mp->mod_irb_given == MOD_TRUE)
		bjt->irb  = mp->irb * bjt->area;
	else
		bjt->irb = 0.0;

	if (mp->mod_ikf_given == MOD_TRUE)
		bjt->inv_ikf = 1.0/(mp->ikf * bjt->area);
	else
		bjt->inv_ikf = 0.0;

	if (mp->mod_ikr_given == MOD_TRUE)
		bjt->inv_ikr = 1.0/(mp->ikr * bjt->area);
	else
		bjt->inv_ikr = 0.0;
	
	/* Area effects on res & cap parameters */

	bjt->rb  = mp->rb  / bjt->area;
	bjt->rbm = mp->rbm / bjt->area;
	bjt->rc  = mp->rc  / bjt->area;
	bjt->re  = mp->re  / bjt->area;

	bjt->cje  = mp->cje * bjt->area;
	bjt->cjc  = mp->cjc * bjt->area;
	bjt->cjs  = mp->cjs * bjt->area;
	

	bjt->mod_rbm_given = mp->mod_rbm_given;

	return(bjt);
}

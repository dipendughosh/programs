/*#########################################################################
.cs 2 20


 #######             #####             ######           ##############
    #####           ####            ####    ####           #####      ##
     ####           ####          ####         ##           ###         ##
     # ###         # ###         ###           ###          ###         ###
     #  ###       #  ###         ###            ##          ###          # #
     #  ###       #  ###        ###             ###         ###          ## #
     #   ###     #   ###        ###             ###         ###          ## #
     #    ###   #    ###        ###             ###         ###          ## #
     #    # ##  #    ###        ###             ###         ###          ## #
     #     ### #     ###         ###            ##          ###          ###
     #      ###      ###          # #          ##           ###         ##
     #      # #      ###           ###        ##            ###        ##
 #######     #   #########           ##########         ################


.cs 2
###########################################################################

                      Designed and written by
                  Donald Erdman, Duke University
               Gary Nifong & Ravi Subrahmanyan, MCNC

        This copy, serial #00, of MCNC proprietary software, is made
        available under license agreement.  Please heed all non-
        disclosure and internal use restrictions.


        Copyright 1986, 1987 by the Microelectronics Center of North
        Carolina and Duke University

###########################################################################

	This file contains initialisation and precomputing for the 
	Spice level 2 MOS model.

###########################################################################*/
#include	<ctype.h>
#include	<math.h>
#include	"sim.h"
#include	"newmod.h"



/* MOD_MOS2_SETUP() - The following code implements SPICE model parameter
 *		setup. check parameter validity sets defaults, and
 *		calculates missing parameter values.
 */

struct mod_mosmodel_s *
mod_mos2_setup(sp, temp)
struct sp_mosmodel_s *sp;
double temp;			/* Temperature in degrees Centigrate */
{
	register struct mod_mosmodel_s *mp;

	/* Allocate compute model structure */
	mp = (struct mod_mosmodel_s *)
		sim_alloc(sizeof(struct mod_mosmodel_s),S_MOD);

	if (sp == (struct sp_mosmodel_s *) NULL) {
		sim_error(S_FATAL, exit, 1, S_MOD,
			"\tLevel 2# mosfet model is NULL!\n"); 
	}

	/* Attach parsed model to computed model */
	/*strcpy(mp->modelname, sp->modelname);*/
	/*mp->modeltype = sp->modeltype;*/
	/*mp->sp_mosmodel = sp;*/

	/* Check type of model */
	if (mp->modeltype == SP_NMOSTYPE )
		mp->sign = NMOS_SIGN;
	else if (mp->modeltype == SP_PMOSTYPE )
		mp->sign = PMOS_SIGN;
	else 
		sim_error(S_FATAL, exit, 1, S_MOD,
			"\tIllegal model type for level 2# mosfet model!\n"); 
	
	mod_mos2_check(sp, mp, temp);

	mod_mos2_model_compute(mp);

	return(mp);
}



/* MOD_MOS2_CHECK() - The following code implements SPICE model parameter
 *		checking, sets defaults, and reports missing
 *		parameter values.
 */

mod_mos2_check(sp, mp, temp)
struct sp_mosmodel_s *sp;
struct mod_mosmodel_s *mp;
double temp;
{

	
	/*  If not given, then compute values later for 
	 *  simulation.
	 */

	if(sp->vto == ZEROSET)
		mp->mod_vto_compute = MOD_TRUE;	/* calculate value */
	else
		mp->vto = sp->vto;
	if(sp->kp == ZEROSET)
		mp->mod_kp_compute = MOD_TRUE;	/* calculate value */
	else
		mp->kp = sp->kp;
	if(sp->gamma == ZEROSET)
		mp->mod_gamma_compute = MOD_TRUE; /* calculate value */
	else
		mp->gamma = sp->gamma;
	if(sp->phi == ZEROSET)
		mp->mod_phi_compute = MOD_TRUE;	/* calculate value */
	else
		mp->phi = sp->phi;
	if(sp->lambda == ZEROSET)
		mp->mod_lambda_compute = MOD_TRUE;	/* calculate value */
	else
		mp->lambda = sp->lambda;


	/*  If not given, then set default values for models
	 *	specified in "SPICE Version 2G User's Guide" .
	 */
	if(sp->is == ZEROSET)
		mp->mod_is_given = MOD_FALSE;
	else
		mp->mod_is_given = MOD_TRUE;
		mp->is = sp->is;

	if(sp->pb == ZEROSET)
		mp->pb = 0.8;
	else
		mp->pb = sp->pb;

	if(sp->cgso == ZEROSET)
		mp->cgso = 0.0;
	else
		mp->cgso = sp->cgso;

	if(sp->cgdo == ZEROSET)
		mp->cgdo = 0.0;
	else
		mp->cgdo = sp->cgdo;

	if(sp->cgbo == ZEROSET)
		mp->cgbo = 0.0;
	else
		mp->cgbo = sp->cgbo;

	if(sp->rsh == ZEROSET)
		mp->rsh = 0.0;
	else
		mp->rsh = sp->rsh;
	if(sp->cj == ZEROSET)
		mp->cj = 0.0;
	else
		mp->cj = sp->cj;
	if(sp->mj == ZEROSET)
		mp->mj = 0.5;
	else
		mp->mj = sp->mj;
	if(sp->cjsw == ZEROSET)
		mp->cjsw = 0.0;
	else
		mp->cjsw = sp->cjsw;
	if(sp->mjsw == ZEROSET)
		mp->mjsw = 0.33;
	else
		mp->mjsw = sp->mjsw;
	if(sp->js == ZEROSET)
		mp->js = 1.0e-14;
	else
		mp->js = sp->js;
	if(sp->tpg == ZEROSET)
		mp->tpg = 1.0;
	else
		mp->tpg = sp->tpg;
	if(sp->tox == ZEROSET)
		mp->tox = 1.0e-07;
	else
		mp->tox = sp->tox; 
	if(sp->xj == ZEROSET)
		mp->xj = 0.0;
	else
		mp->xj = sp->xj;
	if(sp->nfs == ZEROSET)
		mp->nfs = 0.0;
	else
		mp->nfs = sp->nfs;
	if(sp->nss == ZEROSET)
		mp->nss = 0.0;
	else
		mp->nss = sp->nss;
	if(sp->ld == ZEROSET)
		mp->ld = 0.0;	
	else
		mp->ld = sp->ld;
	if(sp->vmax == ZEROSET)
		mp->vmax = 0.0;
	else
		mp->vmax = sp->vmax;
	if(sp->uo == ZEROSET)
		mp->uo = 600.0;	
	else
		mp->uo = sp->uo;
	if(sp->ucrit == ZEROSET)
		mp->ucrit = 1.0e4;
	else
		mp->ucrit = sp->ucrit;
	if(sp->uexp == ZEROSET)
		mp->uexp = 0.0;	
	else
		mp->uexp = sp->uexp;
	if(sp->neff == ZEROSET)
		mp->neff = 0.0;
	else
		mp->neff = sp->neff;
	if(sp->fc == ZEROSET)
		mp->fc = 0.5;
	else
		mp->fc = sp->fc;
	if(sp->delta == ZEROSET)
		mp->delta = 0.0;
	else
		mp->delta = sp->delta;
	if(temp == ZEROSET)
		mp->tnew = 27.0;
	else
		mp->tnew = temp;
	/* Set reference voltage */
	mp->tref = 27.0;


	/* The following parameters must be given in the model
	 * cards or the program will complain to the user.
	 */
	if(sp->level == ZEROSET)
		mod_mos2_error("LEVEL");
	else
		mp->level = (int) sp->level; 
	if(sp->nsub == ZEROSET)
		mod_mos2_error("NSUB");
	else
		mp->nsub = sp->nsub; 



	/* The following parameters are not used in the
	 * level 2# model.
	 */
	if(sp->rd != ZEROSET)
		mod_mos2_nouse("RD");	/* not used */
	if(sp->rs != ZEROSET)
		mod_mos2_nouse("RS");	/* not used */
	if(sp->cbd != ZEROSET)
		mod_mos2_nouse("CBD");	/* not used */
	if(sp->cbs != ZEROSET)
		mod_mos2_nouse("CBS");	/* not used */
	if(sp->utra != ZEROSET)
		mod_mos2_nouse("UTRA");	/* not used */
	if(sp->xqc != ZEROSET)
		mod_mos2_nouse("XQC");	/* not used */
	if(sp->kf != ZEROSET)
		mod_mos2_nouse("KF");	/* not used */
	if(sp->af != ZEROSET)
		mod_mos2_nouse("AF");	/* not used */
	if(sp->theta != ZEROSET)
		mod_mos2_nouse("THETA");	/* not used */
	if(sp->eta != ZEROSET)
		mod_mos2_nouse("ETA");	/* not used */
	
}

mod_mos2_nouse(param)
char *param;
{
	sim_error(S_FATAL, S_RETURN, S_MOD,
		"\tParameter %s is not used in LEVEL 2# model.\n", param); 
}


mod_mos2_error(param)
char *param;
{
	sim_error(S_FATAL, S_RETURN,  S_MOD,
		"\tModel parameter %s must be defined!\n", param); 
}
	

/* MOD_MOS2_MODEL_COMPUTE() - Compute the following parameters if they have 
 *		not been specified.
 */
mod_mos2_model_compute(mp)
struct mod_mosmodel_s *mp;
{
	double wkfng;
	double fermis;
	double fermig;
	double ratio;
	double sratio;

	double tref2;
	double tref3;
	double tnew2;
	double tnew3;
	double ktref;
	double ktnew;
	double btqref;
	double egnew;
	double egref;

	double xni;
	double xniterm1;
	double phiterm1;
	double phiterm2;
	double pbterm;
	double pbarg;

	double phiref;
	double phidiff;
	double sdiff;
	double gdiff;
	double wkfngsdiff;


	/* Convert units to volts, amps, and meters */

	mp->uo = mp->uo * 1.0e-4;
	mp->nsub = mp->nsub * 1.0e6;
	mp->nss = mp->nss * 1.0e4;
	mp->nfs = mp->nfs * 1.0e4;
	mp->ucrit = mp->ucrit * 1.0e2;

	/* Compute temperature, cox, and silicon energy gap */

	mp->tnew = mp->tnew + KELVIN;
	mp->tref = mp->tref + KELVIN;


	tref2 = mp->tref * mp->tref;
	tref3 = tref2 * mp->tref;
	tnew2 = mp->tnew * mp->tnew;
	tnew3 = mp->tnew * tnew2;

	/* Compute the energy gap between the conduction band
	 *	and the valence band for poly silicon at 300K
	 *	and the user supplied temperature.
	 */
	egref = 1.16 - (7.02e-4 * tref2)/(mp->tref + 1108.0); 
	egnew = 1.16 - (7.02e-4 * tnew2)/(mp->tnew + 1108.0); 
	ktref = BOLTZMAN * mp->tref;
	ktnew = BOLTZMAN * mp->tnew;
	btqref =  ktref / CHARGE;

	mp->btq = ktnew / CHARGE;


	/* Gate farads per meter */
	mp->cox = EPOX / mp->tox;

	/* Adjust mobility due to temperature 
	 * sratio = (tnew/tref) ** 3/2
	 */
	ratio =   mp->tnew/mp->tref;
	sratio = ratio * sqrt(ratio);
	mp->uo = mp->uo / sratio;


	/* Compute KP if not defined */

	if( mp->mod_kp_compute == MOD_TRUE)
		mp->kp = mp->uo * mp->cox;
	else
		mp->kp = mp->kp / sratio;


	/* Either compute PHI or adjust the value of PHI
	 *	given in the model based on temperature.
	 *
	 * Compute a new Intrinsic Carrier Concentration.
	 */

	if( mp->mod_phi_compute == MOD_TRUE) {
		phiref = 2.0 * btqref * log(mp->nsub/NI);
		xniterm1 = exp(CHARGE * (egref/ktref - egnew/ktnew));
		xni = NI * sratio * sqrt(xniterm1);
		mp->phi = 2.0 * mp->btq * log(mp->nsub/xni);

	}
	else {
		phiref = mp->phi;
/*		xniterm1 = exp(CHARGE * (egref/ktref - egnew/ktnew - mp->phi/ktref)); */
		xniterm1 = exp(CHARGE * (egref/ktref - egnew/ktnew));
		xni = mp->nsub * sratio * sqrt(xniterm1);
		mp->phi = 2.0 * mp->btq * log(mp->nsub/xni) + ratio * mp->phi;
	}

	/* Do not let PHI go negative */
	if(mp->phi <= 0.0)
		mp->phi = 0.001;
		
	
	/* Adjust PB with temperature */
	pbarg = 0.5 * (egref/ktref - egnew/ktnew);
	pbterm = -2.0 * mp->btq * (1.5 * log(ratio) + CHARGE * pbarg);
	mp->pb = (ratio * mp->pb) + pbterm;

	/* Do not let PB go negative */
	if(mp->pb <= 0.0)
		mp->pb = 0.001;


	/* Compute GAMMA if not defined */

	if( mp->mod_gamma_compute == MOD_TRUE)
		mp->gamma = sqrt(2.0 * CHARGE * EPSIL * mp->nsub)/mp->cox;

	/* Compute work function difference of poly silicon. 
	 * 	Refer to diagram on page 397 & 271 & 397:
	 *	"Physics of Semiconductor Devices " SZE
	 */

	/* Fermi energy level of poly Silicon */
	fermis = mp->sign * 0.5 * mp->phi;

	/* FERMIG is half of the energy gap from the conductance
	 *	band to valence band of the gate.
	 *
	 * TPG = 1 = (n+ poly) 	TPG = -1 = (p+ poly)
	 */
	fermig = mp->sign * mp->tpg * 0.5 * egnew;

	/* To compute temperature effects on energy levels,
	 * subtract the old and add the new values of 
	 * energy levels at different temperature. 
	 */
	phidiff = phiref - mp->phi;
	sdiff = mp->sign * 0.5 * phidiff;
	gdiff = mp->sign * mp->tpg * 0.5 * (egref - egnew);

	/* WKFNGS is the work function difference between metal
	 * and silicon.
	 *
	 * WKFNGSDIFF is the difference in the value WKFNGS due
	 * to temperature effects.
	 */
	mp->wkfngs = - (fermig + fermis);
	wkfngsdiff =  gdiff + sdiff;


	/* Compute VFB, VBI, and VTO if not defined
	 *
	 * NOTE: The flatband voltage is the voltage required to
	 *	 eliminate the electric field between the gate
	 *	 and channel. VFB should be negative for n-type and
	 *       positive for p-type. 
	 *
	 *	 VBI = VFB + (2 * fermi)     phi = 2 * fermi
	 *	 The built-in voltage VBI is amount of voltage required
	 *	 to move to the conduction band. Which is the:
	 *	 VBI = (no electric field voltage) + (2 * fermi)
	 */

	if( mp->mod_vto_compute == MOD_TRUE) {
		mp->vfb = mp->wkfngs - ((CHARGE * mp->nss) / mp->cox);
		mp->vto = mp->vfb + 
			mp->sign * (mp->gamma * sqrt(mp->phi) + mp->phi);
		mp->vbi = mp->vto - mp->sign * (mp->gamma * sqrt(mp->phi));

		/* Correct the VBI sign */
		mp->vbi = mp->sign * mp->vbi;
	}
	else {
		/* Before temperature values of VFB & VBI */
		mp->vfb = mp->vto -
			(mp->sign * (mp->gamma * sqrt(phiref) + phiref));
		mp->vbi = mp->vfb + (mp->sign * phiref);

		if(mod_dbgflag == MOD_TRUE) {
			fprintf(mod_dbg,"First!\n");
			fprintf(mod_dbg,"vfb = %g\n", mp->vfb);
			fprintf(mod_dbg,"vbi = %g\n", mp->vbi);
			fprintf(mod_dbg,"vto = %g\n", mp->vto);
		}


		/* Adjust the values of VTO VFB VBI due to temperature */
		mp->vfb = mp->vfb + wkfngsdiff;
		mp->vbi = mp->vfb + (mp->sign * mp->phi);
		mp->vto = mp->vbi + (mp->sign * mp->gamma * sqrt(mp->phi) );

		/* Correct the VBI sign */
		mp->vbi = mp->sign * mp->vbi;
	}


	/* compute model variable XD */

	mp->xd = sqrt( (2.0 * EPSIL) / (CHARGE * mp->nsub));

	/* compute model contant for computing eta  */

	mp->deltaterm = mp->delta * ((PI*EPSIL)/(4.0 * mp->cox));


	/* Compute some useful values for capacitor evaluation */

	mp->fcpb = mp->fc * mp->pb;
	mp->fcmj1 = exp (1 + mp->mj * log( 1 - mp->fc));
	mp->fcmj2 = 1 - mp->fc * (1 + mp->mj);
	mp->fcmjsw1 = exp (1 + mp->mjsw * log( 1 - mp->fc));
	mp->fcmjsw2 = 1 - mp->fc * (1 + mp->mjsw);
	mp->pbmj = mp->mj / mp->pb;
	mp->pbmj = mp->mjsw / mp->pb;

	/*****	DEBUG	*****/

	if(mod_dbgflag == MOD_TRUE) {
		fprintf(mod_dbg,"\n***** mod_moscheck ******\n");
		fprintf(mod_dbg,"temp = %g\n", mp->tref);
		fprintf(mod_dbg,"temp2 = %g\n", mp->tnew);
		fprintf(mod_dbg,"tpg = %g\n", mp->tpg);
		fprintf(mod_dbg,"type = %g\n", mp->sign);
		fprintf(mod_dbg,"wkfngs = %g\n", mp->wkfngs);
		fprintf(mod_dbg,"btq = %g\n", mp->btq);
		fprintf(mod_dbg,"phi = %g\n", mp->phi);
		fprintf(mod_dbg,"phiref = %g\n", phiref);
		fprintf(mod_dbg,"eg = %g\n", egnew);
		fprintf(mod_dbg,"egref = %g\n", egref);
		fprintf(mod_dbg,"kp = %g\n", mp->kp);
		fprintf(mod_dbg,"uo = %g\n", mp->uo);
		fprintf(mod_dbg,"vfb = %g\n", mp->vfb);
		fprintf(mod_dbg,"vbi = %g\n", mp->vbi);
		fprintf(mod_dbg,"vto = %g\n", mp->vto);
		fprintf(mod_dbg,"pb = %g\n", mp->pb);
		fprintf(mod_dbg,"***** end mod_moscheck ******\n");
	}

}



/* MOD_MOS2_COMPUTE() - This routine pre-computes capacitors constants.
 *		length, width, and area constants. Returns new structure
 *		with pre-computes.
 */

struct mod_mosfet_s * 
mod_mos2_compute(mp, mosp)
struct mod_mosmodel_s *mp;
struct sp_mosfet_s *mosp;
{
	struct mod_mosfet_s *mosfet;

	/* Allocate a transistor structure and fill in values */
	mosfet = (struct mod_mosfet_s *)
		sim_alloc(sizeof(struct mod_mosfet_s),S_MOD);
	mosfet->length = mosp->length;
	mosfet->width = mosp->width;
	mosfet->sarea = mosp->sarea;
	mosfet->sperim = mosp->sperim;
	mosfet->darea = mosp->darea;
	mosfet->dperim = mosp->dperim;


	/* Precomputes for current generation */
	mosfet->effectivelength = mosfet->length - (2.0 * mp->ld); 
	mosfet->gatecap = mp->cox * mosfet->effectivelength * mosfet->width;

	/* Precomputes for capacitance generation */
	mosfet->cjdarea = mosfet->darea * mp->cj;
	mosfet->cjsarea = mosfet->sarea * mp->cj;
	mosfet->cjdperim = mosfet->dperim * mp->cjsw;
	mosfet->cjsperim = mosfet->sperim * mp->cjsw;

	mosfet->cgsocap = mp->cgso * mosfet->width;
	mosfet->cgdocap = mp->cgdo * mosfet->width;
	mosfet->cgbocap = 2.0 * mp->cgbo * mosfet->effectivelength;

	/* Check for illegal parameter */
	if (mosfet->effectivelength < 0.0) {
		sim_error(S_FATAL, exit, 1, S_MOD,
		"\tParameter \"ld\" lateral diffusion is too large!\n"); 
	}

	return(mosfet);
}

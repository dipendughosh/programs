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

	This file contains Spice Level 2 MOS current modeling

###########################################################################*/
#include	<ctype.h>
#include	<math.h>
#include	"sim.h"
#include	"newmod.h"



/* MOD_MOS_EQ2() - SPICE level #2 models equations with
 *		   temperature effects.
 */
mod_mos_eq2(mp, mosfet, auxv, auxi)
struct mod_mosmodel_s *mp;
struct mod_mosfet_s *mosfet;

double auxv[];
double auxi[];

{

double vds;
double vbs;
double vgs;
double idrain;
double isource;

double phivbs, sphivbs, isphivbs, phivds, sphivds, isphivds;
double delta, etta;
double ws, wd, xjterm, phas, phad, alphas, alphad, gammas;
double vgsx, vbsx, vdsx;
double vbin, vth, von, vgnow;
double vdsat, vdsatnew;
double cdterm1, xdl, cdalphas, cdalphad, cdterm2, cd;
double cfs, xn, xnbqt;
double vetta, getta, getta2, ingetta2, ettaterm;
double vdsaterm1, vdsaterm2, del, wb, lmax, leff;
double beta;
double sphivds3, sphivbs3;
double inxnbqt, weakexp, weakterm1, weakterm2;
double linterm1, linterm2;
double sphivdsat, sphivdsat3, satterm1, satterm2;
double sphivdson, vdson, sphivdson3;
double varg;
double vdarg;
double xdv, xls, xlv, xlfact, xlterm;
double udenominator, vbp, uexpterm, uoeffective;
double xlambda;
int    mosmode;

/* stuff for source/drain diodes */

double ids;		/* current from drain to source */
double ibs;		/* current from bulk to source */
double ibd;		/* current from bulk to drain  */
double vbsd;		/* used to save actual vbs (bulk to source) value */
double vbd;		/* bulk to drain voltage */
double dioarea;		/* area of source/drain diode */
double diores = 1.0e-3;	/* series resistance to prevent math overflow */
double diosatcurrent;	/* diode saturation current */


	/* Start calculations */

	/* Set up terminal voltages from auxv */

	vds = auxv[0] - auxv[2];
	vbs = auxv[3] - auxv[2];
	vgs = auxv[1] - auxv[2];

	/* Set the mode for current equations */ 
	if(vds < 0.0) {
		/* P-types  &  inverted n-types */
		vbsx = -vbs;
		vgsx = -vgs;
		vdsx = -vds;
		mosmode = SP_PMOSTYPE;

	}
	else if(vds > 0.0) {
		/* N-types  &  inverted p-types */
		vbsx = vbs;
		vgsx = vgs;
		vdsx = vds;
		mosmode = SP_NMOSTYPE;

	}

	/* When VDS = 0.0 we are unable to determine signs
	 *	so we must check the model type.
	 */
	else {
		if (mp->sign == NMOS_SIGN) {
			/* N-types  &  inverted p-types */
			vbsx = vbs;
			vgsx = vgs;
			vdsx = vds;
			mosmode = SP_NMOSTYPE;

		}
		else if (mp->sign == PMOS_SIGN) {
			/* P-types  &  inverted n-types */
			vbsx = -vbs;
			vgsx = -vgs;
			vdsx = -vds;
			mosmode = SP_PMOSTYPE;

		}
	}

	
	/* Fix signs for source/drain diode biases to make all 
	   calculations for n-type transistors
	*/

	if (mp->modeltype == SP_NMOSTYPE) {		/* NMOS */

		vbsd = vbs;
		vbd  = vbsd - vdsx;

	} else if(mp->modeltype == SP_PMOSTYPE) {	/* PMOS */

		vbsd = -vbs;
		vbd  = vbsd - vdsx;
	}



	/*
	 * NOTE: if vbs is positive then we must clamp vbs to
	 *	ground or equations will blow up.
	 */
	 if (vbsx > 0.0) {

	/*	fprintf(stdout,
		"Oooops! The current equations can't handle positive VBS!\n");
		fprintf(stdout,
		"Clamping vbs to ground!\n");
		fprintf(stdout,
		"Oh my circuits! I just hate it when I can't get it right!\n");
	*/

		vbsx = 0.0;
	}



	/* compute some useful values */
	phivbs = mp->phi - vbsx;
	sphivbs = sqrt(phivbs);
	phivds = phivbs + vdsx;
	sphivds = sqrt(phivds);
	isphivbs = 1.0 / sphivbs;
	isphivds = 1.0 / sphivds;
	xlambda = mp->lambda;

	/* NOTE:
	 * 	Spice documentation shows eta calculation dividing by
	 *      the width instead of length. But, Spice code
	 *      and Suxes code uses length, because COX has been
	 * 	multiplied by LENGTH * WIDTH.
	 *	So, it's OK.
	 */

	/* The deltaterm is calculated with SPICE parameter DELTA */
	delta = mp->deltaterm / mosfet->width;
	etta = 1.0 + delta;

	/* Calculate some current terms */
	sphivds3 = sphivds * sphivds * sphivds;
	sphivbs3 = sphivbs * sphivbs * sphivbs;


	/* Now use GAMMA to compute the short channel effect (gammas) */ 
	ws = mp->xd * sphivbs;
	wd = mp->xd * sphivds; 
	xjterm = (0.5 * mp->xj)/mosfet->effectivelength;
	phas =  1.0 + (2.0 * (ws/mp->xj));
	phad =  1.0 + (2.0 * (wd/mp->xj));
	alphas = xjterm * ( sqrt(phas) - 1.0 );
	alphad = xjterm * ( sqrt(phad) - 1.0 );
	gammas = mp->gamma * (1.0 - alphas - alphad);
	


	/* Now compute Vbin and Vth */
	vbin = mp->vbi + delta * (mp->phi - vbsx);
	vth = vbin + (gammas * sphivbs);


	/* NOTE: 
	 *	Adjustment for Von is based a NFS which a curve
	 *	fitting parameter in the weak conduction region.
	 */

	/* NFS is undefined or equal to zero */
	if(mp->nfs <= 0.0) {
		von = vth;
	}
	/* NFS has been defined so compute a new Von */
	else {
		/* Compute Von starting with Cd */
		cdterm1 = 0.5 * gammas * isphivbs;
		xdl = (0.25 * mp->xd) / mosfet->effectivelength;
		cdalphas = xdl * (1.0 / sqrt( phas)) * isphivbs;
		cdalphad = xdl * (1.0 / sqrt( phad)) * isphivds;
		cdterm2 = sphivbs * mp->gamma * (cdalphas + cdalphad);
		cd = cdterm1 - cdterm2 + delta;
		cfs = CHARGE * mp->nfs;
		xn = 1.0 + (cfs/mp->cox) + cd;
		xnbqt = xn * mp->btq;
		inxnbqt = 1.0 / xnbqt;

		von = vth + xnbqt;
	}


	/* Compute effective mobility with parameters UCRIT and UEXP */
	udenominator = vgsx - von;
	vbp = (mp->ucrit * EPSIL) / mp->cox;
	if( udenominator > vbp) {
		uexpterm = vbp / udenominator;
		uoeffective = mp->uo * exp(mp->uexp * log(uexpterm));
	}
	else 
		uoeffective = mp->uo;


	/* Evaluate saturation voltage and its derivatives
	 * 	according to GROVE-FROHMAN equations.
	 */

	/* Test for vgs less than von */
	if (vgsx < von)
		vgnow = von;
	else 
		vgnow = vgsx;


	/* Calculate vdsat saturation voltage that is dependent on
	 * the gate to source voltage.
	 */
	vetta = (vgnow - vbin) / etta;
	getta = gammas / etta;

 	/* If VMAX is not defined:
	 *	a) Compute the saturation voltage assuming channel pinch off.
	 *	b) Calculate vdsat using this geometrical method.
	 */
	if (mp->vmax <= 0.0)  { 
		getta2 = getta * getta;
		ingetta2 = 1.0/getta2;
		varg =  vetta + mp->phi - vbsx;
		if (varg < 0.0)
			vdsat = 0.0;
		else {
			ettaterm = sqrt(1.0 +(4.0 * ingetta2 * varg));
			vdsat = vetta + (0.5 * getta2 * ( 1.0 - ettaterm));
			if (vdsat < 0.0)
				vdsat = 0.0;
		}
		/* If LAMBDA is undefined */
		if(xlambda <= 0.0) {
			if( vdsx != 0.0) {
			vdsaterm1 = (vdsx - vdsat) / 4.0;
			vdsaterm2 = sqrt( 1.0+ (vdsaterm1 * vdsaterm1));
			xlterm =  sqrt( vdsaterm1 + vdsaterm2);
			xlfact = mp->xd / (mosfet->effectivelength * vdsx);
			xlambda = xlfact * xlterm;
			}
			else 
				xlambda = 0.0;
		}
	}



 	/* If VMAX is defined:
	 *	a) Compute Vdsat assuming the scattering limited velocity.
	 *	b) Calculate vdsat using the Ferrari method.
	 */
	if (mp->vmax > 0.0) { 
		vdsatnew = mod_vdsat_eq(mp, mosfet, getta, vetta,
				uoeffective, sphivbs3, vbsx); 

		if (vdsatnew != 0.0) {
			vdsat = vdsatnew;
		}
		/* Use the above geometrical method when Ferrari returns 
		 * roots with the value of zero.		
		 */
		else {
			getta2 = getta * getta;
			ingetta2 = 1.0/getta2;
			varg =  vetta + mp->phi - vbsx;
			if (varg < 0.0)
				vdsat = 0.0;
			else {
				ettaterm = sqrt(1.0 +(4.0 * ingetta2 * varg));
				vdsat = vetta + (0.5*getta2 *(1.0 - ettaterm));
				if (vdsat < 0.0)
					vdsat = 0.0;
			}
		}

		/* If LAMBDA is undefined calculate using VMAX and NEFF */
		if(xlambda <= 0.0) {
			if( vdsx != 0.0) {
			xdv = mp->xd / sqrt(mp->neff);
			xlv = mp->vmax * xdv / (2.0 * uoeffective);
			if ((vdsx - vdsat) < 0.0)
				vdarg = 0.0;
			else
				vdarg = vdsx - vdsat;
			xls = sqrt((xlv * xlv) + vdarg);
			xlfact = xdv/(mosfet->effectivelength * vdsx);
			xlambda = xlfact * (xls - xlv);
			}
			else 
				xlambda = 0.0;
		}
	}


	 /* Calculate the channel length modulation using LAMBDA
	  *  and check for punch through.
	  */

	wb = mp->xd * sqrt(mp->pb);
	lmax = mosfet->effectivelength - wb;
	leff = mosfet->effectivelength * (1.0 - xlambda * vdsx);
	del = xlambda * vdsx * mosfet->effectivelength;

	/* Punch-through check */
	if( leff <= wb)
		leff = wb / (1.0 + ((del - lmax) / wb));


	/* Compute a beta with modified channel length */
	beta = ( mosfet->width / leff ) * mp->kp * (uoeffective/mp->uo);


	/* Clamp drain to source voltage at VDSAT */
	if(vdsx < vdsat)
		vdson = vdsx;
	else
		vdson = vdsat;

	sphivdson = sqrt( mp->phi - vbsx + vdson);
	sphivdson3 = sphivdson * sphivdson * sphivdson;


	/* Weak inversion transistor current */
	if (vgsx <= von) {
		weakexp = exp( inxnbqt * ( vgsx - von));
		weakterm1 = (von - vbin - (etta * vdson * 0.5)) * vdson;
		weakterm2 = gammas * (sphivdson3 - sphivbs3) / 1.5;
		ids = beta * (weakterm1  - weakterm2) * weakexp;
	}

	/* Linear region */
	else if (vdsx < vdsat) {

		linterm1 = (vgsx - vbin - (etta * vdsx * 0.5)) * vdsx;
		linterm2 = gammas * (sphivds3 - sphivbs3) / 1.5;
		ids = beta * (linterm1 - linterm2);
	}

	/* Saturation region */
	else {
		sphivdsat = sqrt( mp->phi - vbsx + vdsat);
		sphivdsat3 = sphivdsat * sphivdsat * sphivdsat;
		satterm1 = (vgsx - vbin - (etta * vdsat * 0.5)) * vdsat;
		satterm2 = gammas * (sphivdsat3 - sphivbs3) / 1.5;
		ids = beta * (satterm1 - satterm2);
	}



	/* Calculate the bulk currents due to the source and
	   drain diodes 
	*/

	/* drain saturation current */

	if (mp->mod_is_given == MOD_FALSE) {
		dioarea = mosfet->darea + mp->xj*mosfet->dperim;  
		diosatcurrent = mp->js * dioarea;
	} else 
		diosatcurrent = mp->is;


	if (vbd <= (mp->pb + 5 * mp->btq))	/* normal region */	
		ibd = diosatcurrent * (exp(vbd/mp->btq) - 1.0);

	else					/* resistive region */
		ibd = diosatcurrent*(exp((mp->pb + 5 * mp->btq)/mp->btq) 
		       - 1.0) + (vbd-(mp->pb + 5 * mp->btq))/diores;


	/* source saturation current */

	if (mp->mod_is_given == MOD_FALSE) {
		dioarea = mosfet->sarea + mp->xj*mosfet->sperim;
		diosatcurrent = mp->js * dioarea;
	} else
		diosatcurrent = mp->is;

	if (vbsd <= (mp->pb + 5 * mp->btq))	/* normal region */
		ibs = diosatcurrent * (exp(vbsd/mp->btq) - 1.0);

	else					/* resistive region */
		ibs = diosatcurrent*(exp((mp->pb + 5 * mp->btq)/mp->btq) 
		       - 1.0) + (vbsd-(mp->pb + 5 * mp->btq))/diores;


	/* Calculate the total drain and source currents */

	/*
	idrain  =   ids - ibd;
	isource = -(ids + ibs);
	*/
	
	idrain  =   ids;
	isource =  -ids;

	/* Correct the current direction */ 
	if(vds < 0.0) {
		idrain  = -(idrain);
		isource = -(isource);
	}	

	/* Put the currents into auxi[] */

	auxi[0] = idrain;
	auxi[1] = 0.0;
	auxi[2] = isource;

	/***** DEBUG *****/
	if(mod_dbgflag == MOD_TRUE) {
		fprintf(mod_dbg,"\n");
		fprintf(mod_dbg,"vgs= %g\tvds= %g\tvbs= %g\n",vgsx,vdsx,vbsx);
		fprintf(mod_dbg,"vbsd= %g\tvbd= %g\n",vbsd,vbd);
		fprintf(mod_dbg,"vbin = %g\n", vbin);
		fprintf(mod_dbg,"vth = %g\n", vth);
		fprintf(mod_dbg,"von = %g\n", von);
		fprintf(mod_dbg,"sphivbs = %g\n", sphivbs);
		fprintf(mod_dbg,"sphivds = %g\n", sphivds);
		fprintf(mod_dbg,"alphas = %g\n", alphas);
		fprintf(mod_dbg,"alphad = %g\n", alphad);
		fprintf(mod_dbg,"gammas = %g\n", gammas);
		fprintf(mod_dbg,"vdsat = %g\n", vdsat);
		fprintf(mod_dbg,"uoeffective = %g\n", uoeffective);
		fprintf(mod_dbg,"effectivelength = %g\n", leff);
		fprintf(mod_dbg,"xlambda = %g\n", xlambda);
		fprintf(mod_dbg,"beta = %g\n", beta);
		fprintf(mod_dbg,"ids = %g\n", ids);
		fprintf(mod_dbg,"ibs = %g\n", ibs);
		fprintf(mod_dbg,"ibd = %g\n", ibd);
		fprintf(mod_dbg,"isource = %g\n", isource);
		fprintf(mod_dbg,"idrain = %g\n", idrain);
	}



}



static double sig1[4] = {1.0, -1.0, 1.0, -1.0};
static double sig2[4] = {1.0,  1.0,-1.0, -1.0};



/* MOD_VDSAT_EQ () -  evaluate saturation voltage and its derivatives 
*     according to baum's theory of scattering velocity 
*     saturation
*/

double 
mod_vdsat_eq(mp, mosfet, getta, vetta, uoeffective, sphivbs3, vbsx)
struct mod_mosmodel_s *mp;
struct mod_mosfet_s *mosfet;
double getta;
double vetta;
double uoeffective;
double sphivbs3;
double vbsx;
{

int i, j;
int iknt, jknt;
double a4[4], b4[4];
double x4[8], poly4[8];

double v1, v2, xv;
double a1, b1, c1, d1;
double a, b, c, r, s, r3;
double s2, p, p0, p2;
double ro, fi, y3, p3, p4;
double a3, b3;
double del4;
double xvalid;
double vdsat;

	vdsat = 0.0;
	v1 = vetta + mp->phi - vbsx;
	v2 = mp->phi - vbsx;
	xv = (mp->vmax * mosfet->effectivelength) / uoeffective;
	a1 = getta/0.75;
	b1 = -2.0*(v1+xv);
	c1 = -2.0*getta*xv;
	d1 = 2.0*v1*(v2+xv)-(v2*v2)-(4.0/3.0)*getta * sphivbs3;
	a = -b1;
	b = a1*c1-4.0*d1;
	c = -d1*(a1*a1-4.0*b1)-c1*c1;
	r = -(a*a)/3.0+b;
	s = (2.0*a*a*a)/27.0-(a*b/3.0)+c;
	r3 = r*r*r;
	s2 = s*s;
	p = s2/4.0+r3/27.0;
	p0 = fabs(p);
	p2 = sqrt(p0);
	if (p <= 0.0) {
	    ro = sqrt(s2/4.0+p0);
	    ro = log(ro)/3.0;
	    ro = exp(ro);
	    fi = atan(-2.0*p2/s);
	    y3 = 2.0*ro*cos(fi/3.0)-a/3.0;
	} else {
	    p3 = exp(log(fabs(-s/2.0+p2))/3.0);
	    p4 = exp(log(fabs(-s/2.0-p2))/3.0);
	    y3 = p3+p4-a/3.0;
	}
	iknt = 0;
	a3 = sqrt(a1*a1/4.0-b1+y3);
	if ( fabs(y3*y3/4.0 -d1) < (1.0e-10 * d1))
	    b3 = 0.0;
	else
	    b3 = sqrt(y3*y3/4.0-d1);
	for(i = 0;i<=3;i++) {
	    a4[i] = a1/2.0+sig1[i]*a3;
	    b4[i] = y3/2.0+sig2[i]*b3;
	    del4 = a4[i]*a4[i]/4.0-b4[i];
	    if (del4 < 0.0) continue;
	    x4[iknt] = -a4[i]/2.0+sqrt(del4);
	    iknt = iknt+1;
	    x4[iknt] = -a4[i]/2.0-sqrt(del4);
	    iknt = iknt+1;
	}
	jknt = 0;
	for(j = 0;j<iknt;j++) {
	    if (x4[j] <= 0.0) continue;
	    poly4[j] = x4[j]*x4[j]*x4[j]*x4[j]+a1*x4[j]*x4[j]*x4[j];
	    poly4[j] = poly4[j]+b1*x4[j]*x4[j]+c1*x4[j]+d1;
	    if (fabs(poly4[j]) > 1.0e-6) continue;
	    if (jknt == 0) {
		xvalid = x4[j];
	    }
	    jknt = jknt+1;
	    if (x4[j] > xvalid)
		continue;
	    else {
		xvalid = x4[j];
		continue;
	    }
	}

	if (jknt > 0) 
	    vdsat = (xvalid * xvalid) + vbsx - mp->phi;
	else
	    vdsat = 0.0;


	return (vdsat);
}




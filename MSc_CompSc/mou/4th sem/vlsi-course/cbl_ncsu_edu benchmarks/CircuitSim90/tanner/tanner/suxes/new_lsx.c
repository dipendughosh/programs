/* Layer to go between suxxes and libmod.  Uses structures in "lsx.h"
   which correspond to common blocks in suxxes (smodel4.f)
*/

#include <math.h>
#include "sim.h"
#include "newmod.h"

#include "lsx.h"

struct mod_mosmodel_s *mp;

extern struct mod_mosmodel_s *mod_mos2_setup();
extern struct mod_mosfet_s   *mod_mos2_compute();
extern void   mod_mos2_eq();


/* mos_setup(temp)     - a fortran callable routine to perform the setup
			 for libmod
*/
void
mosetp_(temp)

double *temp;

{

	struct sp_mosmodel_s *spmodel;

	int dummy;

/* Allocate the model pointer */

	spmodel = (struct sp_mosmodel_s *)
		  sim_alloc(sizeof(struct sp_mosmodel_s),S_MOD);


	/* 'head' and 'modelname' are not filled in */


	if (param1_.Type == -1) 	/* PMOS */

		spmodel->modeltype = 1;	/* SP_PMOSTYPE */

	else				/* NMOS */

		spmodel->modeltype = 0; /*SP_NMOSTYPE */


	spmodel->level     = param1_.Lev;
	spmodel->vto	= param1_.Vtoi;
	spmodel->kp	= param1_.Xkpi;
	spmodel->gamma	= param1_.Gammai;
	spmodel->phi	= param1_.Phii;
	spmodel->lambda	= param1_.Xlamdi;
	spmodel->rd	= ZEROSET;
	spmodel->rs	= ZEROSET;
	spmodel->cbd	= ZEROSET;
	spmodel->cbs	= ZEROSET;
	spmodel->is	= ZEROSET;
	spmodel->pb	= ZEROSET;
	spmodel->cgso	= ZEROSET;
	spmodel->cgdo	= ZEROSET;
	spmodel->cgbo	= ZEROSET;
	spmodel->rsh	= ZEROSET;
	spmodel->cj	= ZEROSET;
	spmodel->mj	= ZEROSET;
	spmodel->cjsw	= ZEROSET;
	spmodel->mjsw	= ZEROSET;
	spmodel->js	= ZEROSET;
	spmodel->tox	= param1_.Toxi;
	spmodel->nsub	= param1_.Xnsubi;
	spmodel->nss	= param1_.Xnss;
	spmodel->nfs	= param1_.Xnfsi;
	spmodel->tpg	= param1_.Tpg;
	spmodel->xj	= param1_.Xji;
	spmodel->ld	= param1_.Xld;
	spmodel->uo	= param1_.Uoi;
	spmodel->ucrit	= param1_.Ucrit;
	spmodel->uexp	= param1_.Uexpi;
	spmodel->utra	= ZEROSET;
	spmodel->vmax	= param1_.Vmaxi;
	spmodel->neff	= param1_.Xneffi;
	spmodel->xqc	= ZEROSET;
	spmodel->kf	= ZEROSET;
	spmodel->af	= ZEROSET;
	spmodel->fc	= ZEROSET;
	spmodel->delta	= param1_.Deltai;
	spmodel->theta	= ZEROSET;
	spmodel->eta	= ZEROSET;
/*
	spmodel->theta	= param1_.Theta;
	spmodel->eta	= param1_.Eta;
*/
	spmodel->kappa	= param1_.Xkappa;

	mp     = mod_mos2_setup(spmodel, *temp);

/* Free up memory for spmodel.  mp needs to be saved */

	sim_free(spmodel, dummy);

}


/* Libeq2(vds,vbs,vgs) - this is a fortran callable routine to calculate 
*                         level 2 current  values
*/
void
libeq2_(vds,vbs,vgs, length, width)
double *vds;
double *vbs;
double *vgs;
double *length;
double *width;

{
	struct sp_mosfet_s    *spmosfet;
	struct mod_mosfet_s   *mosfet;

	double auxv[4];
	double auxi[4];

	int dummy;

/* Allocate the device pointer */

	spmosfet = (struct sp_mosfet_s *)
		   sim_alloc(sizeof(struct sp_mosfet_s),S_MOD);

	spmosfet->length = *length * 1.0E-6;
	spmosfet->width  = *width  * 1.0E-6;
	spmosfet->darea  = 0.0;
	spmosfet->sarea  = 0.0;
	spmosfet->dperim = 0.0;
	spmosfet->sperim = 0.0;
	spmosfet->nrd    = 0.0;
	spmosfet->nrs    = 0.0;

	mosfet = mod_mos2_compute(mp, spmosfet);

	auxv[0] = *vds - *vbs;
	auxv[1] = *vgs - *vbs;
	auxv[2] = (-1.0)*(*vbs);
	auxv[3] = 0.0;

	mod_mos2_eq(mp, mosfet, auxv, auxi);
	
	mosarg_.cdrain  = auxi[0];

/* Free up memory for spmosfet and mosfet */

	sim_free(spmosfet, dummy);
	sim_free(mosfet, dummy);
}


void
libeq1_(vds,vbs,vgs)
double *vds;
double *vbs;
double *vgs;

{
	printf("\nLevel 1 unavailable.\n");
}

void
libeq3_(vds,vbs,vgs)
double *vds;
double *vbs;
double *vgs;

{
	printf("\nLevel 3 unavailable.\n");
}


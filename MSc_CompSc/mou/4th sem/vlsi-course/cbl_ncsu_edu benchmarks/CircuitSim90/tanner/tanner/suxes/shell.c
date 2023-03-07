/*  lets leave this here for a little while ...
      subroutine moseq2(vds,vbs,vgs)
      implicit double precision (a-h,o-z) 
c 
c     this routine evaluates the drain current, its derivatives and 
c     the charges associated with the gate, channel and bulk
c     for mosfets 
c 
      common /result/ ueff,gammad,xleff,vbin,deltal,vth
      double precision phi,phib
      common /mosarg/ vto,beta,gamma,phi,phib,cox,xnsub,xnfs,xd,xj, 
     1   xlamda,uo,uexp,vbp,utra,vmax,xneff,xl,xw,vbi,von,vdsat,qspof,
     2   beta0,beta1,cdrain,xqco,xqc,fnarrw,fshort
      common /knstnt/ twopi,vt,charge,epssil,epsox,egfet,xni
*/
#include <math.h>
#include "sim.h"
#include "newmod.h"
struct resf77 {
       double ueff;
       double gammad;
       double xleff;
       double vbin;
       double deltal;
       double vth;
} result_;

struct mosf77 {
     double  vto;
     double  beta;
     double  gamma;
     double  phi;
     double  phib;
     double  cox;
     double  xnsub;
     double  xnfs;
     double  xd;
     double  xj;
     double xlamda;
     double uo;
     double uexp;
     double vbp;
     double utra;
     double vmax;
     double xneff;
     double xl;
     double xw;
     double vbi;
     double von;
     double vdsat;
     double qspof;
     double beta0;
     double beta1;
     double cdrain;
     double xqco;
     double xqc;
     double fnarrw;
     double fshort;
} mosarg_;

struct knstntf77 {
       double twopi;
       double vt;
       double charge;
       double epssil;
       double epsox;
       double egfet;
       double xni;
} knstnt_;

/* moseq2(vds,vbs,vgs) - this is a fortran callable routine to calculate 
*                         level 2 current  values
*/
void
moseq2_(vds,vbs,vgs)
double *vds;
double *vbs;
double *vgs;
{
struct mod_mosmodel_s *mp;
struct mod_mosmodel_s *mosfet;
	/*  lets make sure things are ok at this point */
	printf("calling voltages (vds,vbs,vgs) follow:\n\n");
	printf("%e %e %e\n",*vds,*vbs,*vgs);
	printf("some values passed into modlib follow:\n");
	printf("(beta0,phi,beta0,vth,vt )\n");
	printf("%e %e %e %e %e\n",
		mosarg_.beta0,
		mosarg_.phi,
		mosarg_.beta0,
		result_.vth,
		knstnt_.vt);
	/*  now, call the modlib routines */
	/*
	mp = sim_alloc(sizeof(struct mod_mosmodel_s),S_MOD);
	mosfet = sim_alloc(sizeof(struct mod_mosfet_s),S_MOD);
	mosfet=mod_mos2_setup(mp, temp);
	mod_mosfet_compute(mosfet, temp);
	mod_mos_eq2(mp,mosfet,auxv,auxi);
	*/
	/*  finally, copy the returned values back for suxes */
}
/* moseq1(vds,vbs,vgs) - this is a fortran callable routine to calculate 
*                         level 1 current  values
*/
void
moseq1_(vds,vbs,vgs)
double vds;
double vbs;
double vgs;
{
printf("whoops!! no level one, yet \n");
}

struct sp_mosmodel_s *sp;
/* moseq3(vds,vbs,vgs) - this is a fortran callable routine to calculate 
*                         level 3 current  values
*/
void
moseq3_(vds,vbs,vgs)
double vds;
double vbs;
double vgs;
{
printf("whoops!! no level three, yet \n");
}
mod_moscheck1.c:		sim_alloc(sizeof(struct mod_mosmodel_s),S_MOD);
mod_moscheck1.c:		sim_alloc(sizeof(struct mod_mosfet_s),S_MOD);

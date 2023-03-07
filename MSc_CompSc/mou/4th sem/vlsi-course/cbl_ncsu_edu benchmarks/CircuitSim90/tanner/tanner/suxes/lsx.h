/* Include file for going from suxxes common blocks to shell structures */

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

struct param1f77 {
	double Lev;
	double Type;
	double Xld;
	double Toxi;
	double Xnsubi;
	double Vtoi;
	double Xkpi;
	double Gammai;
	double Phii;
	double Uoi;
	double Uexpi;
	double Ucrit;
	double Deltai;
	double Vmaxi;
	double Xji;
	double Xlamdi;
	double Xkappa;
	double Xnfsi;
	double Xneffi;
	double Xnss;
	double Tpg;
	double Eta;
	double Theta;
	double dumy[7];
} param1_;


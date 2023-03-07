



**************************************************************************
**									**
**			( MODEL M125CN )				**
**									**
**	SPICE PARAMETERS						**
**	MCNC 1.25 CMOS PROCESS						**
**	( NOMINAL )							**
**									**
**	NOTE:	IV data was obtained with PISCES and fit to SPICE 	**
**		models with the curve fitting program SUXES.		**
**									**
**	Scott Goodwin-Johansson, Gary Nifong	02/26/87		**
**									**
**************************************************************************

.model nenh nmos
+    Level=2            Ld=0.0u         Tox=225.000e-10
+    Nsub=1.066e+16     Vto=0.622490    Kp=6.326640E-05
+    Gamma=.639243      Phi=.31         Uo=1215.74
+    Uexp=4.612355e-2   Ucrit=174667    Delta=0.0
+    Vmax=177269        Xj=.9u          Lambda=0.0
+    Nfs=4.55168e+12    Neff=4.68830    Nss=3.000000E+10
+    Tpg=1.00000        Rsh=60          Cgso=3.54e-10
+    Cgdo=3.54e-10      Cj=3.27e-04     Mj=1.067
+    Cjsw=1.74e-10      Mjsw=.195

*
*


Rd 1 2 20000
Rs 3 33 5000
Rb 5 55 1
Rg 4 10 1
R2 1 10 15000000
R1 10 0 10000000
M1 2 4 3 5 nenh l=1.0u w=10.0u ad=1.8p pd=1.4u as=1.8p ps=1.4u


VDD 1 0 13.0
VSS 33 0 0.0
VBB 55 0 0.0
VIN 4 0 1.5 AC 0.5 0.0
.ac dec 10 1MEG 10000MEG
.print ac ir(VBB) ii(VBB)
.options limpts=10000
.end




*AMPLIFIER OPEN LOOP GAIN
*
* CLASS AB OPAMP 
* NON-INVERTING INPUT node 2
* INVERTING INPUT     node 3
* AB OUTPUT 	      node 18
*
*
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
+    Tpg=1.00000        Rsh=60          Cgso=2.89e-10
+    Cgdo=2.89e-10      Cj=3.27e-04     Mj=1.067
+    Cjsw=1.74e-10      Mjsw=.195

.model penh pmos
+    Level=2            Ld=.03000000u   Tox=225.000e-10  
+    Nsub=6.575441e+16  Vto=-0.63025    Kp=2.635440E-05
+    Gamma=0.618101     Phi=.541111     Uo=361.941
+    Uexp=8.886957e-02  Ucrit=637449    Delta=0.0
+    Vmax=63253.3       Xj=0.112799u    Lambda=0.    
+    Nfs=1.668437e+11   Neff=0.64354    Nss=3.000000E+10
+    Tpg=-1.00000       Rsh=150         Cgso=3.35e-10
+    Cgdo=3.35e-10      Cj=4.75e-04     Mj=.341
+    Cjsw=2.23e-10      Mjsw=.307
*
*
 
VDD     1 0 5.0
VBIAS   2 0 2.5
*
m1 23 3  9 1 penh l=2.0u w=34u ad=136p as=136p
m2 24 2 10 1 penh l=2.0u w=34u ad=136p as=136p
m3  7 7  5 1 penh l=2.0u w=34u ad=136p as=136p
m4  8 8  6 1 penh l=2.0u w=34u ad=136p as=136p
m5 21 7 44 1 penh l=2.0u w=68u ad=272p as=272p
m6 12 8  4 1 penh l=2.0u w=68u ad=136p as=136p
*
m7   9  9  5 0 nenh l=2.0u w=34u ad=136p as=136p
m8  10 10  6 0 nenh l=2.0u w=34u ad=136p as=136p
m9  22  9  4 0 nenh l=2.0u w=68u ad=136p as=136p
m10 11 10 44 0 nenh l=2.0u w=68u ad=136p as=136p
*
m11 12 12 0 0 nenh l=2.4u w=80u ad=320p as=320p
m12 11 11 1 1 penh l=2.4u w=80u ad=136p as=136p
*
m13  7 23 0 0 nenh l=2.8u w=60u ad=240p as=240p
m14  8 24 0 0 nenh l=2.8u w=60u ad=136p as=136p
m15  9 13 1 1 penh l=2.8u w=60u ad=136p as=136p
m16 10 13 1 1 penh l=2.8u w=60u ad=136p as=136p
*
m17 17 21  0  0 nenh l=2.4u w=40u ad=160p as=160p
m18 17 17 16 16 penh l=2.8u w=42u ad=168p as=168p
m19 16 16  1  1 penh l=2.4u w=40u ad=136p as=136p
*
m20 14 14  0 0 nenh l=2.4u w=40u ad=136p as=136p
m21 15 15 14 0 nenh l=2.8u w=42u ad=136p as=136p
m22 15 22  1 1 penh l=2.4u w=40u ad=136p as=136p
*
m23 20 12  0 0 nenh l=2.4u w=80u ad=136p as=136p
m24 18 15 20 0 nenh l=2.8u w=84u ad=336p as=336p
m25 18 17 19 1 penh l=2.8u w=84u ad=136p as=136p
m26 19 11  1 1 penh l=2.4u w=80u ad=136p as=136p
*
m27 13 13 1 1 penh l=2.8u w=6u ad=24p as=24p
*
m28 21 21 0 0 nenh l=2.4u w=80u ad=136p as=136p
m29 22 22 1 1 penh l=2.4u w=80u ad=136p as=136p
m30 23 23 0 0 nenh l=2.8u w=60u ad=136p as=136p
m31 24 24 0 0 nenh l=2.8u w=60u ad=136p as=136p
*
c4 4 0 0.03p
c5 5 0 0.03p
c6 6 0 0.03p
c7 7 0 0.03p
c8 8 0 0.03p
c9 9 0 0.03p
c10 10 0 0.03p
c11 11 0 0.03p
c12 12 0 0.03p
c13 13 0 0.03p
c14 14 0 0.03p
c15 15 0 0.03p
c16 16 0 0.03p
c17 17 0 0.03p
c18 18 0 0.03p
c19 19 0 0.03p
c20 20 0 0.03p
c21 21 0 0.03p
c22 22 0 0.03p
c23 23 0 0.03p
c24 24 0 0.03p
c44 44 0 0.03p
*
RREF 13 0 450k
*
*
*
* INPUTS
VOFFSET 3 0 2.497 AC 1.00
*
*

.options acct limpts=100000 numdgt=6
.print AC vm(18) 
.ac DEC 10 1 10MEG
.end

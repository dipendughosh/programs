* CMOS SCHMITT TRIGGER with a small amount of feedback. 
*
*	This circuit exibits a small hysteresis curve.
*

**************************************************************************
**									**
**			( MODEL M125CW )				**
**									**
**	SPICE PARAMETERS						**
**	MCNC 1.25 CMOS PROCESS						**
**	( WORST )							**
**									**
**	NOTE:	IV data was obtained with PISCES and fit to SPICE 	**
**		models with the curve fitting program SUXES.		**
**									**
**	Scott Goodwin-Johansson, Gary Nifong	03/06/87		**
**									**
**************************************************************************

.model nenh nmos
+    Level=2            Ld=-0.168u       Tox=241.000e-10
+    Nsub=1.066e+16     Vto=0.7610      Kp=3.843E-05
+    Gamma=.639243      Phi=.31         Uo=790.
+    Uexp=4.612355e-2   Ucrit=174667    Delta=0.0
+    Vmax=177269        Xj=.9u          Lambda=0.0
+    Nfs=4.55168e+12    Neff=4.68830    Nss=3.000000E+10
+    Tpg=1.00000        Rsh=66          Cgso=3.54e-10
+    Cgdo=3.54e-10      Cj=3.43e-04     Mj=1.067
+    Cjsw=1.83e-10      Mjsw=.195	rd = 50	rs=100

.model penh pmos
+    Level=2            Ld=-.138000u    Tox=241.000e-10  
+    Nsub=6.575441e+16  Vto=-0.79000    Kp=1.601e-05
+    Gamma=0.618101     Phi=.541111     Uo=235.0
+    Uexp=8.886957e-02  Ucrit=637449    Delta=0.0
+    Vmax=637449        Xj=0.112799u    Lambda=0.    
+    Nfs=1.668437e+11   Neff=0.64354    Nss=3.000000E+10
+    Cjsw=2.34e-10      Mjsw=.307	rd = 50	rs=100
+    Tpg=-1.00000       Rsh=165         Cgso=4.01e-10
+    Cgdo=4.01e-10      Cj=4.99e-04     Mj=.341

*

* 1	vdd
* 2	ipmos
* 3	ipmos2
* 4	inmos
* 5	inmos2
* 6	out
* 7	in

mp1 2 7 1 1 penh l=1.0u w=10.0u
mp2 2 7 6 1 penh l=1.0u w=10.0u
mp3 2 6 3 1 penh l=1.0u w=2.0u
mp4 3 6 0 1 penh l=1.0u w=2.0u

mn1 6 7 4 0 nenh l=1.0u w=5.0u
mn2 4 7 0 0 nenh l=1.0u w=5.0u
mn3 4 6 5 0 nenh l=1.0u w=1.0u
mn4 5 6 1 0 nenh l=1.0u w=1.0u

VDD 1 0 5.0
VSRC 7 0 0.0
.print dc v(6) 
.dc VSRC 1.5 3.5 .001
*.dc VSRC 3.5 1.5 -.001
.option acct limpts=100000 
.end
 

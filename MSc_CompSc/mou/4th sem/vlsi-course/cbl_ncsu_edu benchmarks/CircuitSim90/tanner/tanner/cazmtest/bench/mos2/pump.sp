*MOS CHARGE PUMP
**************************************************************************
**                                             **
**               ( MODEL M125CN )                    **
**                                             **
**     LEVEL II MOSFET PARAMETERS                         **
**     MCNC 1.25 CMOS PROCESS                              **
**     ( NOMINAL )                                   **
**                                             **
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
md2 5 2 6 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
cn1 5 0 50f
cn2 6 0 50f

VNIN 2 0 pwl(    0.0ns 0.0 5.0ns  0.0 5.2ns  5.0 10.0ns 5.0
+               10.2ns 0.0 15.0ns 0.0 15.2ns 5.0 20.0ns 5.0
+               20.2ns 0.0 25.0ns 0.0 25.2ns 5.0 30.0ns 5.0
+               30.2ns 0.0 35.0ns 0.0 35.2ns 5.0 40.0ns 5.0
+               40.2ns 0.0 45.0ns 0.0 45.2ns 5.0 50.0ns 5.0
+               50.2ns 0.0 55.0ns 0.0 55.2ns 5.0 60.0ns 5.0
+               60.2ns 0.0 65.0ns 0.0 65.2ns 5.0 70.0ns 5.0
+               70.2ns 0.0 75.0ns 0.0 75.2ns 5.0 80.0ns 5.0
+               80.2ns 0.0 85.0ns 0.0 85.2ns 5.0 90.0ns 5.0
+               90.2ns 0.0 95.0ns 0.0 95.2ns 5.0 100.0ns 5.0)

.tran .2ns 100ns
.options limpts=10000 ITL5=100000
.print tran v(2) v(5) 
.end

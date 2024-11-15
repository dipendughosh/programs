*MOS 17 STAGE RING OSCILLATOR
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
vdd 1 0 3.0
mp1 3 2 1 1 penh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn1 3 2 0 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mp2 4 3 1 1 penh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn2 4 3 0 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mp3 5 4 1 1 penh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn3 5 4 0 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mp4 6 5 1 1 penh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn4 6 5 0 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mp5 7 6 1 1 penh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn5 7 6 0 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mp6 8 7 1 1 penh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn6 8 7 0 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mp7 9 8 1 1 penh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn7 9 8 0 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mp8 10 9 1 1 penh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn8 10 9 0 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mp9 11 10 1 1 penh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn9 11 10 0 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mp10 12 11 1 1 penh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn10 12 11 0 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u

mp11 13 12 1 1 penh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn11 13 12 0 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mp12 14 13 1 1 penh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn12 14 13 0 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mp13 15 14 1 1 penh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn13 15 14 0 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mp14 16 15 1 1 penh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn14 16 15 0 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mp15 17 16 1 1 penh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn15 17 16 0 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mp16 18 17 1 1 penh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn16 18 17 0 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mp17 2  18 1 1 penh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn17 2  18 0 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
c1 18 0 .1p

.tran .1ns 100ns
.options acct limpts=10000 ITL5=100000
.print tran v(2) v(5) 
.end


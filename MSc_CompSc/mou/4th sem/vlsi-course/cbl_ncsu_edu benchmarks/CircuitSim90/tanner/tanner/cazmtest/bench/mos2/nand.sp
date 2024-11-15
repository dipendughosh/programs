*MOS 15 INPUT  NAND GATE
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
vdd  1  0 3.0

VAP  20 0 PULSE ( 0.0 3.0 0 1E-9 1E-9 25E-9 50E-9 )
*
mp1  2  20 1 1 penh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mp2  2  20 1 1 penh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mp3  2  20 1 1 penh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mp4  2  20 1 1 penh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mp5  2  20 1 1 penh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mp6  2  20 1 1 penh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mp7  2  20 1 1 penh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mp8  2  20 1 1 penh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mp9  2  20 1 1 penh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mp10  2  20 1 1 penh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u

mn1 2  20 3 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn2 3  20 4 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn3 4  20 5 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn4 5  20 6 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn5 6  20 7 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn6 7  20 8 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn7 8  20 9 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn8 9  20 10 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn9 10 20 11 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn10 11 20 12 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn11 12 20 13 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn12 13 20 14 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn13 14 20 15 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn14 15 20 16 0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u
mn15 16 20 0  0 nenh l=1.25u w=5u ad=5p pd=6u as=5p ps=6u

.op
.tran .1n 100n
.options acct limpts=10000 ITL5=100000
.print tran v(20) v(2)
.end


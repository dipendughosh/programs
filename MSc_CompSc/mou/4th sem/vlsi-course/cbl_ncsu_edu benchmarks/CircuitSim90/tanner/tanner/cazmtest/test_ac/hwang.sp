**************************************************************************
**									**
**			( MODEL M125CB )				**
**									**
**	SPICE PARAMETERS						**
**	MCNC 1.25 CMOS PROCESS						**
**	( BEST )							**
**									**
**	NOTE:	IV data was obtained with PISCES and fit to SPICE 	**
**		models with the curve fitting program SUXES.		**
**									**
**	Scott Goodwin-Johansson, Gary Nifong	03/16/87		**
**									**
**************************************************************************

.model nenh nmos
+    Level=2            Ld=0.042u       Tox=197.000e-10
+    Nsub=1.066e+16     Vto=0.381       Kp=1.1601e-04
+    Gamma=.639243      Phi=.31         Uo=1957.00
+    Uexp=4.612355e-2   Ucrit=174667    Delta=0.0
+    Vmax=177269        Xj=.9u          Lambda=0.0
+    Nfs=4.55168e+12    Neff=4.68830    Nss=3.000000E+10
+    Tpg=1.00000        Rsh=60          Cgso=2.89e-10
+    Cgdo=2.89e-10      Cj=3.27e-04     Mj=1.067
+    Cjsw=1.74e-10      Mjsw=.195

.model penh pmos
+    Level=2            Ld=.197u        Tox=209.000e-10  
+    Nsub=6.575441e+16  Vto=-0.472      Kp=3.816E-05
+    Gamma=0.618101     Phi=.541111     Uo=488.0
+    Uexp=8.886957e-02  Ucrit=637449    Delta=0.0
+    Vmax=63253.3       Xj=0.112799u    Lambda=0.    
+    Nfs=1.668437e+11   Neff=0.64354    Nss=3.000000E+10
+    Tpg=-1.00000       Rsh=150         Cgso=3.35e-10
+    Cgdo=3.35e-10      Cj=4.75e-04     Mj=.341
+    Cjsw=2.23e-10      Mjsw=.307

*
*
.subckt INVERT1 1 2 3 4
mtwo 2 1 3 3 penh l=1.0u w=1200.0u ad=1200.0p pd=1202.0u as=1200.0p ps=1202.0u
mone 2 1 4 4 nenh l=1.0u w=800.0u ad=800.0p pd=802.0u as=800.0p ps=802.0u
.ends INVERT1

.subckt INVERT2 1 2 3 4
mtwo 2 1 3 3 penh l=1.0u w=40.0u ad=40.0p pd=42.0u as=40.0p ps=42.0u
mone 2 1 4 4 nenh l=1.0u w=20.0u ad=20.0p pd=22.0u as=20.0p ps=22.0u
.ends INVERT2

*	Transimission line section I
R11 10  71    0.1 
L11 71  1033  0.1N 
C11 1033  0   0.4P
R44 1033  31  0.1 
L44 31  103   0.1N 
C44 103  0    0.4P

*	Transimission line section II
R22 20  81    0.1 
L22 81  2033  0.1N 
C22 2033  0   0.4P
R55 2033  41  0.1 
L55 41  203   0.1N 
C55 203  0    0.4P

*	Transimission line section III
R33 30  91    0.1 
L33 91  3033  0.1N 
C33 3033  0   0.4P
R66 3033  51  0.1 
L66 51  303   0.1N 
C66 303  0    0.4P

* 	Capacitive and Inductive coupling
K1 L11 L22      .4
C801 1033 2033  .05p
K2 L22 L33      .4
C802 2033 3033  .05p
K3 L44 L55     .4
C803  103 203  .05p
K4 L55 L66     .4
C804  203 303  .05p


*	Drivers and receivers
X11 100 101 88 0 INVERT1
X12 104 105 88 0 INVERT2
X13 200 201 88 0 INVERT1
X14 204 205 88 0 INVERT2
X15 300 301 88 0 INVERT1
X16 304 305 88 0 INVERT2


* 	Driver and receiver loads
C101 101 0 0.4P
L101 101 10 0.1N
C10 10 0 0.4P

C103 103 0 0.4P
C104 104 0 0.4P
L103 103 104 0.1N
C105 105 0 0.1P

C201 201 0 0.4P
L201 201 20 0.1N
C20 20 0 0.4P

C203 203 0 0.4P
L203 203 204 0.1N
C204 204 0 0.4P
C205 205 0 0.1P

C301 301 0 0.4P
L301 301 30 0.1N
C30 30 0 0.4P

C303 303 0 0.4P
L303 303 304 0.1N
C304 304 0 0.4P
C305 305 0 0.1P


.OPTIONS LIMPTS=100000 CPTIME=100000 ITL4=20 ITL5=0 RELTOL=0.01
.IC V(100)=3 V(101)=0  V(300)=3 V(301)=0 

VDD 88  0 DC 3
V1S 100 0 DC 3
V3S 300 0 DC 3

*	
*	Ammeters
*
*VI88 88 888
*VI201 201 2011
*VI204 204 2044


VIN 200 0 1.0 AC 0.2 0.0
.ac lin 200 10MEG 10000MEG
.print ac  vm(201) vm(203) vm(204) vm(30) 
.options limpts=10000
.end




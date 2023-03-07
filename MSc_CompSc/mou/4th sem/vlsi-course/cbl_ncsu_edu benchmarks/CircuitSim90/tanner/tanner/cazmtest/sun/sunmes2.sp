* @(#)models	1.2 11/19/90
*
* These models were derived from files "models" and "skew.parameters"
* in the typical-typical case.  Parameters not needed by CAzM were
* deleted.
*
* Hspice's models were based on:
*	+ Meta-Software's variable saturation model (SAT=3)
*	+ Charge conserving, symmetric capacitor model (CAPOP=1)
*	+ Physically based method for area calculation (ACM=1)
*
* CAzM models are based on:
*	+ Statz model (SAT=2)
*	+ Artificial charge splitting capacitor model
*	+ SPICE method for area calculation (ACM=0)
*
* Created: 11/20/90 ryu
*

.model jfet15 njf 
+ vto=-0.479 beta=2.72e-04 is=3.88e-14 alpha=3.94 lambda=0.127 rs=0 rd=0
+ pb=0.8

.model jfet16 njf 
+ vto=-0.896 beta=3.08e-04 is=7.66e-14 alpha=3.91 lambda=0.037 rs=0 rd=0
+ pb=0.8

.model jfet19 njf 
+ vto=-0.819 beta=2.83e-04 is=1.10e-13 alpha=3.51 lambda=0.083 rs=0 rd=0
+ pb=0.8

.model jfet20 njf 
+ vto=-0.798 beta=3.14e-04 is=3.88e-14 alpha=3.94 lambda=0.127 rs=0 rd=0
+ pb=0.8

.model jfet04 njf 
+ vto=0.267 beta=3.56e-04 is=1.02e-14 alpha=6.53 lambda=0.072 rs=0 rd=0
+ pb=0.8

.model jfet10 njf 
+ vto=0.276 beta=3.78e-04 is=1.10e-14 alpha=6.28 lambda=0.091 rs=0 rd=0
+ pb=0.8
*
*
************************************************************************
* SIMULATION MODEL FOR 4-INPUT XOR
************************************************************************
.GLOBAL VBG
************************************************************************
* 1  Vdd
* 2  X1
* 4  X2
* 6  X3
* 8  X4
* 12 S1
************************************************************************
* PINLIST
************************************************************************
X_XOR1   100  2  4 23 XO2
X_XOR2   100  6  8 24 XO2
X_XOR3   100 23 24 12 XO2

************************************************************************
* INPUTS
************************************************************************
Vdd1     100  0  2
Vdd2     1  0  2
VBG     VBG 0  0.6

VX1     30  0  PULSE(0.0 0.65 200P 100P 100P 2000P 4000P)

VX2     32  0  PULSE(0.0 0.0 200P 100P 100P 2000P 4000P)

VX3     34  0  PULSE(0.0 0.0 200P 100P 100P 2000P 4000P)

VX4     36  0  PULSE(0.0 0.0 200P 100P 100P 2000P 4000P)

************************************************************************
* DRIVERS
************************************************************************
X1A   1 30 40 INV_10X400
X1B   1 40  2 INV_10X400
X2A   1 32 42 INV_10X400
X2B   1 42  4 INV_10X400
X3A   1 34 44 INV_10X400
X3B   1 44  6 INV_10X400
X4A   1 36 46 INV_10X400
X4B   1 46  8 INV_10X400

************************************************************************
* LOADS
************************************************************************
C1  23  0 75F
C2  24  0 75F
C5  12  0 75F
XLS1  1 12 200 INV_10X200
XLS2  1 12 201 INV_10X200
XLS3  1 12 202 INV_10X200


************************************************************************
* DCFL Subcircuits
************************************************************************
* 2-INPUT XOR
.SUBCKT XO2 1 2 3 4
* 1 = Vdd
* 2 = A1
* 3 = A2
* 4 = Z
J1  1  5  5  VBG jfet20 W=4.9U  L=2.3U
J2  5  2  0  VBG jfet04 W=26U   L=1.2U
J3  1  6  6  VBG jfet20 W=4.9U  L=2.3U
J4  6  3  0  VBG jfet04 W=26U   L=1.2U
J5  1  7  7  VBG jfet20 W=4.9U  L=2.3U
J6  7  5  0  VBG jfet04 W=26U   L=1.2U
J7  7  6  0  VBG jfet04 W=26U   L=1.2U
J8  1  8  8  VBG jfet20 W=4.9U  L=2.3U
J9  8  3  0  VBG jfet04 W=26U   L=1.2U
J10 8  2  0  VBG jfet04 W=26U   L=1.2U
J11 1  4  4  VBG jfet20 W=4.9U  L=2.3U
J12 4  7  0  VBG jfet04 W=26U   L=1.2U
J13 4  8  0  VBG jfet04 W=26U   L=1.2U
.ENDS

************************************************************************
* INVERTER
.SUBCKT INV_10X200 1 2 3
* 1 = Vdd
* 2 = IN
* 3 = OUT
J1  1  3  3  VBG  jfet20 W=3.5U  L=2.3U
J2  3  2  0  VBG  jfet04 W=18.3U L=1.2U
.ENDS

************************************************************************
* INVERTER
.SUBCKT INV_10X400 1 2 3
* 1 = Vdd
* 2 = IN
* 3 = OUT
J1  1  3  3  VBG  jfet20 W=7.0U  L=2.3U
J2  3  2  0  VBG  jfet04 W=36.5U L=1.2U
.ENDS
************************************************************************

************************************************************************
* COMMANDS
************************************************************************
.TRANS 20P 5N
.PRINT TRAN V(30) V(32) V(34) V(36) V(12)
************************************************************************

.END


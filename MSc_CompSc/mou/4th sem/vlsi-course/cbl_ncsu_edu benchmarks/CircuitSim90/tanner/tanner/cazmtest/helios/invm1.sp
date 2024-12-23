*** Inverter to test multiplier **
.model jfet20 njf 
+ vgexp=2.55 alpha=3.94 ucrit=0.051 lambda=0.127 satexp=3.68
+ ng=0.595 nd=0.100 k1=0.204 eg=876e-03 gap1=1e-06 gap2=10 d=13.1 
+ level=3 capop=1 sat=3
+ acm=1 hdif=2.615u rshl=0 rs=0 rd=0 xti=2 tlev=2 
+ trs=2.24e-03 trd=2.24e-03 bex=481e-03 tcv=290e-06
+ gcap=1.495e-03 crat=.1109
+ vto=-0.779 beta=2.72e-04 rsh=765 gamds=-0.006 is=3.88e-2 n=1.210 ldel=-0.385u

.model jfet04 njf 
+ vgexp=2.35 alpha=6.53 ucrit=1e-4 lambda=0.072 satexp=3.29
+ ng=0.961 nd=0.100 k1=0.224 eg=917e-03 gap1=1e-06 gap2=10 d=13.1
+ level=3 capop=1 sat=3
+ acm=1 hdif=0.815u rshl=0 rs=0 rd=0 xti=2 tlev=2 
+ trs=-1.17e-03 trd=-1.17e-03 bex=-2 tcv=1.64e-03
+ gcap=1.062e-03 crat=.1109
+ vto=0.227 beta=3.02e-04 rsh=2171 gamds=-0.041 is=1.02e-2 n=1.227 ldel=-0.385u

.SUBCKT XO2 1 2 3 4 VBG
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
.SUBCKT INV_10X200 1 2 3 VBG
* 1 = Vdd
* 2 = IN
* 3 = OUT
J1  1  3  3  VBG  jfet20 W=3.5U  L=2.3U M=1
J2  3  2  0  VBG  jfet04 W=18.3U L=1.2U M=1
.ENDS
.SUBCKT INV_10X400 1 2 3 VBG
* 1 = Vdd
* 2 = IN
* 3 = OUT
J1  1  3  3  VBG  jfet20 W=7.0U  L=2.3U M=1
J2  3  2  0  VBG  jfet04 W=36.5U L=1.2U M=1
.ENDS

************************************************************************
* PINLIST
************************************************************************

************************************************************************
* INPUTS
************************************************************************
Vdd     1  0  2
VBG     VBG 0  0.6

VX1     30  0  PULSE(0.0 0.65 200P 100P 100P 2000P 4000P)

************************************************************************
* DRIVERS
************************************************************************
X1A   1 30 31 VBG INV_10X400
X1B   1 31 32 VBG INV_10X400
X2A   1 32 33 VBG INV_10X400
X2B   1 33 34 VBG INV_10X400
X3A   1 34 35 VBG INV_10X400
X3B   1 35 36 VBG INV_10X400
X4A   1 36 37 VBG INV_10X400
X4B   1 37 38 VBG INV_10X400

************************************************************************
* LOADS
************************************************************************
*C1  23  0 75F
*C2  24  0 75F
*C5  12  0 75F
**C1  23  0 5F
**C2  24  0 5F
**C5  12  0 5F

.tran 20P 5N
.print tran v(30) v(32) v(34) v(36) v(38)
.options ingold=2 co=132

.END

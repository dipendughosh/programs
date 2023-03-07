* typical typical models
.model jfet15 njf 
+ vto=-0.460 beta=2.72e-04 rsh=765 gamds=-0.006 is=3.88e-2 n=1.210 ldel=-0.385u
+ vgexp=2.55 alpha=3.94 ucrit=0.051 lambda=0.127 satexp=3.68
+ ng=0.595 nd=0.100 k1=0.204 eg=876e-03 gap1=1e-06 gap2=10 d=13.1 
+ gcap=1.495e-03 crat=.1109
+ level=3 capop=1 sat=3
+ acm=1 hdif=2.615u rshl=0 rs=0 rd=0 xti=2 tlev=2 
+ trs=2.24e-03 trd=2.24e-03 bex=481e-03 tcv=290e-06

.model jfet16 njf 
+ vto=-0.871 beta=2.65e-04 rsh=1315 gamds=-0.075 is=7.66e-2 n=1.373 ldel=-0.385u
+ vgexp=2.04 alpha=3.91 ucrit=0.88 lambda=0.037 satexp=2.58
+ ng=0.892 nd=0.100 k1=0.295 eg=865e-03 gap1=1e-06 gap2=10 d=13.1 
+ gcap=1.495e-03 crat=.1109
+ level=3 capop=1 sat=3
+ acm=1 hdif=0.815u rshl=0 rs=0 rd=0 xti=2 tlev=2 
+ trs=548e-06 trd=548e-06 bex=-249e-03 tcv=599e-06

.model jfet19 njf 
+ vto=-0.798 beta=2.43e-04 rsh=850 gamds=-0.041 is=1.10e-1 n=1.315 ldel=-0.385u
+ vgexp=2.15 alpha=3.51 ucrit=0.176 lambda=0.083 satexp=2.92
+ ng=0.797 nd=0.100 k1=0.288 eg=845e-03 gap1=27e-06 gap2=210 d=13.1 
+ gcap=1.495e-03 crat=.1109
+ level=3 capop=1 sat=3
+ acm=1 hdif=1.615u rshl=0 rs=0 rd=0 xti=2 tlev=2 
+ trs=3.22e-03 trd=3.22e-03 bex=155e-03 tcv=882e-06

.model jfet20 njf 
+ vgexp=2.55 alpha=3.94 ucrit=0.051 lambda=0.127 satexp=3.68
+ ng=0.595 nd=0.100 k1=0.204 eg=876e-03 gap1=1e-06 gap2=10 d=13.1 
+ level=3 capop=1 sat=3
+ acm=1 hdif=2.615u rshl=0 rs=0 rd=0 xti=2 tlev=2 
+ trs=2.24e-03 trd=2.24e-03 bex=481e-03 tcv=290e-06
+ gcap=1.495e-03 crat=.1109 b=1.26
+ vto=-0.779 beta=2.72e-04 rsh=765 gamds=-0.006 is=3.88e-2 n=1.210 ldel=-0.385u
*+ vto=-0.779 beta=2.72e-04 rsh=0 gamds=-0.006 is=3.88e-2 n=1.210 ldel=-0.385u

.model jfet04 njf 
+ vgexp=2.35 alpha=6.53 ucrit=1e-4 lambda=0.072 satexp=3.29
+ ng=0.961 nd=0.100 k1=0.224 eg=917e-03 gap1=1e-06 gap2=10 d=13.1
+ level=3 capop=1 sat=3
+ acm=1 hdif=0.815u rshl=0 rs=0 rd=0 xti=2 tlev=2 
+ trs=-1.17e-03 trd=-1.17e-03 bex=-2 tcv=1.64e-03
+ gcap=1.062e-03 crat=.1109 b=1.26
+ vto=0.227 beta=3.02e-04 rsh=2171 gamds=-0.041 is=1.02e-2 n=1.227 ldel=-0.385u
*+ vto=0.227 beta=3.02e-04 rsh=0 gamds=-0.041 is=1.02e-2 n=1.227 ldel=-0.385u

.model jfet10 njf 
+ vto=0.236 beta=3.27e-04 rsh=1820 gamds=-0.024 is=1.10e-2 n=1.215 ldel=-0.385u
+ vgexp=2.00 alpha=6.28 ucrit=1e-4 lambda=0.091 satexp=3.01
+ ng=0.937 nd=0.100 k1=0.289 eg=946e-03 gap1=1e-06 gap2=10 d=13.1 
+ gcap=1.062e-03 crat=.1109
+ level=3 capop=1 sat=3
+ acm=1 hdif=1.115u rshl=0 rs=0 rd=0 xti=2 tlev=2 
+ trs=6.1e-03 trd=6.1e-03 bex=500e-03 tcv=476e-06

.model dio16 njf 
+ rsh=1883 is=3.61e-2 n=1.253 ldel=-0.385u
+ eg=831e-03 gap1=54e-06 gap2=210 d=13.1
+ gcap=1.495e-03 crat=.1109
+ level=3 capop=1 sat=3
+ acm=1 hdif=0.815u rshl=0 rs=0 rd=0 
+ xti=2 tlev=2
+ trs=-1.98e-03 trd=-1.98e-03 

.model dio19 njf 
+ rsh=917 is=8.00e-2 n=1.225 ldel=-0.385u
+ eg=821e-03 gap1=232e-06 gap2=210 d=13.1 
+ gcap=1.495e-03 crat=.1109
+ level=3 capop=1 sat=3
+ acm=1 hdif=1.615u rshl=0 rs=0 rd=0 
+ xti=2 tlev=2
+ trs=-1.79e-03 trd=-1.79e-03 

.model dio20 njf 
+ rsh=589 is=4.68e-2 n=1.220 ldel=-0.385u
+ eg=814e-03 gap1=305e-06 gap2=210 d=13.1 
+ gcap=1.495e-03 crat=.1109
+ level=3 capop=1 sat=3
+ acm=1 hdif=2.615u rshl=0 rs=0 rd=0 
+ xti=2 tlev=2
+ trs=-1.78e-03 trd=-1.78e-03 

.model dio04 njf 
+ rsh=2748 is=1.38e-2 n=1.207 ldel=-0.385u
+ eg=848e-03 gap1=319e-06 gap2=10 d=13.1 
+ gcap=1.062e-03 crat=.1109
+ level=3 capop=1 sat=3
+ acm=1 hdif=0.815u rshl=0 rs=0 rd=0 
+ xti=2 tlev=2
+ trs=-1.68e-03 trd=-1.68e-03

.model dio10 njf 
+ rsh=2080 is=1.29e-2 n=1.205 ldel=-0.385u
+ eg=840e-03 gap1=333e-06 gap2=210 d=13.1 
+ gcap=1.062e-03 crat=.1109
+ level=3 capop=1 sat=3
+ acm=1 hdif=1.115u rshl=0 rs=0 rd=0 
+ xti=2 tlev=2
+ trs=-1.34e-03 trd=-1.34e-03 

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
J1  1  3  3  VBG  jfet20 W=3.5U  L=2.3U M=2
J2  3  2  0  VBG  jfet04 W=18.3U L=1.2U M=2
.ENDS
.SUBCKT INV_10X400 1 2 3 VBG
* 1 = Vdd
* 2 = IN
* 3 = OUT
J1  1  3  3  VBG  jfet20 W=7.0U  L=2.3U M=2
J2  3  2  0  VBG  jfet04 W=36.5U L=1.2U M=2
.ENDS

*
*
************************************************************************
* SIMULATION MODEL FOR 4-INPUT XOR
************************************************************************
*.GLOBAL VBG
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
X_XOR1   100  2  4 23 VBG XO2
X_XOR2   100  6  8 24 VBG XO2
X_XOR3   100 23 24 12 VBG XO2

************************************************************************
* INPUTS
************************************************************************
Vdd1     100 0 2
Vdd2     1  0  2
VBG     VBG 0  0.6

VX1     30  0  PULSE(0.0 0.65 200P 100P 100P 2000P 4000P)

VX2     32  0  PULSE(0.0 0.0 200P 100P 100P 2000P 4000P)

VX3     34  0  PULSE(0.0 0.0 200P 100P 100P 2000P 4000P)

VX4     36  0  PULSE(0.0 0.0 200P 100P 100P 2000P 4000P)





************************************************************************
* DRIVERS
************************************************************************
X1A   1 30 40 VBG INV_10X400
X1B   1 40  2 VBG INV_10X400
X2A   1 32 42 VBG INV_10X400
X2B   1 42  4 VBG INV_10X400
X3A   1 34 44 VBG INV_10X400
X3B   1 44  6 VBG INV_10X400
X4A   1 36 46 VBG INV_10X400
X4B   1 46  8 VBG INV_10X400

************************************************************************
* LOADS
************************************************************************
*C1  23  0 75F
*C2  24  0 75F
*C5  12  0 75F
**C1  23  0 5F
**C2  24  0 5F
**C5  12  0 5F
XLS1  1 12 200 VBG INV_10X200
XLS2  1 12 201 VBG INV_10X200
XLS3  1 12 202 VBG INV_10X200


************************************************************************
* DCFL Subcircuits
************************************************************************
* 2-INPUT XOR

************************************************************************
* INVERTER

************************************************************************
* INVERTER
************************************************************************

************************************************************************
* COMMANDS
************************************************************************
************************************************************************


*transient 5N 
.tran 20P 5N
*plot { v(2) V(4) V(6) V(8) V(12)}
.print tran v(2) v(12)
.options ingold=2
*plot mtest.out { v(2) V(4) V(6) V(8) V(12)}
*gridsize mes 90 90 40
*options chargetol=1.0e-16

.END

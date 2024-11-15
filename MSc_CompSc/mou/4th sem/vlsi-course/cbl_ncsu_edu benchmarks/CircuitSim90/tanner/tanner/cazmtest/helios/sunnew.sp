*** simple inverter for CAzM GaAs verification ***

* typical typical models

.model mfet15 njf 
+ vto=-0.460 beta=2.72e-04 rsh=765 gamds=-0.006 is=3.88e-2 n=1.210 ldel=-0.385u
+ vgexp=2.55 alpha=3.94 ucrit=0.051 lambda=0.127 satexp=3.68
+ ng=0.595 nd=0.100 k1=0.204 eg=876e-03 gap1=1e-06 gap2=10 d=13.1 
+ gcap=1.495e-03 crat=.1109
+ level=3 capop=1 sat=3
+ acm=1 hdif=2.615u rshl=0 rs=0 rd=0 xti=2 tlev=2 
+ trs=2.24e-03 trd=2.24e-03 bex=481e-03 tcv=290e-06

.model mfet04 njf 
+ vto=0.227 beta=3.02e-04 rsh=2171 gamds=-0.041 is=1.02e-2 n=1.227 ldel=-0.385u
+ vgexp=2.35 alpha=6.53 ucrit=1e-4 lambda=0.072 satexp=3.29
+ ng=0.961 nd=0.100 k1=0.224 eg=917e-03 gap1=1e-06 gap2=10 d=13.1
+ gcap=1.062e-03 crat=.1109
+ level=3 capop=1 sat=3
+ acm=1 hdif=0.815u rshl=0 rs=0 rd=0 xti=2 tlev=2 
+ trs=-1.17e-03 trd=-1.17e-03 bex=-2 tcv=1.64e-03

.subckt inv 10 11 99 98 EBulk DBulk
jm1 11 10 99 EBulk mfet04 w=50u l=5u
jm2 98 11 11 DBulk mfet15 w=5u  l=5u
c2 11 99 10f
.ends inv

*
*	Seven stage ring oscillator with a load at node (a7)
* 

* DCFL inverter, 10:1 E/D ratio

xinv1 1 2 99 98 EBulk DBulk inv
xinv2 2 3 99 98 EBulk DBulk inv
xinv3 3 4 99 98 EBulk DBulk inv
xinv4 4 5 99 98 EBulk DBulk inv
xinv5 5 6 99 98 EBulk DBulk inv
xinv6 6 7 99 98 EBulk DBulk inv
xinv7 7 1 99 98 EBulk DBulk inv
cinv1 7 99 10f

Vdd 98 0 2.0
VGND 99 0 0.0
Vbias1 EBulk 0 1.0
Vbias2 DBulk 0 1.0

.PRINT TRAN V(1) V(2) V(3) V(4) V(5) V(6) V(7) 
.TRANS 20P 5N
.END

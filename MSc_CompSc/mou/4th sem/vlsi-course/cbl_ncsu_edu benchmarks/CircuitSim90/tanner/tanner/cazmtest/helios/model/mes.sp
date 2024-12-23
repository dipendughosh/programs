*** MESFET model development runs
.model mfet15 njf 
+ vto=-0.460 beta=2.72e-04 rsh=765 gamds=-0.006 is=3.88e-2 n=1.210 ldel=-0.385u
+ vgexp=2.55 alpha=3.94 ucrit=0.051 lambda=0.127 satexp=3.68
+ ng=0.595 nd=0.100 k1=0.204 eg=876e-03 gap1=1e-06 gap2=10 d=13.1 
+ gcap=1.495e-03 crat=.1109
+ level=3 capop=1 sat=3
+ acm=1 hdif=2.615u rshl=0 rs=0 rd=0 xti=2 tlev=2 
+ trs=2.24e-03 trd=2.24e-03 bex=481e-03 tcv=290e-06

.model mfet16 njf 
+ vto=-0.871 beta=2.65e-04 rsh=1315 gamds=-0.075 is=7.66e-2 n=1.373 ldel=-0.385u
+ vgexp=2.04 alpha=3.91 ucrit=0.88 lambda=0.037 satexp=2.58
+ ng=0.892 nd=0.100 k1=0.295 eg=865e-03 gap1=1e-06 gap2=10 d=13.1 
+ gcap=1.495e-03 crat=.1109
+ level=3 capop=1 sat=3
+ acm=1 hdif=0.815u rshl=0 rs=0 rd=0 xti=2 tlev=2 
+ trs=548e-06 trd=548e-06 bex=-249e-03 tcv=599e-06

.model mfet19 njf 
+ vto=-0.798 beta=2.43e-04 rsh=850 gamds=-0.041 is=1.10e-1 n=1.315 ldel=-0.385u
+ vgexp=2.15 alpha=3.51 ucrit=0.176 lambda=0.083 satexp=2.92
+ ng=0.797 nd=0.100 k1=0.288 eg=845e-03 gap1=27e-06 gap2=210 d=13.1 
+ gcap=1.495e-03 crat=.1109
+ level=3 capop=1 sat=3
+ acm=1 hdif=1.615u rshl=0 rs=0 rd=0 xti=2 tlev=2 
+ trs=3.22e-03 trd=3.22e-03 bex=155e-03 tcv=882e-06

.model mfet20 njf 
+ vto=-0.779 beta=2.72e-04 rsh=765 gamds=-0.006 is=3.88e-2 n=1.210 ldel=-0.385u
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

.model mfet10 njf 
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

j01 d g s b01 mfet04 w=50u l=5u
j02 d g s b02 mfet04 w=50u l=5u
j03 d g s b03 mfet04 w=50u l=5u
j04 d g s b04 mfet04 w=50u l=5u
j05 d g s b05 mfet04 w=50u l=5u
j06 d g s b06 mfet04 w=50u l=5u

vd	d	0	0.0
vg	g	0	0.5
vs	s	0	0.0
vb01	b01	0	-0.6
vb02	b02	0	-0.4
vb03	b03	0	-0.2
vb04	b04	0	0.2
vb05	b05	0	0.4
vb06	b06	0	0.6

.dc vd 0.0 2.0 0.05 vg 0.0 0.7 0.1
.print dc i1(j01) i1(j02) i1(j03) i1(j04) i1(j05) i1(j06)
.options ingold=2 co=132
.end

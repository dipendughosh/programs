Test for charge model in HSPICE
*
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
*
j1 d g s b jfet04 w=50u l=5u
*
vd d 0 0.0
vg g 0 0.0
vs s 0 0.0
vb b 0 0.6
*
.dc vd 0 2 0.02 vg 0 0.7 0.1
*.print v(d) v(g) lx9(j1) lx11(j1)
.print lx9(j1) lx11(j1)
.options dccap ingold=2
.end

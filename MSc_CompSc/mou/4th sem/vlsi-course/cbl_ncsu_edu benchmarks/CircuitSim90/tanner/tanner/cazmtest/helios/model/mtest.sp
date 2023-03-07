*** Model test for subthreshold characterisitics ***
.model mtest njf level=3 capop=1 sat=3 acm=1
+ vto=0.5 beta=3.0e-04 ng=0.0 nd=0.0 satexp=3 lambda=0.0
+ ucrit=0 vgexp=2.00 alpha=0 gamds=0.0
+ k1=0.5 eg=917e-03 gap1=1e-06 gap2=10
+ gcap=1.062e-03 crat=.1109
+ rsh=0 rshg=0 rshl=0 rs=0 rd=0
+ xti=2 tlev=2 trs=-1.17e-03 trd=-1.17e-03 bex=-2 tcv=1.64e-03

j01 1 2 3 4 mtest w=50u l=5u

vd01	1	0	2.0
vg01	2	0	0.5
vs01	3	0	0.0
vb01	4	0	0.0

.dc vb01 0.0 1.0 0.1
*.dc vd01 0.0 2.0 0.1 vg01 0.0 0.3 0.1
.print dc i(vd01)
.options ingold=2
.end

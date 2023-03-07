
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
*	Seven stage ring oscillator with a load at node (a7)
* 
*
* DCFL inverter, 10:1 E/D ratio
.subckt inv 10 11 99 98
jm1 11 10 99 jfet04 10
jm2 98	11 11 jfet16 1
c2 11 99 10f
.ends inv

xinv1 1 2 99 98 inv
xinv2 2 3 99 98 inv
xinv3 3 4 99 98 inv
xinv4 4 5 99 98 inv
xinv5 5 6 99 98 inv
xinv6 6 7 99 98 inv
xinv7 7 1 99 98 inv
cinv1 7 99 10f

Vdd 98 0 2.0
VGND 99 0 0.0
.PRINT TRAN V(1) V(2) V(3) V(4) V(5) V(6) V(7) 
.TRANS 20P 5N
.END

* gm6.ckt
.model nrad6 nmos(
+ vto    =  8.86298e-1
+ uo     =  5.05739e+2
+ nsub   =  6.47532e+16
+ ucrit  =  3.06080e+5
+ uexp   =  6.50268e-1
+ lambda =  1.47924e-2
+ tox    =  4.50000e-8
+ xj     =  6.00000e-7
+ tpg    =  1.00000e+0
+ js     =  1.00000e-7
+ cj     =  4.00000e-4
+ pb     =  9.20000e-1
+ rd     =  4.75000e+0
+ rs     =  4.75000e+0
+ level  =  2)
*
.model prad6 pmos(
+ vto    = -1.27110e+0
+ uo     =  1.89514e+2
+ nsub   =  4.57476e+15
+ uexp   =  5.83290e-1
+ lambda =  2.61855e-2
+ ucrit  =  1.20248e+5
+ tox    =  4.50000e-8
+ xj     =  6.00000e-7
+ tpg    = -1.00000e+0
+ js     =  1.00000e-7
+ cj     =  1.30000e-4
+ pb     =  9.00000e-1
+ rd     =  6.92000e+0
+ rs     =  6.92000e+0
+ level  =  2)
*
vdd 10 0 5
vnen 2 0 0
vin 5 0  pulse(0 5 1ns 5ns 5ns 45ns 100ns)

.options acct itl5=0 cptime=5000

.temp 125
.op
.tran .5ns 100ns
mp2 11 2  10 10 prad6 w=56u l=3u ad=504p as=504p
mp3 12 5  11 10 prad6 w=21u l=6u ad=189p as=189p
mp4 7  5  12 10 prad6 w=21u l=6u ad=189p as=189p
mn3 13 5  0  0  nrad6 w=7u  l=6u ad=63p  as=63p
mn4 7  5  13 0  nrad6 w=7u  l=6u ad=63p  as=63p

.print tran v(2) v(5) v(7)
.print tran v(10) v(11) v(12) v(13)

.end

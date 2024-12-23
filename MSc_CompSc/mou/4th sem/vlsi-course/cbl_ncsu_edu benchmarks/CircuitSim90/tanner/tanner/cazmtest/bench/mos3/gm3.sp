*file: gm3.ckt
.model pn4a pmos(
+ vto        = -1.26e+00
+ uo         =  1.68e+02
+ kappa      =  2.00e-02
+ eta        =  2.02e+00
+ theta      =  7.77e-02
+ vmax       =  7.95e+05
+ delta      =  7.03e-01
+ nsub       =  2.39e+15
+ tox        =  4.50e-08
+ tpg        = -1.00e+00
+ xj         =  6.00e-07
+ js         =  1.000e-07     cj=     1.300e-04     pb=    0.900e-00
+ rs         =  6.920e+00     rd=     6.920e+00     level= 3)
* seq. #:   50 process: b4506ap 3153 wafer: 18 loc: 18; 51 date: 10jan83
.model nn4a nmos(
+ vto        =  9.25e-01
+ uo         =  6.34e+02
+ kappa      =  2.00e-02
+ eta        =  1.45e+00
+ theta      =  6.96e-02
+ vmax       =  3.66e+05
+ delta      =  7.23e+00
+ nsub       =  3.43e+16
+ tox        =  4.50e-08
+ tpg        =  1.00e+00
+ xj         =  6.00e-07
+ js         =  1.000e-07     cj=     4.000e-04     pb=    0.920e-00
+ rs         =  4.750e+00     rd=     4.750e+00     level= 3)
* seq. #:   25 process: b3908an 3123 wafer: 19 loc: 13; 87 date: 14may82
* 27 may 83
*
vcc 10 0 5v
vin 1 0 pulse (0 5 5n 2n 2n 20n 50n)
*
x1 2 60 10 10 nand2
x2 60 50 40 30 10 10 nand4
x3 30 1 1 10 nand2
x4 40 1 1 1 10 nand3
x5 50 1 1 1 10 10 nand4
c2 2 0 0.5p
*
.subckt nand2 3 1 2 10
* nodes: out in1 in2 vdd
mp1 3 1 10 10 pn4a w=50u l=3u ad=400p as=400p
mp2 3 2 0 10  pn4a w=50u l=3u ad=400p as=400p
mn1 3 1 4 0   nn4a w=20u l=3u ad=160p as=160p
mn2 4 2 0 0   nn4a w=20u l=3u ad=160p as=160p
.ends nand2
*
.subckt nand4 5 1 2 3 4 10
mp1 5 1 10 10 pn4a w=50u l=3u ad=400p as=400p
mp2 5 2 10 10 pn4a w=50u l=3u ad=400p as=400p
mp3 5 3 10 10 pn4a w=50u l=3u ad=400p as=400p
mp4 5 4 10 10 pn4a w=50u l=3u ad=400p as=400p
mn1 5 1  8  0 nn4a w=50u l=3u ad=400p as=400p
mn2 8 2  7  0 nn4a w=50u l=3u ad=400p as=400p
mn3 7 3  6  0 nn4a w=50u l=3u ad=400p as=400p
mn4 6 4  0  0 nn4a w=50u l=3u ad=400p as=400p
.ends nand4
*
.subckt nand3 4 1 2 3 10
mp1 4 1 10 10 pn4a w=50u l=3u ad=400p as=400p
mp2 4 2 10 10 pn4a w=50u l=3u ad=400p as=400p
mp3 4 3 10 10 pn4a w=50u l=3u ad=400p as=400p
mn1 4 1 8  0  nn4a w=50u l=3u ad=400p as=400p
mn2 8 2 7  0  nn4a w=50u l=3u ad=400p as=400p
mn3 7 3 0  0  nn4a w=50u l=3u ad=400p as=400p
.ends nand3
*
.options acct
.op
.tran .5ns 50ns

.print tran v(30) v(40) v(50) v(60)
.end

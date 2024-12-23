*clock amp and divider circuit  11/7/83
.model pn4a pmos(
+ vto        = -1.28e+00
+ uo         =  2.24e+02
+ kappa      =  2.00e-02
+ eta        =  2.48e+00
+ theta      =  9.81e-02
+ vmax       =  1.24e+06
+ delta      =  5.01e-01
+ nsub       =  2.95e+15
+ tox        =  4.50e-08
+ tpg        = -1.00e+00
+ xj         =  6.00e-07
+ js         =  1.000e-07     cj=     1.300e-04     pb=    0.900e-00
+ rs         =  6.700e+00     rd=     6.700e+00     level= 3)
* seq. #:   22 process: b3908ap 3153 wafer: 19 loc: 13; 81 date: 14may82
.model nn4a nmos(
+ vto        =  8.95e-01
+ uo         =  7.26e+02
+ kappa      =  2.00e-02
+ eta        =  1.41e+00
+ theta      =  3.08e-02
+ vmax       =  1.92e+05
+ delta      =  6.90e+00
+ nsub       =  3.52e+16
+ tox        =  4.50e-08
+ tpg        =  1.00e+00
+ xj         =  6.00e-07
+ js         =  1.000e-07     cj=     4.000e-04     pb=    0.920e-00
+ rs         =  2.940e+00     rd=     2.940e+00     level= 3)
* seq. #:   45 process: b4506an 3123 wafer: 18 loc: 18; 50 date: 10jan83
.subckt e1240 8 1 2 3 4 9
*
* 4 um:  4 input nand gate
*
* i/o nodes: out i1 i2 i3 i4 vdd
*  out          8
*  i1           1
*  i2           2
*  i3           3
*  i4           4
*  vdd          9
*
*  may 17, 1982
*  revised: august 17, 1982
*
mn1 5 4 0 0 nn4a l=3u w=23u as=207p ad=207p
mn2 6 3 5 0 nn4a l=3u w=23u as=207p ad=207p
mn3 7 2 6 0 nn4a l=3u w=23u as=207p ad=207p
mn4 8 1 7 0 nn4a l=3u w=23u as=207p ad=207p
mp1 8 4 9 9 pn4a l=3u w=56u as=504p ad=504p
mp2 8 3 9 9 pn4a l=3u w=56u as=504p ad=504p
mp3 8 2 9 9 pn4a l=3u w=56u as=504p ad=504p
mp4 8 1 9 9 pn4a l=3u w=56u as=504p ad=504p
c1 1 0 .285pf
c2 2 0 .285pf
c3 3 0 .285pf
c4 4 0 .285pf
c8 8 0 .166pf
.ends e1240
.subckt e1230 6 1 2 3 7
*
* 4 um:  3 input nand gate
*
* i/o nodes: out i1 i2 i3 vdd
*  out          6
*  i1           1
*  i2           2
*  i3           3
*  vdd          7
*
*  may 17, 1982
*  revised: august 17, 1982
*
mn1 4 3 0 0 nn4a l=3u w=23u as=207p ad=207p
mn2 5 2 4 0 nn4a l=3u w=23u as=207p ad=207p
mn3 6 1 5 0 nn4a l=3u w=23u as=207p ad=207p
mp1 6 3 7 7 pn4a l=3u w=56u as=504p ad=504p
mp2 6 2 7 7 pn4a l=3u w=56u as=504p ad=504p
mp3 6 1 7 7 pn4a l=3u w=56u as=504p ad=504p
c1 1 0 .285p
c2 2 0 .285p
c3 3 0 .285p
c6 6 0 .134p
.ends e1230
.subckt e1220 4 1 2 5
*
* 4 um:  2 input nand gate
*
* i/o nodes: out i1 i2 vdd
*  out          4
*  i1           1
*  i2           2
*  vdd          5
*
*  may 17, 1982
*  revised: august 17, 1982
*
mn1 4 1 3 0 nn4a l=3u w=23u as=207p ad=207p
mn2 3 2 0 0 nn4a l=3u w=23u as=207p ad=207p
mp1 4 1 5 5 pn4a l=3u w=56u as=504p ad=504p
mp2 4 2 5 5 pn4a l=3u w=56u as=504p ad=504p
c1 1 0 .285pf
c2 2 0 .285pf
c4 4 0 .096pf
.ends e1220
.subckt e2310 3 1 2 9
*
* 4 um:  2 input exclusive or gate
*
* i/o nodes: out i1 i2 vdd
*  out          3
*  i1           1
*  i2           2
*  vdd          9
*
*  may 17, 1982
*  revised: august 17, 1982
*
mn1 4 1 0 0 nn4a l=3u w=23u as=207p ad=207p
mn2 5 2 0 0 nn4a l=3u w=23u as=207p ad=207p
mn3 3 4 7 0 nn4a l=3u w=23u as=207p ad=207p
mn4 3 1 8 0 nn4a l=3u w=23u as=207p ad=207p
mn5 7 5 0 0 nn4a l=3u w=23u as=207p ad=207p
mn6 8 2 0 0 nn4a l=3u w=23u as=207p ad=207p
mp1 4 1 9 9 pn4a l=3u w=56u as=504p ad=504p
mp2 5 2 9 9 pn4a l=3u w=56u as=504p ad=504p
mp3 6 1 9 9 pn4a l=3u w=56u as=504p ad=504p
mp4 6 2 9 9 pn4a l=3u w=56u as=504p ad=504p
mp5 3 4 6 9 pn4a l=3u w=56u as=504p ad=504p
mp6 3 5 6 9 pn4a l=3u w=56u as=504p ad=504p
c1 1 0 .600pf
c2 2 0 .600pf
c3 3 0 .111pf
c4 4 0 .356pf
c5 5 0 .356pf
.ends e2310
.subckt e1520 2 1 3
*
* 4 um:  inverting buffer.
*
* i/o nodes: out i1 vdd
*  out          2
*  i1           1
*  vdd          3
*
*  may 17, 1982
*  revised: august 17, 1982
*
mp1 2 1 3 3 pn4a w=56u l=3u as=504p ad=504p
mp2 2 1 3 3 pn4a w=56u l=3u as=504p ad=504p
mn1 2 1 0 0 nn4a w=23u l=3u as=207p ad=207p
mn2 2 1 0 0 nn4a w=23u l=3u as=207p ad=207p
c1 1 0 .572pf
c2 2 0 .095pf
.ends e1520
.subckt e1500 1 2 3 4 5
*
* 4 um: two single inverters
*
* i/o nodes: out1 out2 i1 i2 vdd
*
* august 5, 1982
*
mp1  1  3  5  5 pn4a w=56u l=3u as=504p ad=504p
mp2  2  4  5  5 pn4a w=56u l=3u as=504p ad=504p
mn1  1  3  0  0 nn4a w=23u l=3u as=207p ad=207p
mn2  2  4  0  0 nn4a w=23u l=3u as=207p ad=207p
c1 1 0 .084pf
c2 2 0 .084pf
c3 3 0 .285pf
c4 4 0 .285pf
.ends e1500
.subckt e1475 1 2 3 4 5 6
*
* 4 um: master/slave d ff with async reset
*
* i/o nodes: q nq d cl nr vdd
*
* august 4, 1982
*
mp1  3  4  8  6 pn4a w=56u l=3u as=504p ad=504p
mp2  9  8  6  6 pn4a w=56u l=3u as=504p ad=504p
mp3  9  5  6  6 pn4a w=56u l=3u as=504p ad=504p
mp4 10  9  6  6 pn4a w=56u l=3u as=504p ad=504p
mp5 10  7  8  6 pn4a w=56u l=3u as=504p ad=504p
mp6  7  4  6  6 pn4a w=56u l=3u as=504p ad=504p
mp7  9  7 12  6 pn4a w=56u l=3u as=504p ad=504p
mp8  1 12  6  6 pn4a w=56u l=3u as=504p ad=504p
mp9  2  1  6  6 pn4a w=56u l=3u as=504p ad=504p
mp10 2  5  6  6 pn4a w=56u l=3u as=504p ad=504p
mp11 2  4 12  6 pn4a w=56u l=3u as=504p ad=504p
mn1  3  7  8  0 nn4a w=23u l=3u as=207p ad=207p
mn2  9  5 11  0 nn4a w=23u l=3u as=207p ad=207p
mn3 11  8  0  0 nn4a w=23u l=3u as=207p ad=207p
mn4 10  9  0  0 nn4a w=23u l=3u as=207p ad=207p
mn5 10  4  8  0 nn4a w=23u l=3u as=207p ad=207p
mn6  7  4  0  0 nn4a w=23u l=3u as=207p ad=207p
mn7  9  4 12  0 nn4a w=23u l=3u as=207p ad=207p
mn8  1 12  0  0 nn4a w=23u l=3u as=207p ad=207p
mn9  2  5 13  0 nn4a w=23u l=3u as=207p ad=207p
mn10 13 1  0  0 nn4a w=23u l=3u as=207p ad=207p
mn11 2  7 12  0 nn4a w=23u l=3u as=207p ad=207p
c1   1  0 .356pf
c2   2  0 .168pf
c3   3  0 .087pf
c4   4  0 .900pf
c5   5  0 .574pf
c7   7  0 .610pf
c8   8  0 .356pf
c9   9  0 .356pf
c12 12  0 .356pf
.ends e1475
***   transistors
mp1 3 2 111 111 pn4a l=3u w=56u as=504p ad=504p
mp2 6 3 112 112 pn4a l=3u w=56u as=504p ad=504p
mp3 4 3 6 112 pn4a l=3u w=56u as=504p ad=504p
mp4 0 4 6 112 pn4a l=3u w=56u as=504p ad=504p
mp5 5 4 113 113 pn4a l=3u w=112u as=1008p ad=1008p
mn1 3 2 0 0 nn4a l=3u w=23u as=207p ad=207p
mn2 4 3 7 7 nn4a l=3u w=23u as=207p ad=207p
mn3 7 3 0 0 nn4a l=3u w=23u as=207p ad=207p
mn4 112 4 7 7 nn4a l=3u w=23u as=207p ad=207p
mn5 5 4 0 0 nn4a l=3u w=46u as=414p ad=414p
x1 8 9 5 5 114 e1500
x3 12 11 11 8 14 115 e1475
x4 17 15 12 116 e2310
x5 15 16 17 8 14 117 e1475
x6 20 18 16 118 e1220
x7 21 18 11 118 e1220
x8 22 15 12 19 118 e1230
x9 23 20 21 22 118 e1230
x10 18 19 23 8 14 119 e1475
x11 26 24 16 120 e1220
x12 27 24 11 120 e1220
x13 28 24 19 120 e1220
x14 29 12 15 18 25 120 e1240
x15 30 26 27 28 29 120 e1240
x16 24 25 30 8 14 121 e1475
***   passive components
c1 1 2 20pf
c2 4 0 0.664pf
c3 3 0 0.547pf
cout 5 0 0.984pf
c5 9 0 3.885pf
r1 2 3 1e6
***  voltage sources
vdd 110 0 dc 10.0v
vidd 110 10 dc 0v
vid1 10 111 dc 0v
vid2 10 112 dc 0v
vid3 10 113 dc 0v
vid4 10 114 dc 0v
vix3 10 115 dc 0v
vix4 10 116 dc 0v
vix5 10 117 dc 0v
vix6 10 118 dc 0v
vix10 10 119 dc 0v
vix11 10 120 dc 0v
vix16 10 121 dc 0v
vin 1 0 sin( 1 1 33e6 )
vnr 14 0 pulse(0v 10v 10ns 1ns 1ns 1us 10us)
***   control cards
.tran 2ns 600ns
.print tran v(8) v(12) v(15) v(21) v(23) v(30)
.op
.options acct itl5=50000 lvltim=1 limpts=10000
.end

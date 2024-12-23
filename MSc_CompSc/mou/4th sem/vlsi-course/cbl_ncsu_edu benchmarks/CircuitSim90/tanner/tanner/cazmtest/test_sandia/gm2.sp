file: gm2.ckt
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
.subckt e1310 2 1 3
*
* 4 um: inverter
*
* i/o nodes: out i1 vdd
*
* august 5, 1982
*
mp1  2  1  3  3 pn4a w=56u l=3u as=504p ad=504p
mn1  2  1  0  0 nn4a w=23u l=3u as=207p ad=207p
c1 1 0 .285pf
c2 2 0 .084pf
.ends e1310
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
vdd 1 0 dc 10
vp 2 0 pulse (0 10 10ns 1ns 1ns 30ns 100ns)
x1 3 2 2 1 e1220
x2 4 3 1 e1310
mn1 4 0 0 0 nn4a w=23u l=3u as=207p ad=207p
*.tran 1ns 200ns
.print tran v(2) v(3) v(4)
*.end

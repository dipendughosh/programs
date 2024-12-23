file: em1.ckt
.model pn4a pmos
+ vto    = -1.27110e+0
+ uo     =  1.89514e+2
+ nsub   =  4.57476e+15
+ ucrit  =  1.20248e+5
+ uexp   =  5.83290e-1
+ lambda =  2.61855e-2
+ utra   =  2.00000e-1
+ tox    =  4.50000e-6
+ xj     =  6.00000e-5
+ ld     =  7.00000e-6
+ js     =  1.00000e-11
+ cbd    =  1.30000e-8
+ cbs    =  1.30000e-8
+ pb     =  9.00000e-1
+ rd     =  6.92000e+0
+ rs     =  6.92000e+0
+ level  =  2)
* seq no:    50  b4506ap  18   18   51   3153
.model nn4a nmos(
+ vto    =  8.86298e-1
+ uo     =  5.05739e+2
+ nsub   =  6.47532e+16
+ ucrit  =  3.06080e+5
+ uexp   =  6.50268e-1
+ lambda =  1.47924e-2
+ utra   =  2.00000e-1
+ tox    =  4.50000e-6
+ xj     =  6.00000e-5
+ ld     =  7.00000e-6
+ js     =  1.00000e-11
+ cbd    =  4.00000e-8
+ cbs    =  4.00000e-8
+ pb     =  9.20000e-1
+ rd     =  4.75000e+0
+ rs     =  4.75000e+0
+ level  =  2)
* seq no:    25  b3908an  19   13   87   3123
vdd 10 0 pulse (0 5 0n 1n 1n 200n 203n)
*.tran 1n 120n
*
vclk 1 0 5v
vwr 2 0 pulse (0 5 9n 2n 2n 18n 50n)
vrd1 3 0 pulse (0 5 29n 2n 2n 18n 60n)
vrd2 4 0 pulse (0 5 29n 2n 2n 18n 60n)
vdi 18 0 pulse (0 5 49n 2n 2n 128n 200n)
*
* storage cell:
x1 14 6 2 23 10 tg
mp1 14 16 10 10 pn4a w=25e-4 l=10e-4 ad=200e-8 as=200e-8 off
mn1 14 16  0  0 nn4a w=7e-4  l=10e-4 ad=56e-8  as=56e-8
r1 13 16 25k
mp2 13 15 10 10 pn4a w=25e-4 l=3e-4 ad=200e-8 as=200e-8
mn2 13 15  0  0 nn4a w=7e-4  l=3e-4 ad=56e-8  as=56e-8 off
r2 14 15 25k
x2 17 14 10 inv2
x3 7 17 3 24 10 tg
x4 8 17 4 25 10 tg
x5 23 2 10 inv
x6 24 3 10 inv
x7 25 4 10 inv
*
* read line latches:
x8 19 10 llatch
x9 20 10 llatch
*
* transparent output latches:
x10 21 19 1 10 dlatch
x11 22 20 1 10 dlatch
*
.subckt inv2 2 1 10
* storage cell output buffer
mp1 2 1 10 10 pn4a w=50e-4 l=3e-4 ad=400e-8 as=400e-8
mn1 2 1 0 0 nn4a   w=20e-4 l=3e-4 ad=120e-8 as=160e-8
.ends inv2
*
.subckt inv 2 1 10
* normal inverter
mp1 2 1 10 10 pn4a w=25e-4 l=3e-4 ad=200e-8 as=200e-8
mn1 2 1  0  0 nn4a w=7e-4  l=3e-4 ad=56e-8  as=56e-8
.ends inv
*
.subckt tg 31 32 33 34 10
* nodes: out in ngate pgate vdd
mp1 31 34 32 10 pn4a w=25e-4 l=3e-4 ad=200e-8 as=200e-8
mn1 31 33 32 0  nn4a w=7e-4  l=3e-4 ad=56e-8  as=56e-8
.ends tg
*
* bit lines:
ro1 7 19 1k
r02 8 20 1k
rin 18 6 1k
cdi 6 0 .5p
cdo1 19 0 .5p
cdo2 20 0 .5p
*
* write line:
cwl 2 0 .3pf
*
* read lines:
cr1 3 0 .3p
cr2 4 0 .3p
*
.subckt dlatch 8 6 1 10
* nodes: q, d, clk, vdd
x31 73 6 1 74 10 tg
x33 75 73 10 inv
x34 8 75 10 inv
rfb 77 8 20k
x32 73 77 74 1 10 tg
x35 74 1 10 inv
cl 8 0 .5p
.ends dlatch
*
* tail-chaser data out line latch:
.subckt llatch 1 10
* nodes: i/0 vdd
mp1 1 2 10 10 pn4a w=25e-4 l=10e-4 ad=200e-8 as=200e-8
mn1 1 2  0  0 nn4a w=7e-4  l=10e-4 ad=56e-8  as=56e-8
mp2 2 1 10 10 pn4a w=25e-4 l=3e-4  ad=200e-8 as=200e-8
mn2 2 1  0  0 nn4a w=7e-4  l=3e-4  ad=56e-8  as=56e-8
.ends llatch
*
.print tran v(2) v(3) v(4) v(6) v(7) i(vdd)
.print tran v(8) v(13) v(14) v(17)
.print tran v(21) v(22)
.end

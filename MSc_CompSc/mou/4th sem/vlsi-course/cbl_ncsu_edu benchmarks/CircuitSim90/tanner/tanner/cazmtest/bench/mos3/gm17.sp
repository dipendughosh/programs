*file: gm17.ckt  -  non-precharged ram for 2901b
* single port version with dlatch and decoder
* 8 transistor cell
* 19 may 83
*
vdd 10 0 5v
vwr 3 0 pulse (0 5 40n 1n 1n 38n 200n)
vad 41 0 pulse (0 5 5n 1n 1n 38n 85n)
vdi 9 0 pulse (0 5 65n 1n 1n 18n 200n)
vclk 1 0 pulse (5 0 120n 1n 1n 30n 200n)
*
* storage cell:
mp1 4 16 10 10 pn4a w=50u l=3u ad=400p as=400p
mp2 5 17 10 10 pn4a w=50u l=3u ad=400p as=400p off
mn1 4 16 0 0 nn4a w=20u l=3u ad=160p as=160p off
mn2 5 17 0 0 nn4a w=20u l=3u ad=160p as=160p
r1 5 16 20k
r2 4 17 20k
*
* access transistors:
mn3 6 2 4 0 nn4a w=18u l=3u ad=144p as=144p
mn4 7 2 5 0 nn4a w=18u l=3u ad=144p as=144p
*
* dummy bit line loads (8x n-ch access transistors):
mn7 6 0 0 0 nn4a w=144u l=3u ad=1152p as=1152p
mn8 7 0 0 0 nn4a w=144u l=3u ad=1152p as=1152p
*
* dummy access transistors for a-port:
mn5 4 0 0 0 nn4a w=18u l=3u ad=144p as=144p
mn6 5 0 0 0 nn4a w=18u l=3u ad=144p as=144p
*
* bit line capacitances:
c6 6 0 .5p
c7 7 0 .5p
*
* half-latch pull-ups:
mp21 6 7 10 10 pn4a w=50u l=3u ad=400p as=400p
mp22 7 6 10 10 pn4a w=50u l=3u ad=400p as=400p
*
* transparent latch:
* x1 8 6 1 10 dlatch
* .subckt dlatch 76 71 72 10
* nodes: q, d, clk, vdd
x31 73 6 1 74 10 tg
x32 73 77 74 1 10 tg
x33 75 73 10 inv
rfb 8 77 20k
x34 8 75 10 inv
x35 74 1 10 inv
cl 8 0 1p
* .ends dlatch
*
* tri-state write cell:
mp11 6 12 10 10 pn4a w=200u l=3u ad=1600p as=1600p
mp12 7 13 10 10 pn4a w=200u l=3u ad=1600p as=1600p
mn11 6 14 0 0 nn4a w=60u l=3u ad=480p as=480p
mn12 7 15 0 0 nn4a w=60u l=3u ad=480p as=480p
x11 11 9 10 inv
x12 14 13 10 inv
x13 15 12 10 inv
x14 12 9 3 10 nand
x15 13 3 11 10 nand
*
* address decoder:
x21 42 41 10 inv
c42 42 0 .50p
x22 43 42 10 inv
c43 43 0 .25p
x23 44 43 10 10 nand
x24 45 44 10 inv
c45 45 0 .75p
x25 47 45 10 10 nand
x26 2 47 10 inv
*
* word line cap:
c2 2 0 .75p
*
.subckt tg 83 82 81 84 80
* nodes: out, in, ngate, pgate, vdd
mp1 83 84 82 80 pn4a w=50u l=3u ad=120p as=120p
mn1 83 81 82  0 nn4a w=20u l=3u ad=160p as=160p
.ends tg
*
.subckt inv 2 1 10
mp1 2 1 10 10 pn4a w=50u l=3u ad=400p as=400p
mn1 2 1 0 0 nn4a w=20u l=3u ad=160p as=160p
.ends inv
*
.subckt nand 3 2 1 10
mp1 3 1 10 10 pn4a w=50u l=3u ad=400p as=400p
mp2 3 2 10 10 pn4a w=50u l=3u ad=400p as=400p
mn1 3 1 4 0 nn4a w=20u l=3u ad=160p as=160p
mn2 4 2 0 0 nn4a w=20u l=3u ad=160p as=160p
.ends nand
*
.model nn4a nmos(
+     vto=   1.004e+00     uo=     6.668e+02     kappa= 2.000e-01
+     eta=   1.645e+00     theta=  3.811e-02     vmax=  1.818e+05
+     delta= 8.729e+00     nsub=   3.545e+16     tox=   4.200e-08
+     tpg=   1.000e+00     xj=     6.000e-09
+     js=    1.000e-07     cj=     4.000e-04     pb=    0.920e-00
+     rs=    2.600e+00     rd=     2.600e+00     level= 3)
*seq.#: 22 proc: b3918ap 3153 wafer:  1 loc:  5;  9 date: 18oct82
.model pn4a pmos(
+     vto=  -1.281e+00     uo=     1.817e+02     kappa= 2.000e-01
+     eta=   3.778e+00     theta=  6.226e-02     vmax=  2.000e+05
+     delta= 7.698e-01     nsub=   1.843e+15     tox=   4.270e-08
+     tpg=  -1.000e+00     xj=     6.000e-09
+     js=    1.000e-07     cj=     1.300e-04     pb=    0.900e-00
+     rs=    5.900e+00     rd=     5.900e+00     level= 3)
.ic v(10)=5, v(5)=0, v(4)=5, v(6)=0, v(7)=5 v(1)=5
.options acct
.print tran v(2) v(4) v(5) v(16) v(17)
.tran .25n 16n 
.end

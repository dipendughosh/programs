file: c1480.ckt - flip flop characterization
* nominal models--version 1  ** 5mar80
*
.model pnl1 pmos(    vto -1.615    kp 1.191e-5   gamma 0.2715
+                      phi 0.5663    uexp 0.3022   ucrit 1.35e5
+                      lambda 0.005  cj 9.17e-5    
+                      pb 0.9        rd 10.9       rs 10.9
+                      tox 5.67e-8   js 1.94e-6   level 2)
.model nnl1 nmos(    vto 0.7746    kp 4.958e-5   gamma 1.300
+                      phi 0.7283    uexp 0.2715   ucrit 2.01e5
+                      utra 2.0      lambda 0.01   cj 7.1e-4
+                      pb 0.9        rd 3.7
+                      rs 3.7        tox 5.67e-8   js 1.57e-8
+                      level 2)
*
.model pnl2 pmos(    vto -1.615    kp 1.191e-5   gamma 0.2715
+                      phi 0.5663    uexp 0.3022   ucrit 1.35e5
+                      lambda 0.005  cj 9.17e-5    
+                      pb 0.9        rd 10.9       rs 10.9
+                      tox 5.67e-8   js 1.94e-10   level 2)
.model nnl2 nmos(    vto 0.7746    kp 4.958e-5   gamma 1.300
+                      phi 0.7283    uexp 0.2715   ucrit 2.01e5
+                      utra 2.0      lambda 0.01   cj 7.1e-4
+                      pb 0.9        rd 3.7
+                      rs 3.7        tox 5.67e-8   js 1.57e-12
+                      level 2)
.model dnpw d(cjo=5.43e-8 vj=.500)
.model dppn d(cjo=1.86e-8 vj=.500)
*
.subckt c9070 1 2 3
dppn1 4 1 dppn area=2.40e-9
dppn2 8 1 dppn area=7.17e-10
dpwn 6 1 dppn area=9.99e-10
dnpw 0 3 dnpw area=1.24e-9
cm1 2 0 .445pf
r1 2 4 610
r2 4 5 610
r3 5 6 125
r4 6 7 125
r5 7 8 143
r6 8 3 143
.ends
*
.subckt c1480 1 2 3 4 13 5 6
mp1 49  3 51 50 pnl1 w=1.63mil l=.174mil ad=1.71e-10 as=1.71e-10
mp2 34  3 32 33 pnl1 w=1.63mil l=.174mil ad=1.71e-10 as=1.71e-10
mp3 54 12 52 53 pnl1 w=1.63mil l=.174mil ad=1.71e-10 as=1.71e-10
mp4 58  4 56 57 pnl1 w=1.63mil l=.174mil ad=1.71e-10 as=1.71e-10
mp5 80 13  81 82 pnl2 w=1.63mil l=.174mil ad=1.71e-10 as=1.71e-10
mp6 42 28  44 43 pnl2 w=1.63mil l=.174mil ad=1.71e-10 as=1.71e-10
mp7 37 19 39 38 pnl2 w=1.63mil l=.174mil ad=1.71e-10 as=1.71e-10
mp8 63 19 61 62 pnl2 w=1.63mil l=.174mil ad=1.71e-10 as=1.71e-10
mp9 85 65 83 84 pnl2 w=1.63mil l=.174mil ad=1.71e-10 as=1.71e-10
mp10 89 13 87 88 pnl2 w=1.63mil l=.174mil ad=1.71e-10 as=1.71e-10
mp11 77  6 79 78 pnl1 w=1.63mil l=.174mil ad=1.71e-10 as=1.71e-10
mp12 73  4 75 74 pnl1 w=1.63mil l=.174mil ad=1.71e-10 as=1.71e-10
mp13 69  3 67 68 pnl1 w=1.63mil l=.174mil ad=1.71e-10 as=1.71e-10
mn1  21  3 23 22 nnl1 w=1.13mil l=.174mil ad=6.45e-11 as=6.45e-11
mn2  10 19  8  9 nnl2 w=1.13mil l=.174mil ad=6.45e-11 as=6.45e-11
mn3  26 12 24 25 nnl1 w=1.13mil l=.174mil ad=6.45e-11 as=6.45e-11
mn4  30  4 92 91 nnl1 w=1.13mil l=.174mil ad=6.45e-11 as=6.45e-11
mn5  98 13 100 99 nnl2 w=1.13mil l=.174mil ad=6.45e-11 as=6.45e-11
mn6  95 28  93 94 nnl2 w=1.13mil l=.174mil ad=6.45e-11 as=6.45e-11
mn7  16  3 14 15 nnl1 w=1.13mil l=.174mil ad=6.45e-11 as=6.45e-11
mn8 112  3 114 113 nnl1 w=1.13mil l=.174mil ad=6.45e-11 as=6.45e-11
mn9 103 65  101 102 nnl2 w=1.13mil l=.174mil ad=6.45e-11 as=6.45e-11
mn10 107 13 109 108 nnl2 w=1.13mil l=.174mil ad=6.45e-11 as=6.45e-11
mn11 128 6   130 129 nnl1 w=1.13mil l=.174mil ad=6.45e-11 as=6.45e-11
mn12 124  4  122 123 nnl1 w=1.13mil l=.174mil ad=6.45e-11 as=6.45e-11
mn13 120 19  118 119 nnl2 w=1.13mil l=.174mil ad=6.45e-11 as=6.45e-11
dpd2 2 1 dppn area=4.44e-11
dpcl3 3 1 dppn area=4.44e-11
dps4 4 1 dppn area=4.44e-11
dpq5 5 1 dppn area=4.44e-11
dpq6 6 1 dppn area=4.44e-11
dsn2 0 7 dnpw area=6.40e-10
ddn2 0 11 dnpw area=1.41e-9
dsn7 0 131 dnpw area=9.40e-10
ddn7 0 17 dnpw area=6.40e-10
ddn8 0 111 dnpw area=1.41e-9
dsn8 0 115 dnpw area=2.43e-9
dsn13 0 117 dnpw area=4.29e-10
ddn13 0 121 dnpw area=1.15e-9
ddn12 0 125 dnpw area=1.684e-9
ddn11 0 127 dnpw area=1.684e-9
ddn1 0 20 dnpw area=6.40e-10
ddn3 0 27 dnpw area=2.03e-9
ddn4 0 29 dnpw area=3.59e-10
ddn6 0 96 dnpw area=3.69e-10
ddn5 0 97 dnpw area=1.47e-9
ddn9 0 104 dnpw area=1.22e-9
ddn10 0 106 dnpw area=1.73e-9
dsp2 31 1 dppn area=1.64e-9
ddp2 35 1 dppn area=1.17e-9
dsp7 36 1 dppn area=5.03e-10
ddp7 40 1 dppn area=1.32e-9
dsp6 41 1 dppn area=5.66e-10
ddp6 45 1 dppn area=1.49e-9
ddp5 47 1 dppn area=1.49e-9
ddp9 86 1 dppn area=1.99e-9
ddp10 90 1 dppn area=1.08e-9
ddp1 48 1 dppn area=9.05e-10
ddp3 55 1 dppn area=1.78e-9
ddp4 59 1 dppn area=7.39e-10
dsp8 60 1 dppn area=1.43e-9
ddp8 64 1 dppn area=6.29e-10
dsp13 66 1 dppn area=6.29e-10
ddp13 70 1 dppn area=1.47e-9
dsp12 72 1 dppn area=4.89e-10
ddp11 76 1 dppn area=1.39e-9
ddr13 13 1 dppn area=4.44e-11
cmd2  2 0 .066pf
cmcl3 3 0 .816pf
cms4  4 0 .641pf
cmq5  5 0 .054pf
cmq6  6 0 .163pf
cmr13 13 0 .518pf
cm65 65 0 .206pf
cm19 19 0 .745pf
cm12 12 0 .266pf
cm18 18 0 .071pf
cm28 28 0 .483pf
cm104 104 0 .020pf
cm126 126 0 .025pf
rn21 2 7 5.63
rn22 7 8 5.63
rbn2 9 0 .1
rn21a 10 11 31.88
rn22a 11 12 31.88
rn71 12 131 20.63
rn72 131 14 20.63
rbn7 15 0 .1
rn71a 16 17 5.63
rn72a 17 18 5.63
rn81 28 111 23.08
rn82 111 112 23.08
rbn8 113 0 .1
rn81a 114 115 67.5
rn82a 115 65  67.5
rn131 65  117 5.63
rn132 117 118 5.63
rbn13 119 0 .1
ra131 120 121 18.75
ra132 121 126 18.75
rn12 122 0 9.47
rbn12 123 0 .1
rn121 124 125 5.63
rn122 125 126 5.63
rd126 126 5   160
rn111 5 127 5.63
rn112 127 128 5.63
rbn11 129 0 .1
rn11 130 0 9
ra11 19 20 5.63
ra12 20 21 5.63
rbnb 22 0 .1
rn3 24 0 9
rbn3 25 0 .1
rn31 26 27 48.75
rn32 27 28 48.75
rn41 28 29 5.63
rn42 29 30 5.63
rbn4 91 0 .1
rn4 92 0 9
rn6 93 0 9
rbn6 94 0 .1
rn1 23 0 9
rn61 95 96 5.63
rn62 96 18 5.63
rn51 18 97 37.5
rn52 97 98 37.5
rbn5 99 0 .1
rn5 100 0 9
rn9 101 0 37.5
rbn9 102 0 .1
rd91 103 104 57.43
rd92 104 6   57.43
rn101 6   106 5.63
rn102 106 107 5.63
rbn10 108 0 .1
rn10 109 0 72
rp21 2 31 48.85
rp22 31 32 48.85
rbp2 33 1 .1
rp21a 34 35 48.85
rp22a 35 12 48.85
rp71 12 36 14.65
rp72 36 37 14.65
rbp7 38 1 .1
rp71a 39 40 53.73
rp72a 40 18 53.73
rp61 18 41 14.65
rp62 41 42 14.65
rbp6 43 1 .1
rp61a 44 45 188.2
rp62a 45 46 188.2
rp51 46 47 188.2
rp52 47 80 188.2
rbp5  81 1 .1
rp5  82 1 25.4
rp9 83 1 84.67
rbp9 84 1 .1
rp9a 85 86 50.13
rp10 86 87 50.13
rbp10 88 1 .1
rp101 89 90 14.65
rp102 90 6   14.65
rp11 19 48 14.65
rp12 48 49 14.65
rbp1 50 1 .1
rp1 51 1 25.4
rp3 52 1 25.4
rbp3 53 1 .1
rp3a 54 55 71.97
rp4 55 56 71.97
rbp4 57 1 .1
rp41 58 59 26.74
rp42 59 28 26.74
rp81 28 60 73.53
rp82 60 61 73.53
rb81 62 1 .1
rp81a 63 64 14.65
rp82a 64 65 14.65
rp131 65 66 29.31
rp132 66 67 29.31
rbp13 68 1 .1
rb131 69 70 42.33
rb132 70 5 42.33
rp121 5 72 14.65
rp122 72 73 14.65
rbp12 74 1 .1
rp111 75 76 42.33
rp112 76 77 42.33
rbp11 78 1 .1
rp11b 79 1 33.87
.ends
*
.subckt c9860 1 2 3
mp1 11  4  9 10 pnl1 w=6.53mil l=.174mil ad=4.74e-9 as=4.74e-9
mn1  7  4  5  6 nnl1 w=4.03mil l=.174mil ad=2.93e-9 as=2.93e-9
dpin 13 1 dppn area=1.82e-9
ddp1 12 1 dppn area=4.30e-9
ddn1 0 8 dnpw area=2.501e-9
cmout 3 0 .63pf
rin1 2 13 116
rp1 9 1 7.9
rbp1 10 1 .1
rp1a 11 12 2.89
rp2 12 3 2.89
rn1 5 0 2.3
rbn1 6 0 .1
rn1a 7 8 1.22
rn2 8 3 1.22
r1n2 13 4 116
.ends
*
x1 1 3 4 c9070
dp 4 1 dppn area 9.88e-10
cd 4 0 2.53pf
x2 1 5 4 0 10 5 6 c1480
x3 1 6 8 c9860
vpwr 30 0 dc 10
rwr 30 1 1
vin 2 0 pulse (0 10 25ns 40ns 40ns 85ns 190ns)
rin 2 3 2000
vrt 9 0 pulse(10 0 10ns 10ns 10ns 1us 2us)
rrt 9 10 2000
co 8 0 10pf
*
.options abstol=10n acct node list itl5=10000
.temp -55 27 125
.tran  2ns 200ns 
.print tran v(8) v(2) (-5,15)
.plot tran v(8) v(2) (-5,15)
.end

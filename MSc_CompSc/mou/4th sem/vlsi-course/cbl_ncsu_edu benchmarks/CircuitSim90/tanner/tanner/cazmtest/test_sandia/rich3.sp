mspice driven run, uid = 2c141bf2.600023ea
v$d10  51 0 exp(0.00000000000000e+00 4.50000000000000e+00
+0.00000000000000e+00 1.00000000000000e-09
+6.00000000000000e-07 1.00000000000000e-09)
v$d9  15 0 pulse(4.50000000000000e+00 0.00000000000000e+00 +7.00000000000000e-08 2.00000000000000e-09 +2.00000000000000e-09 2.96000000000000e-07 4.00000000000000e-07)
v$d8  14 0 pulse(0.00000000000000e+00 4.50000000000000e+00 +3.00000000000000e-08 2.00000000000000e-09 +2.00000000000000e-09 9.60000000000000e-08 2.00000000000000e-07)
v$d7  17 0 pulse(4.50000000000000e+00 0.00000000000000e+00 +5.20000000000000e-08 2.00000000000000e-09 +2.00000000000000e-09 4.20000000000000e-08 9.99999900000000e-08)
v$d6  18 0 pulse(4.50000000000000e+00 0.00000000000000e+00 +2.00000000000000e-09 2.00000000000000e-09 +2.00000000000000e-09 4.20000000000000e-08 9.99999900000000e-08)
m$600 27 22 28 51 pn2 w=17u l=2u ad=85p as=85p
m$599 27 37 11 51 pn2 w=17u l=2u ad=85p as=85p
m$598 48 30 50 51 pn2 w=9u l=2u ad=54p as=54p
m$597 48 47 31 51 pn2 w=9u l=2u ad=54p as=54p
m$596 48 51 51 51 pn2 w=27u l=2u ad=162p as=162p
mnd#/mp1 41 10 51 51 pn2 w=21u l=2u ad=126p as=126p
mnd#/mp2 41 20 51 51 pn2 w=21u l=2u ad=126p as=126p
mnd#/mp3 41 51 51 51 pn2 w=21u l=2u ad=126p as=126p
m$595 27 18 28 0 nn2 w=9u l=2u ad=54p as=54p
m$594 27 12 11 0 nn2 w=9u l=2u ad=54p as=54p
m$593 48 47 50 0 nn2 w=17u l=2u ad=102p as=102p
m$592 48 30 31 0 nn2 w=6u l=2u ad=36p as=36p
m$591 48 0 51 0 nn2 w=51u l=2u ad=306p as=306p
mnd#/mn3 1 51 0 0 nn2 w=37u l=2u ad=185p as=185p
mnd#/mn2 2 20 1 0 nn2 w=37u l=2u ad=185p as=185p
mnd#/mn1 41 10 2 0 nn2 w=37u l=2u ad=185p as=185p
rs#1 42 36 100k
rs#2 13 29 100k
cdgate 46 0 0.2p
cgate 43 0 0.2p
cnpchg 19 0 0.2p
cdnor 45 0 0.1p
cwle 10 0 0.2p
cnor 20 0 0.1p
cmux 48 0 0.03p
crow 33 0 0.01p
cx 42 0 0.1p
cbit 50 0 0.1p
cword 9 0 0.05p
cyr 8 0 0.5p
mp13 45 21 51 51 pn2 w=10u l=2u ad=60p as=60p
mp47 45 25 51 51 pn2 w=2u l=6u ad=24p as=24p
mp10 51 19 51 51 pn2 w=300u l=2u ad=1800p as=1800p
mp3 20 19 51 51 pn2 w=10u l=2u ad=60p as=60p
mp57 20 35 51 51 pn2 w=2u l=6u ad=24p as=24p
mp20 51 49 51 51 pn2 w=1775u l=2u ad=7200p as=7200p
mp23 50 49 51 51 pn2 w=18u l=2u ad=90p as=90p
mp37 50 23 51 51 pn2 w=2u l=6u ad=24p as=24p
m$572 28 29 51 51 pn2 w=17u l=2u ad=85p as=85p
m$571 8 38 51 51 pn2 w=90u l=2u ad=540p as=540p
m$570 38 13 51 51 pn2 w=34u l=2u ad=204p as=204p
m$569 13 27 51 51 pn2 w=17u l=2u ad=85p as=85p
m$568 23 50 51 51 pn2 w=6u l=2u ad=36p as=36p
m$567 37 12 51 51 pn2 w=17u l=2u ad=90p as=90p
m$566 9 41 51 51 pn2 w=98u l=2u ad=600p as=600p
m$565 42 48 51 51 pn2 w=17u l=2u ad=85p as=85p
m$564 31 36 51 51 pn2 w=9u l=2u ad=54p as=54p
m$563 49 34 51 51 pn2 w=392u l=2u ad=1960p as=1960p
m$562 34 10 51 51 pn2 w=98u l=2u ad=600p as=600p
m$561 33 10 51 51 pn2 w=4011u l=2u ad=24000p as=24000p
m$560 47 30 51 51 pn2 w=17u l=2u ad=90p as=90p
m$559 35 20 51 51 pn2 w=2u l=5u ad=30p as=30p
m$558 10 16 51 51 pn2 w=1168u l=2u ad=5840p as=5840p
m$557 16 44 51 51 pn2 w=292u l=2u ad=1460p as=1460p
m$556 44 45 51 51 pn2 w=73u l=2u ad=365p as=365p
m$555 25 45 51 51 pn2 w=2u l=5u ad=30p as=30p
m$554 19 26 51 51 pn2 w=98u l=2u ad=600p as=600p
m$553 43 40 51 51 pn2 w=146u l=2u ad=730p as=730p
m$552 21 22 51 51 pn2 w=17u l=2u ad=90p as=90p
m$551 46 32 51 51 pn2 w=146u l=2u ad=730p as=730p
m$550 40 24 51 51 pn2 w=146u l=2u ad=730p as=730p
m$549 32 39 51 51 pn2 w=73u l=2u ad=365p as=365p
m$548 22 18 51 51 pn2 w=17u l=2u ad=90p as=90p
m$547 39 17 51 51 pn2 w=17u l=2u ad=90p as=90p
m$546 11 0 7 51 pn2 w=17u l=2u ad=85p as=85p
m$545 7 42 51 51 pn2 w=17u l=2u ad=85p as=85p
m$544 30 39 6 51 pn2 w=17u l=2u ad=90p as=90p
m$543 6 10 51 51 pn2 w=17u l=2u ad=90p as=90p
m$542 26 18 5 51 pn2 w=49u l=2u ad=300p as=300p
m$541 5 10 51 51 pn2 w=49u l=2u ad=300p as=300p
m$540 12 15 4 51 pn2 w=17u l=2u ad=90p as=90p
m$539 4 18 51 51 pn2 w=17u l=2u ad=90p as=90p
m$538 24 14 3 51 pn2 w=73u l=2u ad=365p as=365p
m$537 3 17 51 51 pn2 w=73u l=2u ad=365p as=365p
mn33 0 40 0 0 nn2 w=672u l=2u ad=2400p as=2400p
mn3 0 46 0 0 nn2 w=480u l=2u ad=2400p as=2400p
mn13 0 43 0 0 nn2 w=672u l=2u ad=2400p as=2400p
mn11 45 46 0 0 nn2 w=5u l=2u ad=30p as=30p
mn12 45 0 0 0 nn2 w=50u l=2u ad=300p as=300p
mn21 20 43 0 0 nn2 w=5u l=2u ad=30p as=30p
mn2 20 0 0 0 nn2 w=50u l=2u ad=300p as=300p
mn1 50 9 0 0 nn2 w=18u l=2u ad=28p as=36p
mn14 50 0 0 0 nn2 w=2400u l=2u ad=3000p
mn10 0 9 0 0 nn2 w=1775u l=2u ad=1633p as=1800p
m$536 28 29 0 0 nn2 w=9u l=2u ad=54p as=54p
m$535 8 38 0 0 nn2 w=50u l=2u ad=300p as=300p
m$534 38 13 0 0 nn2 w=18u l=2u ad=28p as=36p
m$533 13 27 0 0 nn2 w=9u l=2u ad=54p as=54p
m$532 23 50 0 0 nn2 w=6u l=2u ad=36p as=36p
m$531 37 12 0 0 nn2 w=9u l=2u ad=90p as=90p
m$530 9 41 0 0 nn2 w=42u l=2u ad=252p as=252p
m$529 42 48 0 0 nn2 w=9u l=2u ad=54p as=54p
m$528 31 36 0 0 nn2 w=6u l=2u ad=36p as=36p
m$527 49 34 0 0 nn2 w=200u l=2u ad=1000p as=1000p
m$526 34 10 0 0 nn2 w=50u l=2u ad=300p as=300p
m$525 33 10 0 0 nn2 w=7067u l=2u ad=42000p as=42000p
m$524 47 30 0 0 nn2 w=9u l=2u ad=90p as=90p
m$523 35 20 0 0 nn2 w=5u l=2u ad=30p as=30p
m$522 10 16 0 0 nn2 w=592u l=2u ad=2960p as=2960p
m$521 16 44 0 0 nn2 w=148u l=2u ad=740p as=740p
m$520 44 45 0 0 nn2 w=37u l=2u ad=185p as=185p
m$519 25 45 0 0 nn2 w=5u l=2u ad=30p as=30p
m$518 19 26 0 0 nn2 w=50u l=2u ad=300p as=300p
m$517 43 40 0 0 nn2 w=74u l=2u ad=370p as=370p
m$516 21 22 0 0 nn2 w=9u l=2u ad=90p as=90p
m$515 46 32 0 0 nn2 w=74u l=2u ad=370p as=370p
m$514 40 24 0 0 nn2 w=74u l=2u ad=370p as=370p
m$513 32 39 0 0 nn2 w=37u l=2u ad=185p as=185p
m$512 22 18 0 0 nn2 w=9u l=2u ad=90p as=90p
m$511 39 17 0 0 nn2 w=9u l=2u ad=90p as=90p
m$510 11 0 0 0 nn2 w=17u l=2u ad=102p as=102p
m$509 11 42 0 0 nn2 w=17u l=2u ad=102p as=102p
m$508 30 39 0 0 nn2 w=9u l=2u ad=90p as=90p
m$507 30 10 0 0 nn2 w=9u l=2u ad=90p as=90p
m$506 26 18 0 0 nn2 w=25u l=2u ad=150p as=150p
m$505 26 10 0 0 nn2 w=25u l=2u ad=150p as=150p
m$504 12 15 0 0 nn2 w=9u l=2u ad=90p as=90p
m$503 12 18 0 0 nn2 w=9u l=2u ad=90p as=90p
m$502 24 14 0 0 nn2 w=37u l=2u ad=185p as=185p
m$501 24 17 0 0 nn2 w=37u l=2u ad=185p as=185p
*.options itl5=100000
*.options reltol=.01
*.options lvltim=1
*
.options defl=2u
.options limpts=1000
.options abstol=1.e-10 reltol=.005 vntol=1.e-5 chgtol=1.e-10 lvltim=1
*
.model nn2 nmos(
+ vto    =  1.20269e+0
+ uo     =  7.01737e+2
+ nsub   =  1.11136e+17
+ nfs    =  1.81211e+12
+ kappa  =  2.00000e-2
+ phi    =  8.10335e-1
+ theta  =  6.05549e-2
+ gamma  =  1.74402e+0
+ vmax   =  1.87637e+5
+ eta    =  3.99308e-1
+ tox    =  3.15000e-8
+ xj     =  3.00000e-7
+ tpg    =  1.00000e+0
+ js     =  1.00000e-7
+ cj     =  9.77838e-4
+ pb     =  9.71479e-1
+ rsh    =  4.07910e+1
+ level  =  3)
* seq no:    17  ta632-m  h1235a  w10  d5  2u  1nn  25c  0e0
.model pn2 pmos(
+ vto    = -1.16509e+0
+ uo     =  3.53096e+2
+ kappa  =  2.00000e-2
+ nsub   =  5.54420e+15
+ nfs    =  1.67611e+12
+ gamma  =  6.18987e-1
+ phi    =  1.19566e+0
+ theta  =  1.50551e-1
+ vmax   =  2.78427e+5
+ eta    =  1.57677e+0
+ tox    =  3.15000e-8
+ xj     =  3.00000e-7
+ tpg    = -1.00000e+0
+ js     =  1.00000e-7
+ cj     =  2.27692e-4
+ pb     =  8.93830e-1
+ rsh    =  1.49570e+2
+ level  =  3)
* seq no:    23  ta632-m  h1235a  w04  d5  2u  1np  25c  0e0
.ic v(48)=0.00000e+00  v(50)=0.00000e+00
* .temp 1.25000000000000e+02
.print tran v(0)
.tran 1.00000000000000e-09 5.30000000000000e-07
.opt acct
.end

*killer3 spice testrun
VIN1 1 0 PULSE(0.E+00 5.E+00 5.E-06 1.E-08 1.E-08 5.E-06
+1.E-05)
VIN2 2 0 PULSE(0.E+00 5.E+00 5.E-06 1.E-08 1.E-08 1.E-05
+2.E-05)
VIN3 3 0 PULSE(0.E+00 5.E+00 5.E-06 1.E-08 1.E-08 2.E-05
+4.E-05)
VIN4 4 0 PULSE(0.E+00 5.E+00 5.E-06 1.E-08 1.E-08 4.E-05
+8.E-05)
V_STRB 5 0 PULSE(0.E+00 5.E+00 5.E-06 1.E-08 1.E-08 2.E-06
+5.E-06)
V_INHB 6 0 PULSE(0.E+00 5.E+00 1.E-04 1.E-08 1.E-08 1.E-04
+2.E-04)
XINV1 1 7 XINV
XINV2 2 8 XINV
XINV3 3 9 XINV
XINV4 4 10 XINV
XINV5 5 11 XINV
XINV6 6 12 XINV
*
XNOR1 7 11 13 XNOR
XNOR2 8 11 14 XNOR
XNOR3 9 11 15 XNOR
XNOR4 10 11 16 XNOR
*
XNOR5 13 11 17 XNOR
XNOR6 14 11 18 XNOR
XNOR7 15 11 19 XNOR
XNOR8 16 11 20 XNOR
*
XLATCH1 13 17 21 22 XLATCH
XLATCH2 14 18 23 24 XLATCH
XLATCH3 15 19 25 26 XLATCH
XLATCH4 16 20 27 28 XLATCH
*
XNOR9 21 23 29 XNOR
XNOR10 22 23 30 XNOR
XNOR11 21 24 31 XNOR
XNOR12 22 24 32 XNOR
XNOR13 27 25 33 XNOR
XNOR14 26 27 34 XNOR
XNOR15 25 28 35 XNOR
XNOR16 26 28 36 XNOR
*
XNAND1 33 29 12 37 XNAND
XNAND2 33 30 12 38 XNAND
XNAND3 33 31 12 39 XNAND
XNAND4 33 32 12 40 XNAND
XNAND5 34 29 12 41 XNAND
XNAND6 34 30 12 42 XNAND
XNAND7 34 31 12 43 XNAND
XNAND8 34 32 12 44 XNAND
XNAND9 35 29 12 45 XNAND
XNAND10 35 30 12 46 XNAND
XNAND11 35 31 12 47 XNAND
XNAND12 35 32 12 48 XNAND
XNAND13 36 29 12 49 XNAND
XNAND14 36 30 12 50 XNAND
XNAND15 36 31 12 51 XNAND
XNAND16 36 32 12 52 XNAND
*
XINV7 37 53 XINV
XINV8 38 54 XINV
XINV9 39 55 XINV
XINV10 40 56 XINV
XINV11 41 57 XINV
XINV12 42 58 XINV
XINV13 43 59 XINV
XINV14 44 60 XINV
XINV15 45 61 XINV
XINV16 46 62 XINV
XINV17 47 63 XINV
XINV18 48 64 XINV
XINV19 49 65 XINV
XINV20 50 66 XINV
XINV21 51 67 XINV
XINV22 52 68 XINV
*
XINV23 53 69 XINV
XINV24 54 70 XINV
XINV25 55 71 XINV
XINV26 56 72 XINV
XINV27 57 73 XINV
XINV28 58 74 XINV
XINV29 59 75 XINV
XINV30 60 76 XINV
XINV31 61 77 XINV
XINV32 62 78 XINV
XINV33 63 79 XINV
XINV34 64 80 XINV
XINV35 65 81 XINV
XINV36 66 82 XINV
XINV37 67 83 XINV
XINV38 68 84 XINV
*
.SUBCKT XINV 1 2
* XINVERTER MODEL
VCC 5 0 5.0
MP1 5 1 2 5 MP W=7U L=3U
MN1 2 1 0 0 MN W=4U L=3U
.ENDS XINV
*
.SUBCKT XNOR 1 2 3
VCC 5 0 5.0
MP1 5 1 4 5 MP W=7U L=3U
MP2 4 2 3 5 MP W=7U L=3U
MN3 3 1 0 0 MN W=4U L=3U
MN4 3 2 0 0 MN W=4U L=3U
.ENDS XNOR
*
.SUBCKT XNAND 1 2 3 4
VCC 5 0 5.0
MP1 5 1 4 5 MP W=7U L=3U
MP2 5 2 4 5 MP W=7U L=3U
MP3 5 3 4 5 MP W=7U L=3U
MN4 4 1 6 0 MN W=4U L=3U
MN5 6 2 7 0 MN W=4U L=3U
MN6 7 3 0 0 MN W=4U L=3U
.ENDS XNAND
*
.SUBCKT XLATCH 1 2 3 4
XNOR1 1 4 3 XNOR
XNOR2 3 2 4 XNOR
.ENDS XLATCH
*
.OPTIONS ITL5=20000
.TEMP 2.7E+01
.PRINT TRAN V(1) V(2) V(3) V(4) V(5) V(6) V(69) V(70) V(71) V(72) V(73)
+    V(74) V(75) V(76) V(77) V(78) V(79) V(80) V(81) V(82) V(83) V(84)
.TRAN 1.E-06 2.E-06
.OPT ACCT
*
*
.MODEL MN NMOS VTO= 1.0 TOX=0.05U LD=0.5U CJ=5E-4 CJSW=10E-10
+KP=40U GAMMA=1.0 UO=550 MJ=0.5 MJSW=0.5 NSUB=1.0E16
+CGSO=0.4E-9 CGDO=0.4E-9 LEVEL=3
.MODEL MP PMOS VTO= -1.0 TOX=0.05U LD=0.5U CJ=5E-4 CJSW=10E-10
+KP=15U GAMMA=0.6 UO=200 MJ=0.5 MJSW=0.5 NSUB=1.0E15
+CGSO=0.4E-9 CGDO=0.4E-9 LEVEL=3
.END

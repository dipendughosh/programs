*killer1 spice testrun
V$D2 1 0 PULSE(4.E+00 8.E+00 9.999999E-08 1.9E-06 9.999999E-08 5.E-07
+3.E-06)
V$D1 12 0 DC 5.E+00
CT 2 3 1000PF
Q5 6 6 8 Q2N2369
Q3 3 6 9 Q2N2369
Q2 12 5 3 Q2N2369
Q4 2 6 7 Q2N2369
Q1 12 4 2 Q2N2369
XI$202 10 3 11 X7400
XI$203 2 11 10 X7400
RT 1 6 100
R4 11 5 130
R2 10 4 130
R5 0 8 10
R1 4 12 470
R3 5 12 470
R6 0 9 10
R7 0 7 10
.OPTIONS ITL5=20000 LIMPTS=5000 INGOLD=2
.MODEL Q2N2369 NPN (IS=1.52PF BF=79 NF=0.998
+ VAF=83.9 IKF=0.35 ISE=0.237P NE=1.72
+ BR=0.255 NR=1.01 VAR=20.5 ISC=0.664N NC=1.79
+ RB=5.8 RE=0.63 RC=7.27 CJE=4.92P
+ VJE=0.502 MJE=0.177 CJC=3.73P VJC=1.1 MJC=0.15
+ TF=0.27N TR=99N)
*
*
* 2-INPUT TTL NAND GATE
* USAGE: X1 <INA> <INB> <OUT> X7400
.SUBCKT X7400 1 2 3
VCC 14 0 5.0
QA 5 4 1 QA
QB 5 4 2 QA
QC 6 5 8 QB
QD 9 6 10 QB
QE 3 8 0 QC
DA 0 1 DS
DB 0 2 DS
DD 10 3 DS
R1 4 14 4K
R2 6 14 1.6K
R3 9 14 130
R4 8 0 1K
.ENDS X7400
*
.MODEL QA NPN (BF=20 BR=0.02 RB=500 RC=40 IS=10F VAF=50
+ CJS=1P TF=0.1N TR=10N CJE=0.5P CJC=1P VJC=0.85 VJE=0.85)
.MODEL QB NPN (BF=20 BR=1 RB=70 RC=40 IS=10F VAF=50
+ CJS=1P TF=0.1N TR=10N CJE=0.5P CJC=1P VJC=0.85 VJE=0.85)
.MODEL QC NPN (BF=20 BR=0.2 RB=20 RC=12 IS=16F VAF=50
+ TF=0.7653N TR=6.9328N CJS=1P CJE=0.5P CJC=1P VJC=0.85 VJE=0.85)
.MODEL DS D (RS=40 IS=10F TT=0.1N CJO=0.9P)
.TEMP 2.7E+01
.PRINT TRAN V(1) V(10) V(11)
.TRAN 4.E-09 2.E-06
.OPT ACCT
*
.END

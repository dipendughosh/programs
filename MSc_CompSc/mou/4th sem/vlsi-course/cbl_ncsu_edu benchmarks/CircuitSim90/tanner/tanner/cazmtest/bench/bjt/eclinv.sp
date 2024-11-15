* ECL CKT - EMITTER COUPLED LOGIC INVERTER

Q1 3 2 4 0 QSTD
Q2 5 6 4 0 QSTD
Q3 8 5 7 0 QSTD
Q4 8 5 7 0 QSTD
RIN 1 2 50
RC1 8 3 120
RC2 8 5 135
RE 4 0 340
RTH1 7 0 125
RTH2 7 0 85
CLOAD 7 0 5P

.MODEL QSTD NPN IS=2E-16 BF=50 BR=0.1 RB=100 RC=10 TF=0.12N
+  TR=5N CJE=0.4P VJE=0.8 MJE=0.4 CJC=0.5P VJC=0.8 MJC=0.333
+  CJS=3P VAF=50 RBM=50 IRB=1.0e-4

VIN 1 0 PULSE(4.0 3.2 1NS 1NS 8NS 20NS)
VCC 8 0 5.0
VREF 6 0 3.6

.OPTIONS ABSTOL=1E-12 RELTOL=1E-5
.TRAN 0.25NS 50NS
.PRINT TRAN V(1) I(VIN) V(3) V(5)
.END

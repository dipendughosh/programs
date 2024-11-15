RTLINV CKT - CASCADE RTL INVERTERS

.MODEL QND NPN(BF=50 RB=70 RC=40 CCS=2PF TF=0.1NS TR=10NS
+ CJE=0.9PF CJC=1.5PF PC=0.85 VA=50)

VCC 6 0 5.0
VIN 1 0 PULSE(0 5 2NS 2NS 2NS 80NS)
RB1 1 2 10K
RC1 6 3 1K
Q1 3 2 0 QND
RB2 3 4 10K
Q2 5 4 0 QND
RC2 6 5 1K

.TRAN 2NS 200NS
.PRINT TRAN V(1) V(3) V(5)
.END


*DIFPAIR CKT - SIMPLE DIFFERENTIAL PAIR
*.MODEL QNL NPN(BF=80 RB=100 CCS=2PF TF=0.3NS TR=6NS CJE=3PF CJC=2PF
.MODEL QNL NPN(BF=80 RB=100 TF=0.3NS TR=6NS CJE=3PF)
Q1 4 2 6 9 QNL
Q2 5 3 6 9 QNL
RS1 1 2 1K
RS2 3 0 1K
RC1 4 8 10K
RC2 5 8 10K
Q3 6 7 9 QNL
Q4 7 7 9 QNL
RBIAS 7 8 20K
.AC DEC 100 1KHZ 100KHZ
VIN 1 0 0.0 AC 1
VCC 8 0 12
VEE 9 0 -12
.PRINT AC VM(5) VP(5) VM(7) VP(7) VDB(1)
.END

* STRING OF OPERATIONAL AMPLIFIERS
.MODEL MP PNP IS=727.80E-18 BF=4.284E3 NF=0.9943 VAF=22.13 IKF=29.820E-6
+ ISE=437.9E-18 NE=1.205
+ BR=25.99E3 NR=0.9743 VAR=18.09 IKR=12.8E-6 ISC=17.09E-15 NC=1.021
+ RB=618.0 IRB=0.0 RBM=0.00001 RE=4.083 RC=103.3
+ XTB=0.0 EG=1.110 XTI=3.0
+ CJE=705.106E-15 VJE=1.108 MJE=0.99
+ CJC=1.467E-12 VJC=0.899 MJC=0.99 XCJC=1.0
+ CJS=-3.508E-12 VJS=1.893 MJS=1.980E-22
+ FC=0.5
+ TF=50.0E-9 XTF=0.0 VTF=0.0 ITF=0.0 TR=50.00E-9
+ PTF=0.0
+ KF=0.0 AF=0.0

.MODEL MN NPN IS=53.30E-18 BF=235.9 NF=0.9724 VAF=632.9 IKF=10.86E-3
+ ISE=1.567E-18 NE=1.046
+ BR=0.3272 NR=0.9916 VAR=2.473 IKR=1.388E-3 ISC=1.06E-15 NC=0.9955
+ RB=182.2 IRB=0.0 RBM=0.00001 RE=1.876 RC=207.6
+ XTB=0.0 EG=1.110 XTI=3.0
+ CJE=1.006E-12 VJE=0.4938 MJE=0.1034
+ CJC=786.700E-15 VJC=0.3367 MJC=0.1233 XCJC=1.0
+ CJS=2.488E-12 VJS=0.2636 MJS=0.1262
+ FC=0.5
+ TF=150.0E-12 XTF=0.0 VTF=0.0 ITF=0.0 TR=1.50E-9
+ PTF=0.0
+ KF=0.0 AF=0.0
*
*.SUBCKT OPAMPAL 200 300 400 0
*QNAME    C    B    E    S    TRANSISTOR TYPE
*
* NON	INV	OUT	VMINUS	VPLUS	IN	IN2
* 200	300	400	500	600	700	800
*
QA    600   200         1    500    MN
QB    600   300         2    500    MN
*
QC       14    14         1    500 MP
QD       14    14         1    500 MP
QE       14    14         1    500 MP
QF        3    14         1    500 MP
*
QG        4    14         2    500 MP
QH       14    14         2    500 MP
QI       14    14         2    500 MP
QJ       14    14         2    500 MP
* CURRENT SOURCES
QK        3     3    500    500    MN
QL        4     3    500    500    MN
*
QZA      13    13    500    500    MN
QZB      14    13    500    500    MN
QZC      16    16    500    500    MN
QZD      15    16    500    500    MN
* SECOND STAGE
QM    600     4         5    500    MN
QQ        6     5    500    500    MN
QS       15    15     600    500 MP
QT        9    15     600    500 MP
QU        9     9         8    500    MN
QV    600     9        10    500    MN
QW        9     7         6    500    MN
* THIRD STAGE
QNA     600    10    11    500    MN
QNB     600    10    11    500    MN
QNC     600    10    11    500    MN
QND     600    10    11    500    MN
QNE     600    10    11    500    MN
*
QPA    500     6    12    500 MP
QPB    500     6    12    500 MP
QPC    500     6    12    500 MP
QPD    500     6    12    500 MP
QPE    500     6    12    500 MP
QPF    500     6    12    500 MP
QPG    500     6    12    500 MP
QPI    500     6    12    500 MP
QPJ    500     6    12    500 MP
*
R1        8      7    33K
R2        6      7    50K
R3       10      6    83K
R4       11    400    150
R5      400     12    150
R6    600     13    15MEG
R7    600     16    2.3MEG
*
C1        6      4    4.3PF
*
VPOS    600    0    35V
VNEG    0    500   35V
*VNEG    500   0 -35V
*
*
*
vnon 200 0 0
cin 700 800 1u
rin 800 300 100k
rf 300 400 600k
rl 400 0 10000k
*XA     200    300    400    0  OPAMPAL
*


Vin 700 0 0.0 AC 0.1 0.0
.ac dec 20 1000 100000
.print ac vm(400) vp(400) vm(6) vm(10) 
.options limpts=10000
.end




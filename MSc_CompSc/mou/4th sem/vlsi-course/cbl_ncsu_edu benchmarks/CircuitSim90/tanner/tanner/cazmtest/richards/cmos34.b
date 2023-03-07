*********************************************************
*                                                       *
*  NID SPICE MOSFET MODEL PARAMETERS (CMOS34 PROCESS)   *
*               Berkeley Model Level 3                  *
*                                                       *
*               BEST DEVICE PARAMETERS                  *
*                                                       *
*      JIM LOONEY   Revision Date 1/10/91              *
*                                                       *
*********************************************************
* TEMP = 27C
.MODEL nenh NMOS LEVEL=3 UO=535 VTO=.66 TOX=188E-10 NSUB=2.8E16
+LD=.22U RSH=450 XJ=0.1U ETA=.02 DELTA=.6 THETA=.07 KAPPA=.1
+VMAX=1.35E5 JS=1000U PB=0.8 CGSO=160P CGDO=160P CGBO=220P
+CJ=290U MJ=0.95 CJSW=240P MJSW=0.12 FC=0 NFS=0
*2WD=.40U

.MODEL penh PMOS LEVEL=3 UO=187 VTO=-.81 TOX=188E-10 NSUB=2.8E16
+LD=.10U RSH=1000 XJ=.000U ETA=.09 DELTA=0.3 THETA=.130 KAPPA=3
+VMAX=1.9E5 JS=1000U PB=0.9 CGSO=160P CGDO=160P CGBO=220P
+CJ=470U MJ=0.50 CJSW=235P MJSW=0.33 FC=0 NFS=0
*2WD=.60U


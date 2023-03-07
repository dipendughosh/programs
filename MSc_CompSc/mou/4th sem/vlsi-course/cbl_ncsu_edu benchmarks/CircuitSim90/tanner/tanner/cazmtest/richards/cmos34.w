*********************************************************
*                                                       *
*  NID SPICE MOSFET MODEL PARAMETERS (CMOS34 PROCESS)   *
*               Berkeley Model Level 3                  *
*                                                       *
*              WORST DEVICE PARAMETERS                  *
*                                                       *
*      JIM LOONEY   Revision Date 1/10/91              *
*                                                       *
*********************************************************
* TEMP = 27C
.MODEL nenh NMOS LEVEL=3 UO=505 VTO=.80 TOX=212E-10 NSUB=2.8E16
+LD=.08U RSH=850 XJ=0.1U ETA=.02 DELTA=.6 THETA=.07 KAPPA=.1
+VMAX=1.35E5 JS=1000U PB=0.8 CGSO=210P CGDO=210P CGBO=280P
+CJ=350U MJ=0.95 CJSW=300P MJSW=0.12 FC=0 NFS=5E11
*2WD=.80U

.MODEL penh PMOS LEVEL=3 UO=173 VTO=-.99 TOX=212E-10 NSUB=2.8E16
+LD=-.10U RSH=1400 XJ=.000U ETA=.09 DELTA=0.3 THETA=.130 KAPPA=3
+VMAX=1.9E5 JS=1000U PB=0.9 CGSO=210P CGDO=210P CGBO=280P
+CJ=570U MJ=0.50 CJSW=325P MJSW=0.33 FC=0 NFS=1E12
*2WD=1.0U


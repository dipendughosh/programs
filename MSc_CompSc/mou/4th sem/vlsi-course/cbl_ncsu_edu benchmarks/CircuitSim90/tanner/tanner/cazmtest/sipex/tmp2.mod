**************************************************************************
**                                                                      **
**                      ( MODEL HCMOS1F_N.Jan92)                        **
**                                                                      **
**      CAzM  PARAMETERS                                                **
**      UMC HCMOS-1F 3um parameters per UMC                             **
**      document 161-503-HCMOS-1F pg. 11/32  Rev. No. 17 (10/17/91)     **
**      ( NOMINAL CASE )    January 1992                                **
**                                                                      **
**      W. R. Richards    January 1992                                  **
**                                                                      **
**	Note:								**
**									**
**	The original UMC models contained two parameters Cjpar and      **
**	Cjswpar, neither of which are valid Level 2 parameters as       **
**	implemented in CAzM. Also, the UMC models specified fixed       **
**	series resistances of Rs=Rd=30 ohms for the nenh model and      **
**	Rs=Rd=50 ohms for the penh model. These models contain the 	**
**	N+ and P+ sheet rho values.					**
**									**
**************************************************************************

.model nenh2 nmos
+    Level=2                    Ld=1.0e-6               Tox=4.650000e-08
+    Nsub=1.000000e+16          Vto=0.8000              Kp=4.401336e-05
+    Gamma=0.972734             Pb=0.700                Uo=510.000
+    Uexp=0.350000              Ucrit=0.85e5            Delta=0.2000
+    Vmax=0.7e5                 Xj=1.1000e-06           Lambda=0.003
+    Nfs=5.000000e+11           Neff=6.42404            Nss=3.000000e+10
+    Tpg=1.00000                Rsh=32                  Cgso=7.50e-10
+    Cgdo=7.50e-10              Cj=2.44e-04             Mj=0.410
+    Cjsw=0.35e-9               Mjsw=.250		Wd=0.60e-6
+    Fc=0.500

.model penh2 pmos
+    Level=2                    Ld=0.5e-6               Tox=4.650000e-08
+    Nsub=3.000000e+15          Vto=-0.8500             Kp=2.339845e-05 
+    Gamma=0.708383             Pb=0.64                 Uo=230.000
+    Uexp=0.40                  Ucrit=0.59e5            Delta=0.5000
+    Vmax=2.7000e4              Xj=0.600000e-6          Lambda=0.017 
+    Nfs=5.000000e+11           Neff=14.4786            Nss=3.000000e+10
+    Tpg=-1.0000                Rsh=110                 Cgso=3.70e-10
+    Cgdo=3.70e-10              Cj=1.69e-04             Mj=0.450
+    Cjsw=1.01e-10              Mjsw=0.300		Wd=0.60e-6
+    Fc=0.500

**************************************************************************
**                                                                      **
**                      (MODEL HCMOS1F_N_Lev3.Jan92)                    **
**                                                                      **
**      CAzM  PARAMETERS                                                **
**      UMC HCMOS-1F 3um parameters per UMC                             **
**      NO OFFICIAL UMC documentation !!!				**
**      ( NOMINAL CASE )    January 1992                                **
**                                                                      **
**      W. R. Richards    January 1992                                  **
**                                                                      **
**	Note:								**
**									**
**	The original models from CML appeared to have CGS0/CGD0 swapped	**
**	from best to worst. In these files they are swapped from our	**
**	original communication. Also, the UMC models specified fixed    **
**	series resistances of Rs=Rd=30 ohms for the nenh model and      **
**	Rs=Rd=50 ohms for the penh model. These models contain the 	**
**	N+ and P+ sheet rho values.					**
**									**
**************************************************************************

* Following are CML's comments

********************************************************************************
*									       *
*                            Basic Device Models                               *
*                                for SPICE2G5				       *
*									       *
*     The following models are the basic device models for CL circuit          *
* simulation of UMC's HCMOS-lF #17 process i.e. SILICON GATE. These are the    *
* TYPICAL parameters as given by UMC.                                          *
*     NOTE: These are the new level 3 models (We usually use level 2)          *
*     These models have not yet been fully tested or compared with reality.    *
* (so what's new) They may well be FUBAR                                       **                                                                              *
*                                           Keith Walker                       *
*                                    6th Dececember 1991                       *
*                                                                              **                                                                              *
********************************************************************************

.MODEL nenh3 NMOS LEVEL=3 VTO=0.8 TPG=1.0
+ TOX=4.65E-8 NSUB=1.0E16 XJ=1.1E-6 NFS=5.0E11 VMAX=1.5E5 PB=0.7
+ LD=0.9E-6 RSH=32
+ CJ=2.44E-4 CGSO=6.8E-10 CGDO=6.8E-10 CJSW=0.35E-9
+ DELTA=3.1 THETA=0.051 ETA=0.073 KAPPA=0.001
+ UO=580 FC=0.5
+ MJ=0.41 MJSW=0.25
*+ RD=30 RS=30


.MODEL penh3 PMOS LEVEL=3 VTO=-0.8 TPG=-1.0
+ TOX=4.65E-8 NSUB=1.4E15 XJ=0.6E-6 NFS=5.0E11 VMAX=1.2E5 PB=0.64
+ LD=0.25E-6 RSH=110
+ CJ=1.69E-4 CGSO=1.9E-10 CGDO=1.9E-10 CJSW=1.01E-10
+ DELTA=0.19 THETA=0.095 ETA=0.95 KAPPA=2.0
+ UO=220 FC=0.5
+ MJ=0.45 MJSW=0.3
*+ RS=50 RD=50

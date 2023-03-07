**************************************************************************
**									**
**			( MODEL Mosis2CW )				**
**									**
**	SPICE PARAMETERS						**
**	Mosis 2 micron scalable n-well 					**
**	( WORST )							**
**									**
**	Note:	From corner spice decks for 2um VTI process.      	**
**		BSIM preferred to Spice level 2.  Also see		**
**		mosis memo regarding deltaW for effective 		**
**		width calculations.  This model assumes 		**
**		worst case deltaL.					**
**									**
**	-ravi, Feb 10, 1988						**
**									**
**************************************************************************

.model nenh nmos
+    Level=2            Ld=0.05u        Tox=430.000e-10
+    Nsub=1.0e+16       Vto=0.90        Uo=620.0
+    Uexp=0.125         Ucrit=62000     Delta=1.4
+    Vmax=51000         Xj=.15u         Lambda=0.0
+    Neff=4.00          Tpg=1.00000     Rsh=38 
+    Cgso=2.10e-10      Cgdo=2.10e-10   Cj=2.15e-04 
+    Mj=0.76            Cjsw=5.40e-10   Mjsw=0.30
+    Pb=0.8

.model penh pmos
+    Level=2            Ld=0.05u        Tox=430.000e-10  
+    Nsub=6.6e+15       Vto=-0.90000    Uo=240.0
+    Uexp=0.29          Ucrit=86000     Delta=1.0
+    Vmax=30000         Xj=0.050000u    Lambda=0.    
+    Neff=2.65000       Tpg=-1.00000    Rsh=110         
+    Cgso=2.05e-10      Cgdo=2.05e-10   Cj=2.75e-04     
+    Mj=.535            Cjsw=4.00e-10   Mjsw=.34
+    Pb=0.8

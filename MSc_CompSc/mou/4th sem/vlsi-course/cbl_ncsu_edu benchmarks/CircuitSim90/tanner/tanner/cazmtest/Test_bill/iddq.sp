a2 opamp
*
**************************************************************************
**                                                                      **
**                      ( MODEL M125CN-189)                             **
**                                                                      **
**      SPICE PARAMETERS                                                **
**      MCNC 1.25 CMOS PROCESS                                          **
**      ( NOMINAL )     April 1989                                      **
**                                                                      **
**      SHG-J                                                           **
**                                                                      **
**************************************************************************
*
.model nenh nmos
+    Level=2                    Ld=0.0                  Tox=2.250000e-08
+    Nsub=9.318073e+16          Vto=0.626634            Kp=5.28837e-05
+    Gamma=0.287822             Phi=0.880849            Uo=511.152      
+    Uexp=0.01615777            Ucrit=200.              Delta=3.02002
+    Vmax=57064.3               Xj=9.000000e-07                
+    Nfs=0.00000                Neff=.261026            Nss=3.000000e+10
+    Tpg=1.00000                Rsh=68                  Cgso=2.89e-10
+    Cgdo=2.89e-10              Cj=3.45e-04             Mj=.916
+    Cjsw=1.74e-10              Mjsw=.195

.model penh pmos
+    Level=2                    Ld=6.000000e-08         Tox=2.250000e-08
+    Nsub=8.555868e+14          Vto=-0.617486           Kp=1.930325e-05 
+    Gamma=0.527415             Phi=.8500               Uo=33.9632
+    Uexp=0.141605              Ucrit=98755.5           Delta=6.01138
+    Vmax=6786.31               Xj=5.031585e-9           
+    Nfs=1.0000e+11             Neff=12.182             Nss=3.000000e+10
+    Tpg=-1.0000                Rsh=154                 Cgso=3.35e-10
+    Cgdo=3.35e-10              Cj=4.21e-04             Mj=.3285
+    Cjsw=2.23e-10              Mjsw=.307
* Spice3c1 input file
*
m1 2 2 1 1 penh l=5u w=10u
m2 2 2 0 0 nenh l=5u w=10u
m3 1 3 3 1 penh l=6u w=48u
m5 1 3 5 1 penh l=6u w=48u
m4 3 10 4 0 nenh l=5u w=50u
m6 5 20 4 0 nenh l=5u w=50u
m7 4 2 0 0 nenh l=5u w=5u
mt1 6 6 1 1 penh l=5u w=10u
mt2 20 6 1 1 penh l=5u w=10u
mt3 0 5 20 1 penh l=5u w=10u
idut 6 0 5n
vref 10 0 4.5
*
*
* DC operating point analysis
*
vdd 1 0 5.0


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

.model nenh nmos
+    Level=2                    Ld=0.0                  Tox=2.250000e-08
+    Nsub=9.318073e+16          Vto=0.626634            Kp=5.28837e-05
+    Gamma=0.287822             Phi=0.880849            Uo=511.152      
+    Uexp=0.01615777            Ucrit=200.              Delta=3.02002
+    Vmax=57064.3               Xj=9.000000e-07         Lambda=0.       
+    Nfs=0.00000                Neff=.261026            Nss=3.000000e+10
+    Tpg=1.00000                Rsh=68                  Cgso=2.89e-10
+    Cgdo=2.89e-10              Cj=3.45e-04             Mj=.916
+    Cjsw=1.74e-10              Mjsw=.195

.model penh pmos
+    Level=2                    Ld=6.000000e-08         Tox=2.250000e-08
+    Nsub=8.555868e+14          Vto=-0.617486           Kp=1.930325e-05 
+    Gamma=0.527415             Phi=.8500               Uo=33.9632
+    Uexp=0.141605              Ucrit=98755.5           Delta=6.01138
+    Vmax=6786.31               Xj=5.031585e-9          Lambda=0. 
+    Nfs=1.0000e+11             Neff=12.182             Nss=3.000000e+10
+    Tpg=-1.0000                Rsh=154                 Cgso=3.35e-10
+    Cgdo=3.35e-10              Cj=4.21e-04             Mj=.3285
+    Cjsw=2.23e-10              Mjsw=.307

*
* Simple CMOS op-amp for AC analysis   wrr 1/11/90
*
mbias 30 30 0 0 nenh l=3.0u w=80u
m1 2 10 1 1 nenh l=2.5u w=50u
m2 3 20 1 1 nenh l=2.5u w=50u
m3 1 30 0 0 nenh l=3.0u w=40u
m4 2 2 40 40 penh l=3.0u w=14u
m5 3 2 40 40 penh l=3.0u w=14u
*
m6 60 30 0 0 nenh l=3.0u w=120u
m7 60 3 40 40 penh l=3.0u w=80u
*
cc 3 60 20p
cload 60 0 15p


Vdd 40 0 5.0
Vdd2 80 0 5.0
Vinp 10 0 2.50015
Vinm 20 0 2.5 AC 0.001 0.0
ibias 80 30 75u
.ac dec 10 10 10MEG
.print ac vm(10,0) vm(20) vm(60,0) im(Vdd2)
.options limpts=10000
.end



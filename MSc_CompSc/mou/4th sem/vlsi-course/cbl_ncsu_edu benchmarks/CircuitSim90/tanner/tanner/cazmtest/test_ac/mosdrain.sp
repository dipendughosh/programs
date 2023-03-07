

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
+    Tpg=1.00000                Cgso=2.89e-10           Cgdo=2.89e-10 
+    Cj=3.45e-04                Mj=.916
+    Cjsw=1.74e-10              Mjsw=.195
+    Rsh=68
+    Rs=2000
+    Rd=2000


Rd 1 2 20000
Rs 3 33 5000
Rb 5 55 1
Rg 4 10 1
M1 2 4 3 5 nenh l=1.0u w=10.0u  ad=10.0p pd=16u as=10.0p ps=16u


VDD 1 0 5.0
VSS 33 0 0.0
VBB 55 0 0.0
VIN 10 0 1.5 AC 0.5 0.0
.ac dec 2 1MEG 10000MEG
.print ac ir(VDD) ir(VDD) ir(VIN) ir(VSS) ir(VBB)
.print dc i(VDD) i(VDD) i(VIN) i(VSS) i(VBB)
.options limpts=10000 gmin=1.0e-18 reltol=1.0e-15 abstol=1.0e-15
.end


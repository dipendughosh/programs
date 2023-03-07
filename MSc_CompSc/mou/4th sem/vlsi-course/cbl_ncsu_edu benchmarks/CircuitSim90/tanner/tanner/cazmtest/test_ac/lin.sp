
.MODEL PN D IS=1e-16  RS=100 N=1.0  TT=1N CJO=3PF VJ=0.7 M=0.67 EG=1.12

D1 2 1 PN 3
R1 2 0 100

Vin 1 0 -1.25 AC 0.25 0.0
.ac lin 15 100MEG 10000MEG
.print ac vm(2) vp(2) vr(2) vi(2) vdb(2)
.options limpts=10000
.end





.MODEL PN D IS=1e-16  RS=100 N=1.0  TT=1N CJO=3PF VJ=0.7 M=0.67 EG=1.12

D1 1 2 PN 3
R1 2 0 1

VIN 1 0 -1.25 AC 0.25 0.0
.ac dec 10 100MEG 10000MEG
.print ac ir(VIN) ii(VIN) 
.options limpts=10800  gmin=1.0e-25
.end





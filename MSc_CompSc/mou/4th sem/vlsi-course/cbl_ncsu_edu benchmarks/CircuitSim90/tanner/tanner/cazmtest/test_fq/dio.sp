

.MODEL PN D IS=1e-16  RS=100 N=1.0  TT=.5N CJO=0PF VJ=0.7 M=0.67 EG=1.12

D1 1 2 PN 3
R1 2 0 100

VIN 1 0 SIN(0.5 3.0 200MEG  0.0 0.0) 
.tran .01n 20ns
.print tran v(1) v(2) i(VIN) 
.options limpts=50000 itl5=10000 reltol=1.0e-8
.end








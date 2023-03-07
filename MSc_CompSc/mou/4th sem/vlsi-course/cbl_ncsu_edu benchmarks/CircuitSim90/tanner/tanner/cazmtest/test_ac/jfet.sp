
.model mjn njf 
+ vto=-2 beta=1.0e-4 lambda=0 cgs=1p cgd=1p pb=0.7
+ is=1.0e-14 fc=0.5


Rd 1 2 20000
Rs 3 7 2000
Rg 4 5 1

J1 2 5 3 mjn


VDD 1 0 5.0
VSS 7 0 0.0
VIN 4 0 0.5 AC 1.0 0.0
.ac dec 100 10MEG 1000MEG
.print ac ir(VDD) ii(VDD) ir(VIN) ii(VIN) ir(VSS) ii(VSS)
.options limpts=10000
.end



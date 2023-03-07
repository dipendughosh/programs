


R1 1 2 10000
R2 2 3 10000


VIN  3 0 0.0
ICUR 1 0 5.0u 
.print tran v(2) i(VIN)
.tran .1n 2n 
.options limpts=50000 itl5=10000 reltol=1.0e-8
.end





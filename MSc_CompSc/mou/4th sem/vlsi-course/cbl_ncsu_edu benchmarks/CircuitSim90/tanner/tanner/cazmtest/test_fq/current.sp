
ICIN 1 0 5u
R2 2 3 10000
VNOW 3 4 0.0
R4 4 0 10000

VIN 1 2 sin (0.0 0.0 10MEG 0.0 0.0)

.print tran i(VIN) i(VNOW) v(3) 
.tran .2n 2n 
.options limpts=50000 itl5=10000 reltol=1.0e-8
.end





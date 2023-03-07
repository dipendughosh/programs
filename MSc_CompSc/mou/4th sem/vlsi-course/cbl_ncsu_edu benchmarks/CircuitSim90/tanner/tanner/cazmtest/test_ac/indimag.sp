
ICIN 1 0 0.0 AC -1
VIN 2 1 0.0
la 2 0 100n


.ac lin 10 8.0e7 3.2e8
.print ac vm(2,0) vp(2,0) ir(VIN) ii(VIN) im(VIN) ip(VIN)
.options limpts=10000  gmin=1.0e-25
.end
 

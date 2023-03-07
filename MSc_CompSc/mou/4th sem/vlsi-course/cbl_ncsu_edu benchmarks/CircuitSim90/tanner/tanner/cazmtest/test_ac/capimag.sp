
VIN 2 0 0.0 AC 1
ca 2 0 100n


.ac lin 10 8.0e7 3.2e8
.print ac vm(2,0) vp(2,0) im(VIN) ip(VIN) ir(VIN) ii(VIN)
.options limpts=10000  gmin=1.0e-25
.end
 

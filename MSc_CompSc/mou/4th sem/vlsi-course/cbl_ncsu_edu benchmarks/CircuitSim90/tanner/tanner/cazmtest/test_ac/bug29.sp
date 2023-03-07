
ICIN 1 0 0.0 AC -1
VIN1 1 2 0.0
la 2 0 100n

VIN2 1 3 0.0
lb 3 0 100n

.ac lin 1 8.0e7 8.0e7
.print ac vm(2,0) vp(2,0) ir(VIN1) ii(VIN1) ir(VIN2) ii(VIN2)
.options limpts=10000  gmin=1.0e-25
.end
 

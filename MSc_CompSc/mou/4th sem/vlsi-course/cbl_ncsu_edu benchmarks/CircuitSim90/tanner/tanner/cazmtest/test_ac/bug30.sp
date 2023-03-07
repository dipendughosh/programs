
ICIN 1 0 0.0 AC -1

VIN1 1 2 0.0
ra 2 0 100u

VIN2 1 3 0.0
rb 3 0 100u

.ac lin 1 8.0e7 8.0e7
.print ac ir(VIN1) ii(VIN1) ir(VIN2) ii(VIN2) vm(2,0) vm(3,0)
.options limpts=10000  gmin=1.0e-25
.end
 



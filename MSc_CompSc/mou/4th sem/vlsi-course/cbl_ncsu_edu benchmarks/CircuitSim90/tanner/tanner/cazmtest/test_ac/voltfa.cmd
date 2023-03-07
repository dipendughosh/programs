

ac dec 10 1MEG 10MEG
plot voltfa_cz1 {
	ir(VIN,vin) ii(VIN,vin)
	ir(rone,cap1) ii(rone,cap1)
	ir(cone,GND) ii(cone,GND)
}
plot voltfa_cz2 {
	ir(VIN7,GND) ii(VIN7,GND) 
	ir(r3,vin6)  ii(r3,vin6)
	ir(VIN5,vin5) ii(VIN5,vin5)
	ir(rtwo,cap2) ii(rtwo,cap2)
	ir(ctwo,GND) ii(ctwo,GND)
}

plot voltfa_cz3 {
	ir(VIN4,vin4)   ii(VIN4,vin4)
	ir(VIN3,vin3)   ii(VIN3,vin3)
	ir(rthree,cap3) ii(rthree,cap3)
	ir(cthree,GND) ii(cthree,GND)
}


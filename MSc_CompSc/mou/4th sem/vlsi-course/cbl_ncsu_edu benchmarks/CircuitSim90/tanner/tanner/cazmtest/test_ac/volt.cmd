
wave vin17 GND sin amp=2.0 freq=100MEG label=VIN17
volt vin16 vin15 0.0 label=VIN15

*	volt - resistor  - cap
volt vin GND 2.5 acmag= 2.0 acphase= 0.0 label=VIN

*	volt - resistor - volt - resistor - cap
volt vin7 GND 2.5 acmag= 2.0 acphase= 0.0 label=VIN7
volt vin6 vin5 0.0 label=VIN5

*	volt - volt - resistor - cap
volt vin4 GND 0.0 acmag= 2.0 acphase= 0.0 label=VIN4
volt vin3 vin4 2.5 label=VIN3

dcoppt

*
*	TRANSIENT ANALYSIS
*
transient 10n 
plot volt_cz { 
	i(VIN17,vin17)
	i(r13,vin16)
	i(VIN15,vin15)
	i(c12,0) 
	i(r12,cap12)

	itx(VIN17,vin17)
	itx(r13,vin16)
	itx(VIN15,vin15)
	itx(r12,cap12)
	itx(c12,GND) 
}

*
*	AC ANALYSIS
*
ac dec 10 1MEG 10MEG
plot volt_cz1 {
	idc(VIN,vin)
	idc(rone,cap1)
	idc(cone,GND)

	ir(VIN,vin) ii(VIN,vin)
	ir(rone,cap1) ii(rone,cap1)
	ir(cone,GND) ii(cone,GND)
}
plot volt_cz2 {
	ir(VIN7,vin7) ii(VIN7,vin7) 
	ir(r3,vin6) ii(r3,vin6)
	ir(VIN5,vin5) ii(VIN5,vin5)

	ir(rtwo,cap2) ii(rtwo,cap2)
	ir(ctwo,GND) ii(ctwo,GND)
	vm(vin5) 
	vm(cap2) 
}

plot volt_cz3 {
	ir(VIN4,vin4)   ii(VIN4,vin4)
	ir(VIN3,vin3)   ii(VIN3,vin3)
	ir(rthree,cap3) ii(rthree,cap3)
	ir(cthree,GND) ii(cthree,GND)
}




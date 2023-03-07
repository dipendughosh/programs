
volt n2 n1 5.0 label=VIN1
volt n3 n2 3.0 label=VIN2
plot {i(VIN1,n1) i(VIN2,n2) i(Rseries,gate) i(C1,GND) }
transient 100n .1n powerup




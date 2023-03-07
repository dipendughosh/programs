
volt in GND 5.0 label=VIN
plot {i(VIN,in) i(VIN,GND) i(Rseries,in) i(C1,gate) }
transient 100n .1n powerup





volt in new 5.0 label=VIN
plot {i(VIN,new) i(VIN,in) i(Rseries,in) i(C1,gate) }
transient 100n .1n powerup


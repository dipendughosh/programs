

wave in new sin amp=5 freq=50000000 offset=0 delay=0.5n label=VIN
plot { i(VIN,new) i(VIN,in) i(Rseries,in) i(C1,gate) }
transient 100n .1n powerup



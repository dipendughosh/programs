wave 1 GND sin amp=3.0 freq=200MEG offset=.5 label=VIN
transient 20n .1n
plot { V(1) V(2) i(VIN,1) i(D1,2) i(R1,2) }



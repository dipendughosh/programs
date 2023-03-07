wave 1 GND sin amp=0.05 freq=200MEG offset=0.8 label=VIN
transient 20n 1n
plot { V(1) V(2) i(T1,1) i(T1,2) i(R1,2) }
options reltol=1.0e-10 abstol=1.0e-12



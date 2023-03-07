

wave in new sini amp=5.0u freq=50000000 offset=0 label=VIN
plot { i(VIN,new) i(VIN,in) i(Rseries,in) i(C1,gate) v(new,in)  v(in, gate) in gate }
transient 100n .1n powerup







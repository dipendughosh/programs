

wave in GND sini amp=5.0u freq=50000000 offset=0 label=CIN
plot { i(CIN,in) i(CIN,GND) i(Rseries,in) i(C1,gate) v(GND,in)  v(in, gate) in gate }
transient 100n .1n powerup


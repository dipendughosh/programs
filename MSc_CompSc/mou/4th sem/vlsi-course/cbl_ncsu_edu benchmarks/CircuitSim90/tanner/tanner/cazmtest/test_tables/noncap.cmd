
wave in sin amp=3.0 freq=50000000 offset=1.5 delay=20.0n
plot { in n1 i(in,n1) q(n1,GND) }

table noncap nonlincap.ftx nonlincap.qtx
transient 100n .1n dcoppt

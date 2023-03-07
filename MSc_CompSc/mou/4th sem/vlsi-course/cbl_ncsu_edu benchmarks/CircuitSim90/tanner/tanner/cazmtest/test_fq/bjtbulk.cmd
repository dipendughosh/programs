
volt vcc GND 5.0
wave in sin amp=0.2 freq=50000000 offset=.8 delay=20.0n
plot {vcc in b1 c1 i(Q1,b1) i(Q1,c1) i(Q1,GND) q(Q1,b1) }
transient 200n .2n 


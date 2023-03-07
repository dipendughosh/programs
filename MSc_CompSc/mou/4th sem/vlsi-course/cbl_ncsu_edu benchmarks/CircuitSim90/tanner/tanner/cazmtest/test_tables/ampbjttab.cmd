
volt vcc GND 10.0
wave in sin amp=0.3 freq=50000000 offset=.8 delay=20.0n
wave in2 sin amp=0.3 freq=50000000 offset=.8 delay=20.0n

table pbjt pnp.ftx pnp.qtx
table nbjt npn.ftx npn.qtx

plot {in b1 c1 in2 b2 c2}
transient 150n .2n 



gridsize mos 30 60 4
vrange mos 15
volt vdd vss 13.0
wave gate sin amp=0.5 freq=50000000 offset=1.5 delay=20.0n
plot {n1 n2}
plot {gate}
transient 150n .1n powerup

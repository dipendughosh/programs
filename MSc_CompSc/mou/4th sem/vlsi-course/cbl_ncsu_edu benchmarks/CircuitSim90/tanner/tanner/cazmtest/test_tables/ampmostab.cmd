
volt vdd vss 5.0
wave gate sin amp=0.5 freq=50000000 offset=1.5 delay=20.0n
wave gate2 sin amp=0.5 freq=50000000 offset=3.5 delay=20.0n

table nenhtable nmos.ftx nmos.qtx
table penhtable pmos.ftx pmos.qtx

plot {
gate n1 n2
gate2 n3 n4
}
transient 150n .1n dcoppt

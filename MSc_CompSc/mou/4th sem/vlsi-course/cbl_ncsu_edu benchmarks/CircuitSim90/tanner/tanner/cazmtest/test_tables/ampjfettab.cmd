
volt vdd vss 5.0
wave gate sin amp=0.5 freq=50000000 offset=0.0 delay=20.0n
wave gate2 sin amp=0.5 freq=50000000 offset=0.0 delay=20.0n

table njfet njf.ftx njf.qtx
table pjfet pjf.ftx pjf.qtx
plot {gate n1 n2  gate2 n3 n4}
transient 150n .1n powerup




wave c sin amp=5.0 freq=50000000 offset=0.0 delay=20.0n
table diotable dio.ftx dio.qtx
plot {a d c v(a,d)}
transient 200n .1n  powerup  


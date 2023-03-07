
*options numnt=100
wave a sin amp=5.0 freq=50000000 offset=0.0 delay=10.0n
plot {a b c  v(b,c) }
transient 100n  powerup  


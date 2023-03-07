
options numnt=100 chargetol=1.0e-12
wave a d sin amp=5.0 freq=50000000 offset=0.0 delay=10.0n
plot {a d b }
transient 100n .5n  powerup  


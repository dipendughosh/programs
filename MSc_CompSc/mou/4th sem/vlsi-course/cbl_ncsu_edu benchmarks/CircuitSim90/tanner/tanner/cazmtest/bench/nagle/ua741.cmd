wave 30 0 sin  label=VIN freq=10K amp=0.1 damp=AC offset=0 delay=2.5U 
options reltol=0.0001
transient 250u 2.0u
plot { v(30) v(8) v(24)}

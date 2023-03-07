wave 200 2 sin  label=VIN freq=20K amp=0.001 damp=0.0 offset=0.0 delay=0.0 
options format=7 abstol=1.0e-12
plot { v(18) v(203) v(200) v(201) }
transient 200000n 100n

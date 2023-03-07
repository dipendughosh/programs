wave 1 0 sin  label=VIN freq=10K amp=0.1 damp=0 offset=0 delay=2.5US 
plot { V(1) V(30) V(7) V(18)}
transient 250US 2.0US
options reltol=1E-5

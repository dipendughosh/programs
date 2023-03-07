wave 40 0 sin  label=VIN freq=500KHZ amp=0.2 damp=AC offset=0 delay=0.05US 
transient 10US 0.01us

plot { V(40) V(10) V(18)}

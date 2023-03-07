wave 1 0 sin  label=VIN1 freq=50 amp=100 offset=0 
wave 2 0 sin  label=VIN2 freq=50 amp=-100 offset=0 
transient 20MS 0.2MS
plot { V(1) V(2) V(3) V(4)}

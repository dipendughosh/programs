wave 1 0 sin  label=VIN freq=50MEG amp=0.1 damp=0.0 offset=0 delay=0.5NS 
plot { V(1) V(16) V(17)}
transient 200NS 0.5NS


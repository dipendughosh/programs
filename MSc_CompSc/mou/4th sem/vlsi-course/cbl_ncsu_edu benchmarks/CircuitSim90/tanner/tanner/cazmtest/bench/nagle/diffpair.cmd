wave 1 0 sin  label=VIN freq=5MEG amp=0.1 damp=AC offset=0.0 delay=5NS 
transient 500ns 5ns
plot { V(1) V(4) V(5) }

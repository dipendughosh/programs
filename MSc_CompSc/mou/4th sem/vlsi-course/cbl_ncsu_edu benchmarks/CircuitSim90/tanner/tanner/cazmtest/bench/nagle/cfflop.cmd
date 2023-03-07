wave 99 0 sin  label=VIN freq=2MEG amp=1 damp=0 offset=0 delay=20NS 
transient 1000NS 1NS
plot { V(99) V(3) V(6)}
options format=6

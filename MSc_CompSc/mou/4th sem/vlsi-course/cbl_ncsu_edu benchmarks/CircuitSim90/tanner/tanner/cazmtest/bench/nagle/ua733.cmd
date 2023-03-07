wave 99 0 sin  label=VIN freq=5MEG amp=0.1 damp=0.0 offset=0 delay=0.5NS 
transient 1000NS 5NS
plot { V(99) V(3) V(14) V(22)}
options format=6

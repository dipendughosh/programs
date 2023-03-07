wave 999 0 sin  label=vdcoff freq=1K amp=.01 damp=0.0 offset=0.5155m delay=100u 
options reltol=0.0001
transient 10m 5u
plot { v(999) v(24)}

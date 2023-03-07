wave 301 0 sin  label=VVIN freq=2000 amp=5 damp=0 offset=0 delay=1e-05 

options abstol=5e-10 reltol=1e-07 chargetol=5e-15 format=4
plot { v(301) v(302) v(304) v(305)}
transient 1m 1e-06

wave 20 0 bit  {10} label=VAP rt=1E-9 ft=1E-9 ht=2.4e-08 lt=2.6e-08 on=0.0 off=3.0 delay=-2.4e-08 pw=50E-9
transient 100n .1n

plot { v(20) v(2)}

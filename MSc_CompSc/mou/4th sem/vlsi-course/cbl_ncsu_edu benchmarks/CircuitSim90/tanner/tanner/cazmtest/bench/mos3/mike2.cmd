wave 2 0 bit  {10} label=vpulse rt=1n ft=1n ht=1.1e-08 lt=1.1e-08 on=0 off=5.5 delay=-1e-08 pw=22n
transient 20n .05n
plot { v(2) i(vpulse)}
vrange mos 5.5


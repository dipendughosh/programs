wave 1 0 sin  label=vin freq=33e6 amp=1v offset=1v 
wave 14 0 bit  {10} label=vnr rt=1ns ft=1ns ht=8.999e-06 lt=1.001e-06 on=0v off=10v delay=-8.989e-06 pw=10us
transient 600ns 2ns
plot { v(8) v(12) v(15) v(21) v(23) v(30)}
ic {8=9.93}
dcoppt
vrange mos 10


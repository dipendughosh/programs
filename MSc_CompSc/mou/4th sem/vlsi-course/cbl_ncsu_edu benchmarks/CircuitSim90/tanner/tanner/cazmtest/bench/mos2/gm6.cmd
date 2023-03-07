wave 5 0 bit  {10} label=vin rt=5ns ft=5ns ht=5e-08 lt=5e-08 on=0 off=5 delay=-4.9e-08 pw=100ns

temp 125
dcoppt
transient 100ns .5ns
plot { v(2) v(5) v(7)}
plot { v(10) v(11) v(12) v(13)}
vrange mos 7.0

wave 1 0 bit  {10} label=vin rt=2n ft=2n ht=2.8e-08 lt=2.2e-08 on=0 off=5 delay=-2.3e-08 pw=50n

dcoppt
transient 50ns .5ns
plot { v(30) v(40) v(50) v(60)}

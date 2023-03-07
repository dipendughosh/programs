wave 2 0 bit  {10} label=vp rt=1ns ft=1ns ht=6.9e-08 lt=3.1e-08 on=0 off=10 delay=-5.9e-08 pw=100ns

transient 200ns 1ns
plot { v(2) v(3) v(4)}
vrange mos 10

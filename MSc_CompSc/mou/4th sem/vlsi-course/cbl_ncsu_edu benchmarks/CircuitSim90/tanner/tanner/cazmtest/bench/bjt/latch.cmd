wave 1 0 bit  {10} label=vrset rt=1ns ft=1ns ht=2.9e-08 lt=1.1e-08 on=0v off=3v delay=-2.8e-08 pw=40ns
wave 7 0 bit  {10} label=vset rt=1ns ft=1ns ht=2.9e-08 lt=1.1e-08 on=0v off=3v delay=-9e-09 pw=40ns
transient 75ns 1ns
plot { v(1) v(7) v(5) v(2)}


wave 1 0 bit  {10} label=VIN rt=400ns ft=400ns ht=5e-07 lt=5e-07 on=-1.6 off=-1.2 delay=-4.9e-07 pw=1000ns
plot { v(1) v(3) v(5) v(6)}
transient 1000ns 10ns
options format=6

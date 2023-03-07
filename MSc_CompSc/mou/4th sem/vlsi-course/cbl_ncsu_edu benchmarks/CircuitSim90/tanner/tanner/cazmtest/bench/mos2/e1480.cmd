wave 2 0 bit  {10} label=vin rt=40ns ft=40ns ht=6.5e-08 lt=1.25e-07 on=0 off=10 delay=-4e-08 pw=190ns
wave 9 0 bit  {10} label=vrt rt=10ns ft=10ns ht=9.9e-07 lt=1.01e-06 on=10 off=0 delay=-9.8e-07 pw=2us

transient 200ns 2ns
plot { v(8) v(2)}
vrange mos 10

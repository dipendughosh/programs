wave 72 0 bit  {10} label=vres rt=5ns ft=5ns ht=9.5e-08 lt=1.05e-07 on=0 off=5 delay=-9.5e-08 pw=200ns
wave 93 0 bit  {10} label=vclk rt=5ns ft=5ns ht=5e-09 lt=1.5e-08 on=0 off=5 delay=-5e-09 pw=20ns
temp 25.0
plot { v(0) v(93) v(72) v(82) v(80) v(79)}
transient 1.0e-7 0.5e-9
vrange mos 10


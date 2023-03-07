wave 3 6 bit  {10} label=vin rt=20ns ft=20ns ht=1.3e-07 lt=7e-08 on=0  off=10  delay=-1.2e-07 pw=200ns
transient 200ns 2ns
options abstol=10n
plot { v(3) v(4) v(5) v(7) v(8)}
plot { v(9) v(10) v(11)}
vrange mos 10

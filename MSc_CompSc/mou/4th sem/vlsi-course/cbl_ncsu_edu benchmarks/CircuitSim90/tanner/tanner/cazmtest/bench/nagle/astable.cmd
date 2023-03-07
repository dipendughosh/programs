wave 5 0 bit  {10} label=vin rt=1us ft=1us ht=-1e-06 lt=0.000101 on=0 off=5 delay=1e-06 pw=100us
transient 10us 0.1us
plot { v(5) v(1) v(2) v(3) v(4)}


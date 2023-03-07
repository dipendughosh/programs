wave 1 0 bit  {10} label=VIN rt=0.1MS ft=0.0001 ht=-0.0001 lt=0.0101 on=0 off=1 delay=0.0002 pw=0.01
transient 10MS 0.1MS
plot { V(1) V(2) V(3)}

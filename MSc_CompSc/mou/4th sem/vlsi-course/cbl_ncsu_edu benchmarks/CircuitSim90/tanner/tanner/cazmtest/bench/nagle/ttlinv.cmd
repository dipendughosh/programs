wave 1 0 bit  {10} label=VIN rt=1NS ft=1NS ht=5.9e-08 lt=4.1e-08 on=0 off=3.5 delay=-5.8e-08 pw=1e-07
transient 100NS 1NS
plot { V(1) V(5) V(9)}

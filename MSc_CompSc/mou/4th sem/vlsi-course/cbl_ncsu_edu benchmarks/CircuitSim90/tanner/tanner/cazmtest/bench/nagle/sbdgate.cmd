wave 1 0 bit  {10} label=VIN rt=2NS ft=2NS ht=1.48e-07 lt=5.2e-08 on=0.2 off=3.6 delay=-1.46e-07 pw=2e-07
transient 200NS 1NS
plot { V(1) V(15) I(VCC)}

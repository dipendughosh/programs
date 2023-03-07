wave 1 0 bit  {10} label=VIN rt=0.2NS ft=0.2NS ht=9.8e-09 lt=1.02e-08 on=-0.8 off=-1.8 delay=-9.6e-09 pw=2e-08
transient 20NS 0.1NS
plot { V(1) V(12) V(21)}

wave 16 0 bit  {10} label=VIN rt=1NS ft=1NS ht=-1e-09 lt=2.1e-08 on=-1.8 off=-0.8 delay=2e-09 pw=2e-08
wave 17 0 bit  {10} label=VGATE rt=1NS ft=1NS ht=1.4e-08 lt=6e-09 on=-0.8 off=-1.8 delay=-9e-09 pw=2e-08
transient 20NS 0.1NS
plot { V(16) V(17) V(6) V(14)}

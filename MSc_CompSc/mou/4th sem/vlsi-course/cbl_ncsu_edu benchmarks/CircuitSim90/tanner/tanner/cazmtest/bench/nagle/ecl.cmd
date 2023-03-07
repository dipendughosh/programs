wave 1 0 bit  {10} label=VIN rt=1NS ft=8NS ht=-1.1e-08 lt=2.1e-08 on=-1.0 off=-1.8 delay=1.2e-08 pw=1e-08
options abstol=1E-12 reltol=1E-5
transient 10NS 0.2NS
plot { V(1) V(3) V(5) V(7) I(VIN)}

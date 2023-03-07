wave 1 0 bit  {10} label=VIN rt=1NS ft=8NS ht=2.9e-08 lt=2.1e-08 on=4.0 off=3.2 delay=-2.8e-08 pw=5e-08
options abstol=1E-12 reltol=1E-5
transient 50NS 0.25NS
plot { V(1) I(VIN) V(3) V(5)}

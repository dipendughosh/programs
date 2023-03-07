wave 13 0 bit  {10} label=VPOS rt=10NS ft=10NS ht=1e-06 lt=1e-06 on=-10.0E-5 off=10.0E-5 delay=-1e-06 pw=2000NS
wave 19 0 bit  {10} label=VNEG rt=10NS ft=10NS ht=1e-06 lt=1e-06 on=10.0E-5 off=-10.0E-5 delay=-1e-06 pw=2000NS
wave 14 0 bit  {10} label=Vphi1 rt=10NS ft=10NS ht=2.6e-07 lt=7.4e-07 on=5.0 off=0.0 delay=-1e-08 pw=1000NS
wave 18 0 bit  {10} label=Vphi2 rt=10NS ft=10NS ht=2.8e-07 lt=7.2e-07 on=0.0 off=5.0 delay=-2e-08 pw=1000NS
wave 26 0 bit  {10} label=Vphi3 rt=10NS ft=10NS ht=6.9e-07 lt=3.1e-07 on=0.0 off=5.0 delay=-2e-08 pw=1000NS
wave 16 0 bit  {10} label=Vphi1b rt=10NS ft=10NS ht=2.6e-07 lt=7.4e-07 on=0.0 off=5.0 delay=-1e-08 pw=1000NS
wave 20 0 bit  {10} label=Vphi2b rt=10NS ft=10NS ht=2.8e-07 lt=7.2e-07 on=5.0 off=0.0 delay=-2e-08 pw=1000NS
wave 8 0 bit  {10} label=Vphi3b rt=10NS ft=10NS ht=6.9e-07 lt=3.1e-07 on=5.0 off=0.0 delay=-2e-08 pw=1000NS
transient 2000NS 10NS
plot { V(24,6) V(26) V(13,19)}
plot { V(24) V(6) V(26) V(13) V(19)}

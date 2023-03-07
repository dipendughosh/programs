*volt 1 gnd 0.0 label=v1
*transfer { v1 0 10 0.1}
wave 1 bit {01} on=5 off=0 rt=2p ft=2p lt=0.2n ht=0.2n
transient 0.5n
*plot {vtx(1) itx(v1)}
plot {v(1) v(2) v(3)}

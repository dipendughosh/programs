*O3S
*
* Spice node 2 corresponds to sim node a.
* Spice node 5 corresponds to sim node b.
* Spice node 7 corresponds to sim node c.
* Spice node 8 corresponds to sim node q.
*
volt 0 gnd 0
volt 1 gnd 2.7 
wave 2 bit {2(1) 2(0)}  on=2.7 rt=2n ft=2n pw=5n off=0.0
wave 5 bit {4(0) 4(1)}  on=2.7 rt=2n ft=2n pw=5n off=0.0
wave 7 bit {8(0) 8(1)}  on=2.7 rt=2n ft=2n pw=5n off=0.0

temp 70
transient 160n
plot {v(2) v(5) v(7) v(8)}

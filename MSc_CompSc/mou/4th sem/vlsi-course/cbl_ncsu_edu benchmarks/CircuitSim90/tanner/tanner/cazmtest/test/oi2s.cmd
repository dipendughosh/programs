*OI2S
*
* Spice node 2 corresponds to sim node a.
* Spice node 4 corresponds to sim node b.
* Spice node 5 corresponds to sim node q.
*
volt 1 gnd 2.7
wave 2 bit {4(0) 4(1)} on=2.7 rt=2n ft=2n pw=5n off=0.0
wave 4 bit {8(0) 8(1)} on=2.7 rt=2n ft=2n pw=5n off=0.0

temp 70
transient 100n
plot {v(2) v(4) v(5)}

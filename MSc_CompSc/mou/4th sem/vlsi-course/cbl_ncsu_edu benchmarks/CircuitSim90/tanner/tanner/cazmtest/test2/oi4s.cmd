*OI4S
*
* Spice node 2 corresponds to sim node a.
* Spice node 4 corresponds to sim node b.
* Spice node 6 corresponds to sim node c.
* Spice node 8 corresponds to sim node d.
* Spice node 9 corresponds to sim node q.
*
volt 0 gnd 0
volt 1 gnd 2.7
wave 2 bit { 2(0)  2(1)} on=2.7 rt=2n ft=2n pw=5n off=0.0
wave 4 bit { 4(0)  4(1)} on=2.7 rt=2n ft=2n pw=5n off=0.0
wave 6 bit { 8(0)  8(1)} on=2.7 rt=2n ft=2n pw=5n off=0.0
wave 8 bit {16(0) 16(1)} on=2.7 rt=2n ft=2n pw=5n off=0.0

temp 70
transient 320n
plot {v(2) v(4) v(6) v(8) v(9)}

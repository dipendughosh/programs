*AOI33S
*
* Spice node 2 corresponds to sim node a1.
* Spice node 4 corresponds to sim node a2.
* Spice node 5 corresponds to sim node a3.
* Spice node 6 corresponds to sim node b1.
* Spice node 8 corresponds to sim node b2.
* Spice node 9 corresponds to sim node b3.
* Spice node 7 corresponds to sim node q.
*
volt  0 gnd 0
volt  Vdd gnd 2.7
wave  2 bit {88(0) 2(1)} on=2.7 rt=2n ft=2n pw=5n off=0.0
wave  4 bit {88(0) 4(1)} on=2.7 rt=2n ft=2n pw=5n off=0.0
wave  5 bit {88(0) 8(1)} on=2.7 rt=2n ft=2n pw=5n off=0.0
wave  6 bit {2(0) 2(1)} on=2.7 rt=2n ft=2n pw=5n off=0.0
wave  8 bit {4(0) 4(1)} on=2.7 rt=2n ft=2n pw=5n off=0.0
wave  9 bit {8(0) 8(1)} on=2.7 rt=2n ft=2n pw=5n off=0.0

temp 70
transient 100n
*plot {v(2) v(4) v(5) v(6) v(8) v(9) v(7)}
plot {v(6) v(8) v(9) v(7)}

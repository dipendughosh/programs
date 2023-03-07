* WDD
* Spice node 9 corresponds to sim node data_in.
* Spice node 11 corresponds to sim node scan_in.
* Spice node 10 corresponds to sim node t1.
* Spice node 8 corresponds to sim node ck1.
* Spice node 7 corresponds to sim node ck2.
* Spice node 6 corresponds to sim node q.
*
volt 1 gnd 2.7 
volt 12 0
*
* wave data_in
wave  9 bit {8(0) 8(1)}  on=2.7 rt=2n ft=2n pw=5n off=0.0
* wave scan_in
wave 11 bit {8(1) 8(0)}  on=2.7 rt=2n ft=2n pw=5n off=0.0
* wave t1
wave 10 bit {4(1) 4(0)}  on=2.7 rt=2n ft=2n pw=5n off=0.0
* wave ck1
wave  8 bit {4(0) 4(1)}  on=2.7 rt=2n ft=2n pw=5n off=0.0
* wave ck2
wave  7 bit {4(0) 4(1)}  on=2.7 rt=2n ft=2n pw=4n off=0.0
*
temp 70
transient 80n
*plot  t1   ck1  ck2  q
plot {v(9) v(11) v(10) v(8) v(7) v(6)}

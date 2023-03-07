*DS2IS
*
* Spice node 4 corresponds to sim node D.
* Spice node 6 corresponds to sim node DS.
* Spice node 2 corresponds to sim node cs.
* Spice node 5 corresponds to sim node csb.
* Spice node 14 corresponds to sim node ck1.
* Spice node 7 corresponds to sim node ck1b.
* Spice node 15 corresponds to sim node ck2.
* Spice node 10 corresponds to sim node ck2b.
* Spice node 12 corresponds to sim node q.
* Spice node 13 corresponds to sim node qb.
*
volt 0 gnd 0
volt 1 gnd 2.7 
volt 16 0
volt 17 0
volt 18 0
volt 19 0
volt 20 0
* wave d
wave  4 bit {2(0) 2(1)}  on=2.7 rt=2n ft=2n pw=5n off=0.0
* wave ds
wave  6 bit {2(1) 2(0)}  on=2.7 rt=2n ft=2n pw=5n off=0.0
* wave cs
wave  2 bit {4(0) 4(1)}  on=2.7 rt=2n ft=2n pw=5n off=0.0
* wave csb
wave  5 bit {4(1) 4(0)}  on=2.7 rt=2n ft=2n pw=5n off=0.0
* wave ck1
wave 14 bit {4(0) 4(1)}  on=2.7 rt=2n ft=2n pw=5n off=0.0
* wave ck1b
wave  7 bit {4(1) 4(0)}  on=2.7 rt=2n ft=2n pw=5n off=0.0
* wave ck2
wave 15 bit {4(0) 4(1)}  on=2.7 rt=2n ft=2n pw=4n off=0.0
* wave ck2b
wave 10 bit {4(1) 4(0)}  on=2.7 rt=2n ft=2n pw=4n off=0.0

temp 70
transient 80n
*plot d    ds   cs   csb  ck1   ck1b ck2   ck2b  q
plot {v(4) v(6) v(2) v(5) v(14) v(7) v(15) v(10) v(12)}

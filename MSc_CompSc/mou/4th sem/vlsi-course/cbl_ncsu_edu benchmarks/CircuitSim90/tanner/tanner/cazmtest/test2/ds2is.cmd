*DS2IS
*
* Spice node  4 corresponds to sim node d.
* Spice node  2 corresponds to sim node cs.
* Spice node 14 corresponds to sim node ds.
* Spice node  5 corresponds to sim node csb.
* Spice node 15 corresponds to sim node ck1.
* Spice node  7 corresponds to sim node ck1b.
* Spice node 16 corresponds to sim node ck2.
* Spice node 10 corresponds to sim node ck2b.
* Spice node 12 corresponds to sim node q.
* Spice node 13 corresponds to sim node qb.
*
volt 0 gnd 0
volt 1 gnd 2.7 
*cl d    80n 10
wave  4 bit {8(0) 8(1)}  on=2.7 rt=2n ft=2n pw=5n off=0.0
*cl ck   40n 0101
wave 15 bit {2(0) 2(1)}  on=2.7 rt=2n ft=2n pw=5n off=0.0
*cl ckb  40n 1010
wave  7 bit {2(1) 2(0)}  on=2.7 rt=2n ft=2n pw=5n off=0.0
*cl cs   80m 01
wave  2 bit {100(0) 2(1)}  on=2.7 rt=2n ft=2n pw=5n off=0.0
*cl csb  80m 10
wave  5 bit {100(1) 2(0)}  on=2.7 rt=2n ft=2n pw=5n off=0.0

temp 70
transient 80n
plot {v(4) v(15) v(7) v(2) v(5) v(12) v(13)}

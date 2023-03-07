*PFT2S
* Spice node 7 corresponds to sim node d.
* Spice node 9 corresponds to sim node ck1.
* Spice node 6 corresponds to sim node ck1b.
* Spice node 8 corresponds to sim node ck2.
* Spice node 5 corresponds to sim node ck2b.
* Spice node 4 corresponds to sim node q.

volt 0 gnd 0
volt 1 gnd 2.7 

*Vd    19 0  Pulse (5 0 40n 2n 2n 80n 160n)
wave 13 bit {8(1) 8(0)}  on=2.7 rt=2n ft=2n pw=10n off=0.0
*Vck1  16 0  Pulse (0 5 20n 2n 2n 40n 80n)
wave 19 bit {4(0) 4(1)}  on=2.7 rt=2n ft=2n pw=10n off=0.0
*Vck2  15 0  Pulse (5 0 20n 2n 2n 40n 80n)
wave 16 bit {4(1) 4(0)}  on=2.7 rt=2n ft=2n pw=10n off=0.0
*ck3
wave 14 bit {4(1) 4(0)}  on=2.7 rt=2n ft=2n pw=10n off=0.0
*Vckb1 18 0  Pulse (5 0 20n 2n 2n 40n 80n)
wave 12 bit {4(1) 4(0)}  on=2.7 rt=2n ft=2n pw=10n off=0.0
*Vckb2 17 0  Pulse (0 5 20n 2n 2n 40n 80n)
wave  9 bit {4(0) 4(1)}  on=2.7 rt=2n ft=2n pw=10n off=0.0
*ckb3
wave  4 bit {4(0) 4(1)}  on=2.7 rt=2n ft=2n pw=10n off=0.0

temp 70
transient 80n
plot {v(7) v(9) v(8) v(6) v(5) v(4) v(3)}
* Spice node 13 corresponds to sim node d.
* Spice node 11 corresponds to sim node ds.
* Spice node 18 corresponds to sim node cs.
* Spice node 10 corresponds to sim node csb.
* Spice node 19 corresponds to sim node ck1.
* Spice node 12 corresponds to sim node ck1b.
* Spice node 16 corresponds to sim node ck2.
* Spice node 9 corresponds to sim node ck2b.
* Spice node 4 corresponds to sim node ck3b.
* Spice node 14 corresponds to sim node ck3.
* Spice node 3 corresponds to sim node q.

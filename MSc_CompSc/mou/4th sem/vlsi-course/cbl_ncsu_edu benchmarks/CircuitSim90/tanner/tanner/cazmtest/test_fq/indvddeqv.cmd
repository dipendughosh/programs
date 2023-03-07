wave n1 pie {0 5 100n 5 101n 0 1000n 0} label=VIN
ic {ind=3.0}
*
*	Truncation error, when:
*
*	ic {ind=2.0}
*		^
*		|

vc ind Vdd n2 GND 1 label=VV1
vc n2 GND ind Vdd -1 label=VV2

plot { i(VIN,GND) i(VV1,ind) i(rone,n1) i(cone,n2) }
transient 1000ns powerup

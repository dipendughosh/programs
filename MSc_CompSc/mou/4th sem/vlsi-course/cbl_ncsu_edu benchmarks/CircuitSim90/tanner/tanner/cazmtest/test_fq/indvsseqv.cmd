*
* Voltage controlled current sources for modeling inductors  
*

wave n1 GND pie {0 0 100n 0 101n 5 1000n 5} label=VIN

vc ind GND n2 GND 1 label=VC1
vc n2 GND ind GND -1 label=VC2

plot { i(VIN,GND) i(r1,n1) i(VC1,ind) i(c1,n2) }
transient 1000ns powerup


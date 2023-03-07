*gridsize mos 30 60 
*gridsize mos 30 60 4
volt vdd vss 5.0
wave gate sin amp=0.5 freq=50000000 offset=1.5 delay=20.0n
plot { gate n1 n2 i(Rd,vdd) i(Rs,GND)
 gate i(m1,n2) i(m1,n1) i(m1,gate) i(m1,GND)
 q(m1,n2) q(m1,n1), q(m1,gate) q(m1,GND)}
transient 200n .1n

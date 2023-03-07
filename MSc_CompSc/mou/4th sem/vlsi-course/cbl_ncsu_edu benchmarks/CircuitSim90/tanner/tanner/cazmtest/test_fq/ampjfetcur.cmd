
volt vdd vss 5.0
wave gate sin amp=0.5 freq=50000000 offset=0.0 delay=20.0n
plot {gate n1 n2 i(Rs,GND)
i(J1,n2), i(J1,n1), i(J1,gate) 
q(J1,n2), q(J1,n1), q(J1,gate)
} 
transient 200n .1n powerup  


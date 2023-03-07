
volt vcc GND 5.0
wave vin1 sin amp=0.2 freq=50000000 offset=.8 delay=20.0n label=W1

plot {vin1 base1 coll22
i(W1,vin1) i(Q1,base1) i(Q1,coll22) 
q(Q1,base1) q(Q1,coll22)  
}
transient 200n .2n 


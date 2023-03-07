volt vdd gnd 3.0 

volt carryin gnd 0
volt x1 gnd 0
volt x2 gnd 0
volt x3 gnd 0
volt x4 gnd 0
volt x5 gnd 0
volt x6 gnd 0
volt x7 gnd 0
volt y0 gnd 3.0
volt y1 gnd 3.0
volt y2 gnd 3.0
volt y3 gnd 3.0
volt y4 gnd 3.0
volt y5 gnd 3.0
volt y6 gnd 3.0
volt y7 gnd 3.0

*wave vin piec { 0,1.0 2n,}
wave x0 bit {0 0 1 1} rt=1.0n pw=5n on=3.0 off=0.0

temp 70
transient 20n
plot {carryout carry1 a b c d x0}


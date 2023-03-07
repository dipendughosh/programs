*D1
*
volt GND 0
volt Vdd GND 5.0

wave ck bit { 5(0)  5(1)}  on=5.0 rt=2n ft=2n pw=5n off=0.0
wave d  bit {10(1) 10(0)}  on=5.0 rt=2n ft=2n pw=5n off=0.0

temp 75
transient 120n 0.1ns {i1 0}
plot {d i1 qb q}

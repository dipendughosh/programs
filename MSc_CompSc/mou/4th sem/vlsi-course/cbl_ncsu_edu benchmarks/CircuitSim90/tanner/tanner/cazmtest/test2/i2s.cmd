*I2S
*
* Spice node 2 corresponds to sim node a.
* Spice node 3 corresponds to sim node q.
*
volt 0 gnd 0
volt 1 gnd 2.7 
wave 2 bit {1 4(1) 4(0)}  on=2.7 rt=2n ft=2n pw=5n off=0.0

temp 70
transient 100n
plot {v(2) v(3)}

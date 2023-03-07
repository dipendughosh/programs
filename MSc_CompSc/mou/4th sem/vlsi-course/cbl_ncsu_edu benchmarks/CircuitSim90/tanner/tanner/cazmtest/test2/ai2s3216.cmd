*
*
* CLOCK COMMANDS
*va    2  0  Pulse (2.7 0 5n  2n 2n 80n 160n)
*vb    4  0  Pulse (2.7 0 10m 2n 2n 80m 160m)
*vdd   1  0  2.7 
volt 1 gnd 2.7
wave 2 bit {1 16(0) 16(1)} on=2.7 rt=2n ft=2n pw=5n off=0.0
volt 4 gnd 2.7v

temp 70
transient 160n
plot {v(2) v(3)}

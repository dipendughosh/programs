*aoi2211s
*
*
volt GND 0
volt Vdd GND 5.0
wave a1 bit {10(1) 10(0)} on=5.0 rt=0.5n ft=0.5n pw=10.0n off=0.0
wave a2 bit {10(1) 10(1)} on=5.0 rt=0.5n ft=0.5n pw=10.0n off=0.0
wave b1 bit {10(0) 10(0)} on=5.0 rt=0.5n ft=0.5n pw=10.0n off=0.0
wave b2 bit {10(0) 10(0)} on=5.0 rt=0.5n ft=0.5n pw=10.0n off=0.0
wave c bit {10(0) 10(0)} on=5.0 rt=0.5n ft=0.5n pw=10.0n off=0.0
wave d bit {10(0) 10(0)} on=5.0 rt=0.5n ft=0.5n pw=10.0n off=0.0

temp 25
transient 300.0ns 0.1ns
plot { a1 q }

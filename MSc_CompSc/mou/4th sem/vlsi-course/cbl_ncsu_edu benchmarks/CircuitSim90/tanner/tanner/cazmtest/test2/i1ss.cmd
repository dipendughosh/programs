volt GND 0
volt Vdd GND 5.0
wave a bit {10(1) 10(0)}  rt=.5n ft=.5n  pw=10.0n on=5.0 off=0.0

temp 75
transient 300n .1n 
plot {a q}

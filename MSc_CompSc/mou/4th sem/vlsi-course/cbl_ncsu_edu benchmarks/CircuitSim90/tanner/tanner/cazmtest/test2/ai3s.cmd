*AI3S
*
volt Vdd GND 5.5
wave a bit {10(0) 10(1)} on=5.5 rt=2n ft=2n pw=10n off=0.0
wave b bit {80(1) 80(0)} on=5.5 rt=2n ft=2n pw=10n off=0.0
wave c bit {80(1) 80(0)} on=5.5 rt=2n ft=2n pw=10n off=0.0

temp 0
transient 300ns 0.1ns
plot {v(a) v(q)}

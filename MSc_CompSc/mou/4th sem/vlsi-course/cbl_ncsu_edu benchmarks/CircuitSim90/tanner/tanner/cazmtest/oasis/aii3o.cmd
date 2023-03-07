volt Vdd GND 5.5
temp 0

wave a bit {1011111} on=5.5 rt=0.5n ft=0.5n pw=50.0n off=0.0
wave b bit {1110111} on=5.5 rt=0.5n ft=0.5n pw=50.0n off=0.0
wave c bit {1111101} on=5.5 rt=0.5n ft=0.5n pw=50.0n off=0.0

transient 350.0ns
plot 0.5.aii3o.plot { a b c q6 qbar6 }
plot 0.3.aii3o.plot { a b c q5 qbar5 }
plot 0.2.aii3o.plot { a b c q4 qbar4 }
plot 0.15.aii3o.plot { a b c q3 qbar3 }
plot 0.1.aii3o.plot { a b c q2 qbar2 }
plot 0.05.aii3o.plot { a b c q1 qbar1 }

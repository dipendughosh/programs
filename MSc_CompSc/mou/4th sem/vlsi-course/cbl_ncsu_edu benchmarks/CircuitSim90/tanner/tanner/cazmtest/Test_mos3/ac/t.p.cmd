
volt Vdd GND 5.5
volt Vdrain GND 0
volt gate GND 0

transfer {Vdrain 0 5.5 }
plot { v(Vdrain) i(Vdd,Vdrain) }

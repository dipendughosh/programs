volt Vdd GND 5.0
volt Vgate GND 5.5

transfer {Vdd 0 5.5 Vgate 1.0 5.5 0.5 }

plot { v(Vdd) i(Vdd,GND)}


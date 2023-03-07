
vv in GND controll GND 5 label=VIN
wave controll pie { 0 0 100n 5 }
plot { i(VIN,GND) i(VIN,in) i(Rseries,in) i(Rseries,gate) }
transient 100n .1n powerup




vv in new controll GND 5 label=VIN
wave controll GND pie { 0 0 100n 5 } 
plot { i(VIN,new) i(VIN,in) i(Rseries,in) i(C1,gate) }
transient 100n .1n powerup



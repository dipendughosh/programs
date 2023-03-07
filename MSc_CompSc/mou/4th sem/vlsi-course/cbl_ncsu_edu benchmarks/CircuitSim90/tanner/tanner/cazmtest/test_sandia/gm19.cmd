vrange mos 10
gridsize mos 12 20 6
wave 14 0 pie { 0 0v 10e-9 0v 1.1e-08 10v 1.011e-06 10v 1.012e-06 0v 10e-6 0v }
*vin 1 0 sin(1v 1v 33e6)
wave 1 sin offset=1v amp=1v freq=33e6
transient 600ns
*.tran 4ns 600ns
plot { v(119) v(120) }

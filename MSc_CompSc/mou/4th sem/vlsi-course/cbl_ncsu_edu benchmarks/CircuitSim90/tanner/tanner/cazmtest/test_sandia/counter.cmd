wave 72 0 pie { 0 0 5e-09 5 1.05e-07 5 1.1e-07 0 200e-9 0 }
wave 93 0 pie { 0 0 5e-09 5 1.5e-08 5 2e-08 0 }
vrange mos 10
transient 1e-7
plot { v(0) v(93) v(72) v(82) v(80) v(79) }

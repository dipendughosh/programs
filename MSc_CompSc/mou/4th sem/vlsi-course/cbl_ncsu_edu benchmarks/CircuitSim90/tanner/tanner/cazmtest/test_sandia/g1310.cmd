wave 3 6 pie { 0 0v 10e-9 0v 3e-08 10v 8e-08 10v 1e-07 0v 200e-9 0v }
*.tran 2ns 200ns
transient 200ns
vrange mos 10
*.print tran v(3) v(4) v(5) v(7) v(8) i(vdd) i(vss) i(vin)
plot { v(3) v(4) v(5) v(7) v(8) }
plot { v(9) v(10) v(11) }

wave 10 0 pie { 0e-9 0 1e-09 5 2.01e-07 5 2.02e-07 0 203e-9 0 }
wave 2 0 pie { 0 0 9e-9 0 1.1e-08 5 2.9e-08 5 3.1e-08 0 50e-9 0 }
wave 3 0 pie { 0 0 29e-9 0 3.1e-08 5 4.9e-08 5 5.1e-08 0 60e-9 0 }
wave 4 0 pie { 0 0 29e-9 0 3.1e-08 5 4.9e-08 5 5.1e-08 0 60e-9 0 }
wave 18 0 pie { 0 0 49e-9 0 5.1e-08 5 1.79e-07 5 1.81e-07 0 200e-9 0 }
*.tran 1n 120n
transient 120n
*plot { v(2) v(3) v(4) v(6) v(7) i(vdd) }
*plot { v(2) v(3) v(4) v(6) v(7) }
plot { v(8) v(13) v(14) v(17)}
plot { v(21) v(22) }

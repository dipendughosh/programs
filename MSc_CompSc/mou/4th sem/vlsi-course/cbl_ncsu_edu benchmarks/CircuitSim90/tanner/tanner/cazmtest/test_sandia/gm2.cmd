wave 2 0 pie { 0 0 10e-9 0 1.1e-08 10 4.1e-08 10 4.2e-08 0 100e-9 0 }
*.tran 1ns 200ns
transient 200ns
plot { v(2) v(3) v(4) }

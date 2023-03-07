wave 1 0 pie { 0 0 10e-9 0 5e-08 5 1.6e-07 5 2e-07 0 300e-9 0 }
*.tran 2ns 300ns
transient 300ns
plot { v(1) v(11) v(14) }

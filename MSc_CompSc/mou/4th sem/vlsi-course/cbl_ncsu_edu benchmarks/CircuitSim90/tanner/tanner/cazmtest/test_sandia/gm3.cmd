wave 1 0 pie { 0 0 5e-9 0 7e-09 5 2.7e-08 5 2.9e-08 0 50e-9 0 }
*.tran .5ns 50ns
transient 50ns
plot { v(30) v(40) v(50) v(60) }

wave 3 0 pie { 0 0 40e-9 0 4.1e-08 5 7.9e-08 5 8e-08 0 200e-9 0 }
wave 41 0 pie { 0 0 5e-9 0 6e-09 5 4.4e-08 5 4.5e-08 0 85e-9 0 }
wave 9 0 pie { 0 0 65e-9 0 6.6e-08 5 8.4e-08 5 8.5e-08 0 200e-9 0 }
wave 1 0 pie { 0 5 120e-9 5 1.21e-07 0 1.51e-07 0 1.52e-07 5 200e-9 5 }
*.tran 1n 16n uic
transient 16ns
plot { v(2) v(4) v(5) v(16) v(17) }

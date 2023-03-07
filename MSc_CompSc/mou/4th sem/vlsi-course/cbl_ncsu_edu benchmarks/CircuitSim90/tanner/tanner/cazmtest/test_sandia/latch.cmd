wave 1 0 pie { 0 0v 1e-9 0v 2e-09 3v 1.2e-08 3v 1.3e-08 0v 40e-9 0v }
wave 7 0 pie { 0 0v 20e-9 0v 2.1e-08 3v 3.1e-08 3v 3.2e-08 0v 40e-9 0v }
transient 75ns
plot { v(1) v(7) v(5) v(2) }

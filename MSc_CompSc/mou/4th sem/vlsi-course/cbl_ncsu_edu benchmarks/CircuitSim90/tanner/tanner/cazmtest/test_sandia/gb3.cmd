wave 8 0 pie { 0 4.2v 1e-9 4.2v 2e-09 3.7v 4.7e-08 3.7v 4.8e-08 4.2v 100e-9 4.2v }
wave 9 0 pie { 0 4.2v 1e-9 4.2v 2e-09 3.7v 4.7e-08 3.7v 4.8e-08 4.2v 100e-9 4.2v }
wave 18 0 pie { 0 3.7v 2e-9 3.7v 4e-09 4.2v 7e-09 4.2v 9e-09 3.7v 10e-9 3.7v }
wave 15 0 pie { 0 4.2v 2e-9 4.2v 4e-09 3.7v 7e-09 3.7v 9e-09 4.2v 10e-9 4.2v }
wave 24 0 pie { 0 2.9v 0.5e-9 2.9v 1e-09 3.4v 1.5e-09 3.4v 2e-09 2.9v 100e-9 2.9v }
*.tran 0.5ns 70ns
transient 70ns
plot { v(8) v(18) v(12) v(20) v(2) v(18) v(3) v(19) v(25) v(28) }
*.plot tran v(8) v(18) v(3) v(12) v(20) v(2)

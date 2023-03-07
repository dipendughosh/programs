wave 11 0 pie  { 0.0ns 5.0v 30.0ns 5.0 30.1ns 0.0 40.0ns 0.0 40.1ns 5.0 50ns 5.0 
 } label=VSEU
wave 12 0 pie  { 0.0ns 0.0v 10.0ns 0.0 10.1ns 5.0 20.0ns 5.0 20.1ns 0.0 50ns 0.0 
 } label=VSEU2
transient 50ns 0.1ns
plot { v(11) v(12) v(3) v(4) v(5)}


*  Xmission line test
wave 1 pie{0ns 0 0.1ns 100 10ns 100}
*wave 1 pie{0ns 0 1.0ns 100 10ns 100}
*wave 1 pie{0ns 0 5ns 0 5.1ns 100 10ns 100}
plot {2 3 4 i(rs,2) i(t1,2)}
*options reltol=1.0e-3
transient 200ns 


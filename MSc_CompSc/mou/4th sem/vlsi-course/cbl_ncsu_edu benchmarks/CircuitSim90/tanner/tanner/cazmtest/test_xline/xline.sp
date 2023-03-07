*  Xmission line test
*vs 1 0 pwl{0ns 0 0.1ns 100 10ns 100}
vs 1 0 pwl(0ns 0 5ns 0 5.1ns 100 10ns 100)
rs 1 2 300
rload 3 0 50
t1 2 0 3 0 z0=100 td=10ns
.tran 0.1ns 200ns
.print tran v(2) v(3)
.options limpts=10000 
.end


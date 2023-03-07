
.model pn d cjo=1.0e-12 is=1.0e-12 tt=0 n=1 m=0.33 vj=0.01 bv=20 ibv=1.0e-5
t0 1 0 2 0 z0=50 td=1.0e-9
*diode 2 0 pn


vsin 1 0 sin(0 1 5.0e8 0.0 0.0)
.tran 0.1ns 10ns
.print tran v(1) v(2)
.options limpts=18000 
.end


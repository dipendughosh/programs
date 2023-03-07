*  Xmission line test
rs 1 2 100
t1 2 0 3 0 z0=50 td=10ns
rload 3 0 100

Vs 1 0 3.0 AC 1.5 0.0
.ac DEC 5 10K 1000MEG
.print ac vr(3) vi(3) ir(Vs) ii(Vs)
.options limpts=10000 gmin=1.0e-16 
.end


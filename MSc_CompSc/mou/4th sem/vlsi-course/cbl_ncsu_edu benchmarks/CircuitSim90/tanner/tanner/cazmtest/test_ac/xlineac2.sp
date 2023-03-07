*  Xmission line test
rs 1 2 100
cload 4 0 1p
rload 4 0 25
t1 2 0 3 0 z0=50 td=10ns
t2 3 0 4 0 z0=25 td=5ns
t3 3 0 5 0 z0=25 td=5ns

Vs 1 0 3.0 AC 1.5 0.0
.ac DEC 5 10K 1000MEG
.print ac vr(3) vi(3) ir(Vs) ii(Vs) vr(4) vi(4) vr(5) vi(5)
.options limpts=10000 gmin=1.0e-16 
.end


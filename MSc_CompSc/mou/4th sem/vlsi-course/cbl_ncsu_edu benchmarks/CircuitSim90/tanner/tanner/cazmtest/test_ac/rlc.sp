
r1 1 2 10k
c1 2 3 2p
r2 3 0 10k
c2 3 4 2p
v1 4 5 0 
l1 5 0 2m

VIN 1 0 2.5 AC 2.0 0.0
.ac dec 1 1MEG 1MEG
.print ac vm(1) vp(1) vm(2) vm(3) vm(4) ir(v1)
.options limpts=10000
.end



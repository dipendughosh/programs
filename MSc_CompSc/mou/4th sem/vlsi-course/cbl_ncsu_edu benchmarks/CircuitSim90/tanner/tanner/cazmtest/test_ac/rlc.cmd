

volt 1 0 0.0 acmag= 2.0 acphase= 0.0 label=VIN
ac dec 1 1MEG 1MEG
plot {vm(1) vp(1) vm(2) vm(3) vm(4) ir(l1,4)}


*r1 1 2 10k
*c1 2 3 2p
*r2 2 0 10k
*c2 3 4 2p
*l1 4 0 2m

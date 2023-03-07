
wave 1 2 sin amp=0.0 freq=10MEG label=VIN
plot {i(ICIN,0) i(VIN,1) i(R2,2) i(VNOW,3) i(VNOW) i(R4,4) v(2) v(3) }
plot {idc(ICIN,0) idc(VIN,1) idc(R2,2) idc(VNOW,3) idc(VNOW) idc(R4,4)
vdc(2) vdc(3) }
dcoppt
transient 2n .2n 



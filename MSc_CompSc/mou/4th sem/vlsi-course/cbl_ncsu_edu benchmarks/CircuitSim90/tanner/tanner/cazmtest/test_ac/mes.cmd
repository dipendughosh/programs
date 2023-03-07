*
*
volt vdd gnd 5.0
volt s1 gnd 0.0
volt g1 gnd -2.5 acmag=2
plot { vdc(g1,gnd) vdc(d1,gnd) }
plot { idc(z1, d1) }
plot { vm(g1, gnd) vm(d1, gnd) }
dcoppt
ac dec 1 1K 100MEG
options format=5

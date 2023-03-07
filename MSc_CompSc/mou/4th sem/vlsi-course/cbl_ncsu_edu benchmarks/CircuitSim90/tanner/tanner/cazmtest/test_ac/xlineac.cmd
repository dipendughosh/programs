*  Xmission line test
volt 1 0 3 acmag=1.5 label=Vs
plot {vr(3) vi(3) ir(Vs) ii(Vs) vdc(2) vdc(3) idc(rs,2) }
dcoppt
ac DEC 5 10K 100000MEG 


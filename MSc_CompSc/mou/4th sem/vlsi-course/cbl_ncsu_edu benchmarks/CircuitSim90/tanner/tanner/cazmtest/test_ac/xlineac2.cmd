*  Xmission line test
volt 1 0 3 acmag=1.5 label=Vs
plot {vr(3) vi(3) ir(Vs) ii(Vs) vdc(2) vdc(3) idc(rs,2) vr(4) vi(4) vr(5) vi(5)}
dcoppt
ac DEC 5 10K 1000MEG 


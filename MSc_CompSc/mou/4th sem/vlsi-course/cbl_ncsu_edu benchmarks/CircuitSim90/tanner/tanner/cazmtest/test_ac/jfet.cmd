
volt vdd vss 5.0
volt vin gnd 0.5 acmag= 1.0 acphase= 0.0
plot {ir(J1,d1) ii(J1,d1) ir(J1,g1) ii(J1,g1) ir(J1,s1) ii(J1,s1) }
plot {idc(J1,d1) vdc(d1) idc(J1,g1) vdc(g1) idc(J1,s1) vdc(s1) }
ac dec 100 10MEG 1000MEG
dcoppt

acmodel { J1 }




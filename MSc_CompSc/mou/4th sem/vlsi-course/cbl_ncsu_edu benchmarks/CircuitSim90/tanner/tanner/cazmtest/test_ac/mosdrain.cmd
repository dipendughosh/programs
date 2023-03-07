
volt vdd GND 5.0
volt vbulk GND 1.0 label=VSS
volt vin GND 0.0 acmag= 0.5 acphase= 0.0
plot {ir(Rd,d1) ir(M1,d1) ir(M1,g1) ir(M1,s1) ir(M1,b1) }
plot {idc(Rd,d1) idc(M1,d1) idc(M1,g1) idc(M1,s1) idc(M1,b1) }
plot {idc(VSS,vbulk) idc(Rb,b1) idc(Rd,d1) idc(Rs,s1)}
acmodel { M1  }
dcoppt
ac dec 2 1MEG 10000MEG
options abstol=1.0e-12 reltol=1.0e-12



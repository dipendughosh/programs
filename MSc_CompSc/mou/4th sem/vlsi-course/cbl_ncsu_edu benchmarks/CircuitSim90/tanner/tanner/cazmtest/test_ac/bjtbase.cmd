
volt vc GND  5.0
volt ve GND  0.0
volt vs GND  6.0
volt in GND  0.0 acmag=0.3 acphase=0.0
dcoppt
plot {  ir(Rb,b1)  ii(Rb,b1)  ir(Q1,b1)  ii(Q1,b1) }
plot {   i(Rb,b1)   i(Q1,b1)   i(Re,e1)   i(Q1,e1) }
plot { idc(Q1,e1) idc(Q1,c1) idc(Q1,b1) idc(Q1,s1) }
plot { idc(Re,e1) idc(Rc,c1) idc(Rb,b1) idc(Rs,s1) }

options abstol=1e-20 reltol=1e-12
ac lin 10 10 1000

acmodel { Q1  }


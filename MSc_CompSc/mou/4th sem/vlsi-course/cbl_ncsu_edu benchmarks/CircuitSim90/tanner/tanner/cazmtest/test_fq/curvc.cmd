
vc in GND controll GND 1.0u label=VC
wave controll pie { 0 1 100n 5 } label=VIN
plot { controll i(VC,GND) i(VC,in) i(Rseries,in) i(Rseries,gate) i(R1,gate)
i(R1,GND) v(GND,in) v(in,gate) in gate }
transient 100n .1n powerup
dcoppt
plot { vdc(controll,GND) idc(VC,GND) idc(VC,in) idc(R1,gate)
vdc(in,gate) in gate }




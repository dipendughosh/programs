options numnd=1000
*
* AC analysis
*
ac dec 10 10 10MEG
plot { vm(inp) vm(inm) vm(out) im(VDD2,vdd2) im(CUR1,bias) }
plot { vdc(inp) vdc(inm) vdc(out) }
plot { idc(VDD) idc(VDD2) } 
plot { idc(VINP) idc(VINM) }
plot { pdc(vdd,GND) pdc(vdd2,GND) } 
plot { pdc(inp,GND) pdc(inm,GND) }
acmodel { * }

dcoppt

volt vdd GND 5.00 label=VDD
volt vdd2 GND 5.00 label=VDD2
current vdd2 bias 75u label=CUR1
volt inp GND 2.5000 label=VINP
volt inm GND 2.5000 acmag= 1.000 acphase= 0.0 label=VINM
power vdd GND
power vdd2 GND

*

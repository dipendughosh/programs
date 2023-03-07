volt VDD1 GND 5.0
volt GND1 GND 0.0
wave in GND bit {01} pw=10n on=3.0 off=0.2
plot {out,i(mtwo,out),i(mone,out),i(mone,GND1), i(mone,in) i(r1,out) q(r1,out) }
transient 50n .05n 



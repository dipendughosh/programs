volt VDD1 GND 5.0
volt GND1 GND 0.0
wave in GND bit {01} pw=10n on=3.0 off=0.2
plot { out i(freda,out), i(freda,in), i(freda,GND1),
 i(r1,out) q(r1,out) }
table minv minv.ftx minv.qtx
transient 50n .1n 





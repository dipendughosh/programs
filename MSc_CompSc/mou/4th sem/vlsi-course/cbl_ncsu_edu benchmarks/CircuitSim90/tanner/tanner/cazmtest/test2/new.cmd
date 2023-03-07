volt gnd3 gnd 0
volt pwr3 gnd 3.0 
volt vss gnd 0
volt vdd gnd 5.0 
volt vbias gnd 3.0

volt vref gnd 2.5
*volt vin gnd 2.55

*wave vin piec { 0,1.0 2n,}
wave vin bit {0 0 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0} pw=2n on=2.55 off=2.45

temp 70
power pwr3 gnd3
power vdd vss 
transient 36n 
plot {vlat vout vamp vin}

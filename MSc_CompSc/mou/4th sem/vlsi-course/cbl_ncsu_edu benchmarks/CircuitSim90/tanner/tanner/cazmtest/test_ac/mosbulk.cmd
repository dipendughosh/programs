
vrange mos 15
volt vdd GND 13.0
volt vin GND 1.5 acmag= 0.5 acphase= 0.0
ac dec 10 1MEG 10000MEG
plot {ir(Rb,b1) ii(Rb,b1) ir(M1,b1) ii(M1,b1) }
acmodel { M1  }







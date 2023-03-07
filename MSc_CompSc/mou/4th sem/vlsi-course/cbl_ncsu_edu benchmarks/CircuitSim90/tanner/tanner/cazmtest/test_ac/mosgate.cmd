
vrange mos 15
volt vdd GND 13.0
volt vin GND 1.5 acmag= 0.5 acphase= 0.0
ac dec 10 1MEG 10000MEG
plot {ir(Rg,g1) ii(Rg,g1) ir(M1,g1) ii(M1,g1) }
acmodel { M1  }







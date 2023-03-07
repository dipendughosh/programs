/* Reflection Cancelation Model for CMOS */
ic {xload2/inpad=0 xload3/inpad=0 xload4/inpad=0}
volt vdd 5.0
wave vs1 GND pie {0n 0 .1n 5 20n 5}
wave vs2 GND pie {0n 0 .1n 5 20n 5}
wave vs3 GND pie {0n 0 .1n 5 20n 5}
wave vs4 GND pie {0n 0 .1n 5 20n 5}
options reltol=1.0e-6 abstol=1.0e-9
vrange mos 10
transient 5ns 
plot {vs1 vload1 
          vload2 po2 xload2/inpad
    vsum3 vload3 po3 vtest3 
    vsum4 vload4 po4 vtest4}

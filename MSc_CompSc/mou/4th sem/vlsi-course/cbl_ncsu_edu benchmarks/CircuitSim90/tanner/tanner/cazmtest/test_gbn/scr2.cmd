
transient 1.0e-2
options chargetol=1.0e-12
wave power gnd sin amp=170 freq=60
wave trig gnd pie {0,0, 4e-3,0, 4.1e-3,2, 4.323e-3,2, 4.333e-3,0, 8.333,0}
plot {v(power), v(trig), i(rload, power)}


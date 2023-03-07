
transient 1.0e-2
wave power gnd sin amp=170 freq=60
***** ACTUALLY want amp=170, but even untriggered case bombs *****
wave trig gnd pie {0,0, 4e-3,0, 4.1e-3,1, 4.323e-3,1, 4.333e-3,0, 8.333,0}
***** ACTUALLY want to use wave ... bit{...}, but delay=4e-3 doesn't work *****
plot {v(power), v(trig), i(rload, power)}
options numnt=300 numnd=1500

* ECL CKT - EMITTER COUPLED LOGIC INVERTER

volt 8 0 5.0
volt 6 0 3.6
waveform 1 piecewise {0 4.0 1n 4.0 2n 3.2 22n 3.2 30n 4.0 50n 4.0}

options abstol=1e-10

transient 50n 0.5n powerup
plot {v(1),i(inv1/RIN,inv1/2),v(inv1/3),v(7),v(28)}

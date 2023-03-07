* ECL CKT - EMITTER COUPLED LOGIC INVERTER

volt 8 0 5.0
volt 6 0 3.6
waveform 1 piecewise {0 4.0 1n 4.0 2n 3.2 22n 3.2 30n 4.0 50n 4.0}

options abstol=1e-10

transient 50n 0.5n
*transfer {1 3.2 4}
plot {v(1),i(RIN,2),v(3),v(5)}

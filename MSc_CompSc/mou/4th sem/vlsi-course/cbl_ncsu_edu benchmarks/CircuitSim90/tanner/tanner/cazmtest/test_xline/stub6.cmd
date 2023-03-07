/* Same as STUB6 except for timing here */
wave vs1 GND pie {0n 0 .1n 1 1n 1 1.1n 0 2n 0}
wave vs2 GND pie {0n 0 .1n 1 1n 1 1.1n 0 2n 0}
wave vs3 GND pie {0n 0 .1n 1 1n 1 1.1n 0 2n 0}
wave vs4 GND pie {0n 0 .1n 1 1n 1 1.1n 0 2n 0}
transient 10ns
*options reltol=1.0e-3
plot {vs1 vload1 vload2 vsum3 vload3 vtest3 vsum4 vload4 vtest4}

wave n1 pie {0 5 100n 5 101n 0 1000n 0} label=VIN

plot {i(VIN,GND) i(rone,n1) i(lone,ind) }
transient 1000ns  1n

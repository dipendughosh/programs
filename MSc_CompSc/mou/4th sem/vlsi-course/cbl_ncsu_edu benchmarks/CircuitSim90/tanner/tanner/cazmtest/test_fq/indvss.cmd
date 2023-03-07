wave n1 pie {0 0 100n 0 101n 5 500n 5 501n 0 1000n 0} label=VIN
plot { i(VIN,GND) i(rone,n1) i(lone,ind1) }

transient 1000ns 1ns powerup


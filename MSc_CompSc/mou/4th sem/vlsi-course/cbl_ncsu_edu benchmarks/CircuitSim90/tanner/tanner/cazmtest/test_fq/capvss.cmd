wave n1 pie {0 0 100n 0 101n 5 500n 5 501n 0 1000n 0} label=VIN
plot { n1 cap1 i(VIN,GND) i(rone,n1) i(cone,cap1) }

transient 1000ns powerup

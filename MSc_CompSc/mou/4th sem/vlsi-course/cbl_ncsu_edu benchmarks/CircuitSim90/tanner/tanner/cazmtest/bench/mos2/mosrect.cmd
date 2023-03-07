wave 21 0 sin  label=VIN freq=2MEG amp=5.0 damp=0.0 offset=1.0 delay=10.0n 
plot { v(2) v(3) v(4) }

transient 1000n 1n
vrange mos 10

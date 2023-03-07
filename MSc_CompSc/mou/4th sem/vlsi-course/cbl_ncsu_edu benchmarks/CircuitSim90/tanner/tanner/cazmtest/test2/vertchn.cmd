wave ramp bit {01} pw=10n rt=0.1n ft=0.1n
*wave ramp bit {01} pw=5n 
*wave ramp sin amp=2.5 offset=2.5 freq=1.0e8
*wave s1 sin amp=2.5 delay=20ns offset=0.0 freq=1.0e8
*wave s2 sin amp=2.5 offset=2.5 freq=1.0e8 damp=1.0e7
*wave s3 sin amp=2.5 offset=2.5 freq=1.0e8 damp=1.0e8
*ic {s1 5 s2 5}


plot {ramp s1 }
plot {s2 s3 s4 s5 s6 out}
transient 100n 0.5n powerup
ic {s1 1 s2 1 s3 1 s4 1 s6 1}

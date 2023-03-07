volt vddp vss 3.5
volt vssp vss -3.5
volt vddn vss 3.5
volt vssn vss -3.5
wave gaten sin amp=0.5 freq=50000000 offset=0.0 delay=20.0n
wave gatep sin amp=0.5 freq=50000000 offset=0.0 delay=20.0n
plot {gaten dn sn gatep dp sp}
transient 150n .1n powerup


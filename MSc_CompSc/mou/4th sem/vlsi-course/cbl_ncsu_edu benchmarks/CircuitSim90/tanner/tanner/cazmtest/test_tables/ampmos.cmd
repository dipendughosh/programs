volt vddn vss 5.0
volt vddp vss -5.0
wave gaten sin amp=0.1 freq=50000000 offset=2.5 delay=20.0n
wave gatep sin amp=0.1 freq=50000000 offset=-2.5 delay=20.0n
plot {
gaten dn sn
gatep dp sp
}
transient 150n .1n dcoppt

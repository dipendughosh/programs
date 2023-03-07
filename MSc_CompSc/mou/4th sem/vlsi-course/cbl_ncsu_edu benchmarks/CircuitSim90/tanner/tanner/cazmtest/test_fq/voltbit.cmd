

wave in bit { 1111 0000 1111 1111 } on=5 pw=10n delay=10n label=VIN
plot { i(VIN,GND) i(VIN,in) i(Rseries,in) i(C1,gate) }
transient 100n .1n powerup


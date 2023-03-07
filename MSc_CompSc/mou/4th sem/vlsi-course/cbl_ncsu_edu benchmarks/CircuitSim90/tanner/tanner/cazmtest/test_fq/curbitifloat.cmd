

wave in new biti { 1111 0000 1111 1111 } on=5u pw=10n delay=10n label=VIN
plot { i(VIN,new) i(VIN,in) i(Rseries,in) i(C1,gate) v(new, in)  in gate }
transient 100n .1n powerup





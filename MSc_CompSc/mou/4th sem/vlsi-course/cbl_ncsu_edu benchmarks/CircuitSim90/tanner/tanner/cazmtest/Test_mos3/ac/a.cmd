volt Vdd GND 5.0

wave in pie {0 0 1n 0 1.01n 5 10n 5 10.01n 0 20n 0 }

transient 20n 1n
plot { in i(in,gate) drain i(Vdd,drain) }

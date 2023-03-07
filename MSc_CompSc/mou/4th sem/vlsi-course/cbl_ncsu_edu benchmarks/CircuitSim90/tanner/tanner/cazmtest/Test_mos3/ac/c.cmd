volt Vdd GND 5.0

wave in pie {0 0 1n 0 1.01n 5 2n 5 2.01n 0 4n 0 }

transient 4n 0.1n
plot { in i(in,drain1) i(in,drain2) i(in,drain3) i(in,drain4) i(in,drain5) i(in,drain6) }

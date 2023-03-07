wave a bit {10(0011)} ph=10n off=0.0 on=5.0
wave b bit {5(0011)} ph=20n off=0.0 on=5.0

volt Vdd1 GND 4
volt GND1 GND 0

plot { a b abar ex i(abar,vss) }

power GND1 Vdd1

transient 280n


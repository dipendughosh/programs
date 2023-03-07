wave a bit {10(0011)} ph=5n off=0.0 on=4.0
wave b bit {5(0011)} ph=10n off=0.0 on=4.0
wave c bit {10(0011)} ph=5n off=0.0 on=4.0
wave d bit {5(0011)} ph=10n off=0.0 on=4.0

volt Vdd2 GND 4
volt Vdd1 GND 4
volt GND1 GND 0

plot { a b abar ex sex }

power GND1 Vdd1
power GND1 Vdd2 

transient 400n 


* BICMOS INVERTER

volt Vdd GND 3.0
wave 1 piecewise { 0n 3.0 .2n 3.0 0.7n 0 40n 0 40.5n 3.0 80n 3.0}

plot {1 2 3 4}

transient 80n .01n

* This file is a pair of inverters, the first drives
* the second with very high fanout.  The purpose is to
* accentuate the Miller capacitance in the second inverter
* to produce the characteristic "kink" in the rising and
* falling waveforms.

* I1
m0 0 3 4 0 nfet l=1.6u w=4u
m1 2 3 4 2 pfet l=1.6u w=4u

*I2
m2 0 4 5 0 nfet l=1.6u w=100u
m3 2 4 5 2 pfet l=1.6u w=100u

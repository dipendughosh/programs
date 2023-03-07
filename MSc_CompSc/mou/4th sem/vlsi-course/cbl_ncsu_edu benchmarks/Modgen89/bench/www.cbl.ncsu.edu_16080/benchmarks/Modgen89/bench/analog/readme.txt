.PH ""
.ce
Analog

Analog layout is trickier than digital.
For that reason,
there are only two,
relatively simple analog benchmarks included here.

.H 1 "OPAMP"
The first is an opamp,
coming from  the 1987 Design Automation Conference proceedings
article ``A Prototype Framework for Knowledge-Based Analog Circuit Synthesis''
by Harjani, Rutenbar and Carly,
page 48, circuit B.
A postscript picture of this is in ``opamp.post''.
Call this benchmark 5.1.
Please extract it and demonstrate it works, 
if possible.

.H 1 "Filter"
The second is a switched-capacitor filter,
coming from the article 
``A Family of Active Switched Capacitor Biquad Building Blocks,"
by P. E. Fleischer and K. R. Laker, Bell System Technical Journal, Vol 58 No 10,
December 1979, pp 2235-2269.
Implement a notch filter as described on page 2258,
with a fz of 1800 Hz, sampling frequency of 128kHz, etc.
Use the E-circuit parameters found on page 2259 on the schematic
found on the bottom of page 2237 
(general active SC topology, minimum configuration).
Note that several of the capacitors are not needed for the notch filter
function.
Although the article does not specify it, 
use transistors that are minimum channel length and 4 times minimum width,
unless you do your own analysis showing better ones.
You may use the CMOS OPAMP from 5.1,
or your own.
You make make the capacitors in whatever way you think is best:
with poly/metal structures or whatever,
but see note (c) below.
A postscript picture of this circuit is in ``switch.post''.
Call this benchmark 5.2.
Please extract it and demonstrate it works, 
if possible.

.H 1 "Design Analysis"

With analog circuits,
the schematic information does not completely specify the requirements for layout.
Please consult with your local experts in analog design regarding such 
issues as:

a) pairing of transistors. 
For example, opamps need to have the input transistors
track exactly.

b) eliminating coupling capacitance from output to input.

c) making some of the ratio capacitors on the switched capacitor filter
track exactly across process variations.

Please include a discussion of these in your results.
Please use just one level of metal and one of poly.
Inputs and outputs may be anywhere on the perimeter.

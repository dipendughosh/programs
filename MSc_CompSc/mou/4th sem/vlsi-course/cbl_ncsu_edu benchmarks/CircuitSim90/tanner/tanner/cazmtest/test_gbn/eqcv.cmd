
*
*	Double the voltage with an equivalent Current-controlled-Voltage
*	source.
*
*	N1 and N2 are the nodes of a resistor that generates
*	the controlling current.
*
*		K  = 2000 
*		R1 = 1000 
*		V  = n1 - n2
*		I  = V/R1
*
*	where:
*
*		Voltage generated = ((n1 - n2)) * (K / R1)
*

*R1 n1 n2 1000
*E1 v1 v2 n1 n2 2.0
*Rload v1 v2 1000

wave n1 n2 sin freq=1000MEG amp=2.0

plot { v(n1,n2) i(R1,n1) v(v1,v2) }

transient 20ns .1ns


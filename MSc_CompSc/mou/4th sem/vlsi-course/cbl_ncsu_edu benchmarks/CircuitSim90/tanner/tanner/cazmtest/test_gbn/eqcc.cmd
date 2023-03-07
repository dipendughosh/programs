
*
* 	Double the current with an equivalent Current-contolled-Current
*	source.
*
*
*	N1 and N2 are the nodes of a resistor that generates
*	the controlling current.
*
*		K  = 2 
*		R1 = 1000 
*		V  = n1 - n2
*		I  = V/R1
*
*	where:
*
*		Current generated = ((n1 - n2)) * (K / R1)
*

*R1 n1 n2 1000
*G1 c1 c2 n1 n2 0.002
*Rload c1 c2 1000

wave n1 n2 sin freq=1000MEG amp=2.0

plot { v(n1,n2) i(R1,n1) v(c1,c2) i(Rload,c1) }

transient 20ns .1ns


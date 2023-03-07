
*
*	THIS CIRCUIT TEST THE RESONANCE OF
*	A SERIES TANK!
*
*	With a computed frequency of 2.5164606 MegaHertz

wave n1 sin amp=3.0 freq=2516460.6 offset=0.0 delay=20.0n 
wave n2 sin amp=3.0 freq=2516460.6 offset=0.0 delay=20.0n 
wave n3 sin amp=3.0 freq=2516460.6 offset=0.0 delay=20.0n 

plot { n1 ind1 cap1 ind2 cap2 ind3 cap3 }

transient 2000ns powerup


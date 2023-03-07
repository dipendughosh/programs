
wave 3 4 sin amp=0.0 freq=1n label=SIN
volt 1 2 0.0 label=VIN
current 1 0 5.0u label=CIN
plot {i(CIN,0) i(VIN,1) i(R2,2) i(SIN,3) i(R4,4) i(vnow,5) i(R6,6) }
transient 2n .2n 


* Test current sources *



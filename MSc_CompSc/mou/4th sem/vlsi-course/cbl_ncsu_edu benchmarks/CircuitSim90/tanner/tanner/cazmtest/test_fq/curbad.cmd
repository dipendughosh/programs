
current 1 0 5.0u label=CIN
wave 1 2 sin amp=0.0 freq=10n label=SIN
plot {i(CIN,0) i(SIN,1) i(R2,2) i(vnow,3) i(R4,4) }
transient 2n .2n 


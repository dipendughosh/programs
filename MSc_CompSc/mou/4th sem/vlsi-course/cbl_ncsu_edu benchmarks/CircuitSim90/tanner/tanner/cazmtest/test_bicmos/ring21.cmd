*BICMOS INVERTER CHAIN

volt 25 gnd 5.0
wave 1 piecewise { 0n 5.0 1.5n 5.0 1.55n 0 50n 0 }

options reltol=1e-4 chargetol=1e-17 
plot {V(1,0),V(21,0),V(22,0)}

transient 1200n

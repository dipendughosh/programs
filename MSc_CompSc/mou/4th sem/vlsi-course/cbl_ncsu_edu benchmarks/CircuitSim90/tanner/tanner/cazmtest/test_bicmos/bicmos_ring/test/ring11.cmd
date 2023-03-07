*BICMOS INVERTER CHAIN

volt 25 gnd 4.5
wave 1 piecewise { 0n 4.5 1.5n 4.5 1.55n 0 50n 0 }

gridsize mos 20 25 4
options numnd=400 reltol=1e-4 chargetol=1e-16 numnt=100
plot {V(1,0),V(11,0),V(12,0)}

transient 200n

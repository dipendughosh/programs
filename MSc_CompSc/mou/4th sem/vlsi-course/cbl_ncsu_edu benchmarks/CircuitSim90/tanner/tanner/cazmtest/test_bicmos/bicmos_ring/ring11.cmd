*BICMOS INVERTER CHAIN

volt 25 gnd 2.0
wave 1 piecewise { 0n 2.0 1.5n 2.0 1.55n 0 50n 0 }

*gridsize mos 20 25 8
*options numnd=400 reltol=1e-4 chargetol=1e-17 numnt=100
*options numnd=400 reltol=1e-4 abstol=1e-12 chargetol=1e-17 numnt=100
*options numnd=400 reltol=1e-5 chargetol=1e-15 numnt=100
options numnd=400 reltol=1e-5 abstol=1e-11 chargetol=5e-17 numnt=100
*options numnd=400 reltol=1e-4 chargetol=1e-17
plot {V(1,0),V(11,0),V(12,0)}

*transient 30n 0.01n
transient 30n

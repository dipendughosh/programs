transient 5N 
*transient 5N 20P 
plot { v(2) V(4) V(6) V(8) V(12)}
plot mtest.out { v(2) V(4) V(6) V(8) V(12)}
*gridsize mes 90 90 40
options chargetol=1.0e-16

*vrange mes 3

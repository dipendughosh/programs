************************************************************************
* COMMANDS
************************************************************************
*.TRANS 20P 5N
*.PRINT TRAN V(2) V(4) V(6) V(8) V(12)
************************************************************************

*.options ingold=2 col=132
transient 5n 20p
plot sunmes2.out {v(2) v(4) v(6) v(8) v(12)}
plot {v(2) v(4) v(6) v(8) v(12)}


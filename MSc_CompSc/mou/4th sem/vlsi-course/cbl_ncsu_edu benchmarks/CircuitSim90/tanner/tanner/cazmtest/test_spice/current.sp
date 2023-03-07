
*R2 2 3 1000
*VNOW 3 4 0.0
R4 2 5 100
C4 5 0 1p

*VIN 2 0 sin (0.0 0.0 10MEG 0.0 0.0) ac 0.5
*.print ac ir(VIN) ir(R4,2) vr(5) 

ICIN 2 0 0 ac 5u
.print ac ir(ICIN) ir(R4,2) vr(5) 

.ac DEC 5 10MEG 100MEG
.options limpts=50000 itl5=10000 reltol=1.0e-8
.end








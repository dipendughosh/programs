*MOSFET DIODE BRIDGE

.model nenh nmos
+Level=2 Ld=0.0u Tox=225.000e-10
+Nsub=1.066e+16 Vto=0.622490 Kp=6.326640E-05
+Gamma=.639243 Phi=.31 Uo=1215.74
+Uexp=4.612355e-2 Ucrit=174667 Delta=0.0
+Vmax=177269 Xj=.9u Lambda=0.0
+Nfs=4.55168e+12 Neff=4.68830 Nss=3.000000E+10
+Tpg=1.00000 Rsh=60 Cgso=2.89e-10
+Cgdo=2.89e-10 Cj=3.27e-04 Mj=1.067
+Cjsw=1.74e-10 Mjsw=.195

.model penh pmos
+Level=2 Ld=.03000000u Tox=225.000e-10
+Nsub=6.575441e+16 Vto=-0.63025 Kp=2.635440E-05
+Gamma=0.618101 Phi=.541111 Uo=361.941
+Uexp=8.886957e-02 Ucrit=637449 Delta=0.0
+Vmax=63253.3 Xj=0.112799u Lambda=0.
+Nfs=1.668437e+11 Neff=0.64354 Nss=3.000000E+10
+Tpg=-1.00000 Rsh=150 Cgso=3.35e-10
+Cgdo=3.35e-10 Cj=4.75e-04 Mj=.341
+Cjsw=2.23e-10 Mjsw=.307

*
*
VDD 1 0 10v

R2 21 20 10
L1 20 0 1u
L2 2  3   1u
K1 L1 L2 .9

*       pos neg
md1 1 0 2   0   nenh l=1.25u w=50u as=50p ps=50u ad=50p pd=50u
md2 1 0 4   2   nenh l=1.25u w=50u as=50p ps=50u ad=50p pd=50u
md3 1 0 3   0   nenh l=1.25u w=50u as=50p ps=50u ad=50p pd=50u
md4 1 0 4   3   nenh l=1.25u w=50u as=50p ps=50u ad=50p pd=50u
r1 4 0 100K

VIN 21 0 SIN (1.0 5.0 2MEG 10.0n 0.0)
.print tran v(2) v(3) v(4)
.tran 1n 1000n
.end

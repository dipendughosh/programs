*TEST FOR SMALL SEU HARD D-LATCH		Sandia


* level 3 models only work with lvltim=1
.model nmod nmos(
+ vto    =  1.20269e+0   uo     =  7.01737e+2   nsub   =  1.11136e+17
+ nfs    =  1.81211e+12  kappa  =  2.00000e-2   phi    =  8.10335e-1 
+ theta  =  6.05549e-2   gamma  =  1.74402e+0   vmax   =  1.87637e+5
+ eta    =  3.99308e-1   tox    =  3.15000e-8   xj     =  3.00000e-7
+ tpg    =  1.00000e+0   js     =  1.00000e-7   cj     =  9.77838e-4
+ pb     =  9.71479e-1   rsh    =  4.07910e+1   level  =  3)

.model pmod pmos(
+ vto    = -1.16509e+0   uo     =  3.53096e+2   kappa  =  2.00000e-2
+ nsub   =  5.54420e+15  nfs    =  1.67611e+12  gamma  =  6.18987e-1
+ phi    =  1.19566e+0   theta  =  1.50551e-1   vmax   =  2.78427e+5
+ eta    =  1.57677e+0   tox    =  3.15000e-8   xj     =  3.00000e-7
+ tpg    = -1.00000e+0   js     =  1.00000e-7   cj     =  2.27692e-4
+ pb     =  8.93830e-1   rsh    =  1.49570e+2   level  =  3)


VDD 99 0 5.0
VND 1 0 5.0
VC  8 0 0.0
VSEU 11 0 pwl(0.0ns 5.0v 30.0ns 5.0 30.1ns 0.0 40.0ns 0.0 40.1ns 5.0 50ns 5.0)
VSEU2 12 0 pwl(0.0ns 0.0v 10.0ns 0.0 10.1ns 5.0 20.0ns 5.0 20.1ns 0.0 50ns 0.0)

*seu injection transistors
mpseu 99 11 4 99 pmod w=100u l=2u as=0.01p ad=0.01p 
mnseu 0  12 4 0  nmod w=100u l=2u as=0.01p ad=0.01p 

* clock inverter
mpinv 9 8 99 99 pmod w=7.5u l=2u as=45p ad=45p
mninv 9 8  0  0 nmod w=5.5u l=2u as=35p ad=35p

*latch and input inverter
mp1 2 1 99 99 pmod w=7.5u l=2u as=45p ad=45p nrs=0.27 nrd=0.27
mp2 2 9  3 99 pmod w=9u l=2u as=25p ad=50p nrs=0.22 nrd=0.22 
mp3 4 3 99 99 pmod w=9u l=2u as=25p ad=50p nrs=0.22 nrd=0.22 
mp4 6 5 99 99 pmod w=9u l=2u as=25p ad=12p nrs=0.22 nrd=0.22 
mp5 3 8  6 99 pmod w=9u l=2u as=12p ad=25p nrs=0.22 nrd=0.22 

mn1 2 1  0  0 nmod w=5.5u l=2u as=35p ad=35p nrs=0.36 nrd=0.36 
mn2 2 8  3  0 nmod w=9u l=2u as=25p ad=50p nrs=0.22 nrd=0.22 
mn3 4 3  0  0 nmod w=9u l=2u as=25p ad=50p nrs=0.22 nrd=0.22 
mn4 7 5  0  0 nmod w=9u l=2u as=25p ad=12p nrs=0.22 nrd=0.22 
mn5 3 9  7  0 nmod w=9u l=2u as=12p ad=25p nrs=0.22 nrd=0.22 

r1 4 5 200k

.tran 0.1ns 50ns
.print tran v(11) v(12) v(3) v(4) v(5)
.options acct limpts=10000 lvltim=1

.end

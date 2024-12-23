*nand test

vdd 1 0 dc 5.5
vpulse 2 0 pulse 0 5.5 1n 1n 1n 10n 22n
vtest1 100 9 dc 0
vtest2 200 12 dc 0
vtest3 300 13 dc 0

.tran .05n 20n
.print tran v(2) i(vpulse)
.options acct limpts=5000

* nominal 2 micron model 0e0 at 25c level 3
* ps:<sanca_models.cmos_iii>n2u0e0r.lv3.2

.model nmod nmos(
+ vto    =  1.20269e+0
+ uo     =  7.01737e+2
+ nsub   =  1.11136e+17
+ nfs    =  1.81211e+12
+ kappa  =  2.00000e-2
+ phi    =  8.10335e-1
+ theta  =  6.05549e-2
+ gamma  =  1.74402e+0
+ vmax   =  1.87637e+5
+ eta    =  3.99308e-1
+ tox    =  3.15000e-8
+ xj     =  3.00000e-7
+ tpg    =  1.00000e+0
+ js     =  1.00000e-7
+ cj     =  9.77838e-4
+ pb     =  9.71479e-1
+ rsh    =  4.07910e+1
+ cgso   =  0.00000e+0
+ cgdo   =  0.00000e+0
+ mjsw   =  0.33000e+0
+ ld     =  0.00000e+0
+ level  =  3)
* seq no:    17  ta632-m  h1235a  w10  d5  2u  1nn  25c  0e0

.model pmod pmos(
+ vto    = -1.16509e+0
+ uo     =  3.53096e+2
+ kappa  =  2.00000e-2
+ nsub   =  5.54420e+15
+ nfs    =  1.67611e+12
+ gamma  =  6.18987e-1
+ phi    =  1.19566e+0
+ theta  =  1.50551e-1
+ vmax   =  2.78427e+5
+ eta    =  1.57677e+0
+ tox    =  3.15000e-8
+ xj     =  3.00000e-7
+ tpg    = -1.00000e+0
+ js     =  1.00000e-7
+ cj     =  2.27692e-4
+ pb     =  8.93830e-1
+ rsh    =  1.49570e+2
+ cgso   =  0.00000e+0
+ cgdo   =  0.00000e+0
+ mjsw   =  0.33000e+0
+ ld     =  0.00000e+0
+ level  =  3)
* seq no:    23  ta632-m  h1235a  w04  d5  2u  1np  25c  0e0

cload1 14 0 15pf

m9 3 2 1 1 pmod l=2.2u w=100u as=700p ad=700p nrs=0.026 nrd=0.026
m10 3 2 0 0 nmod l=2u w=60u as=420p ad=420p nrs=0.043 nrd=0.043

m2 9 3 1 1 pmod l=2.2u w=200u as=1400p ad=1400p nrs=0.013 nrd=0.013
m3 9 1 1 1 pmod l=2.2u w=200u as=1400p ad=1400p nrs=0.013 nrd=0.013
m7 9 1 7 0 nmod l=2u w=240u as=1680p ad=1680p nrs=0.0108 nrd=0.0108
m8 7 3 0 0 nmod l=2u w=240u as=1680p ad=1680p nrs=0.0108 nrd=0.0108


m11 200 100 1 1 pmod l=2.2u w=400u as=2800p ad=2800p nrs=0.0065 nrd=0.0065
m12 200 100 0 0 nmod l=2u w=240u as=1680p ad=1680p nrs=0.0108 nrd=0.0108

m13 300 12 1 1 pmod l=2.2u w=1200u as=8400p ad=8400p nrs=0.0022 nrd=0.0022
m14 300 12 0 0 nmod l=2u w=720u as=5040p ad=5040p nrs=0.0036 nrd=0.0036

m15 14 13 1 1 pmod l=2.2u w=4000u as=28000p ad=28000p nrs=0.00065 nrd=0.00065
m16 14 13 0 0 nmod l=2u w=2560u as=17920p ad=17920p nrs=0.00102 nrd=0.00102

.end

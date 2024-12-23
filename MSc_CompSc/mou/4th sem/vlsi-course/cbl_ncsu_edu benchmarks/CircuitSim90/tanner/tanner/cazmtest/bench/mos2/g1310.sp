*rca standard cell c1310
*
* nominal models--version 1  ** 5mar80
*
.model pchnl1 pmos(    vto -1.615    kp 1.191e-5   gamma 0.2715
+                      phi 0.5663    uexp 0.3022   ucrit 1.35e5
+                      lambda 0.005  cj 9.17e-5    nsub=8.2e14
+                      pb 0.9        rd 10.9       rs 10.9
+                      tox 5.67e-8   js 1.94e-6   level 2)
.model nchnl1 nmos(    vto 0.7746    kp 4.958e-5   gamma 1.300
+                      phi 0.7283    uexp 0.2715   ucrit 2.01e5
+                      utra 2.0      lambda 0.01   cj 7.1e-4
+                      pb 0.9        rd 3.7        nsub=1.8e16
+                      rs 3.7        tox 5.67e-8   js 1.57e-8
+                      level 2)
.model diodnpw d(cjo 6.50e-8   vj .9   is 3.00e-12   n 3.17)
.model diodppn d(cjo 2.0e-8    vj .9   is 2.40e-11   n 3.42)
*
*subcircuit description of the c1310 inverter
*
.subckt in1310 1 2 3 57
mp 4 2  6 5  pchnl1 w=4.93mil l=.174mil ad=5.18e-10 as=5.18e-10
mn 8 2 10 9 nchnl1 w=3.33mil l=.174mil ad=3.50e-10 as=3.50e-10
dpin 2 1 diodppn area=4.93e-10
dpot 3 1 diodppn area=4.93e-10
dpdp 11 1 diodppn area=2.71e-9
dpdn 57 7 diodnpw area=1.70e-9
cmin 2 57 .316pf
cmout 3 57 .127pf
rpdp1 3 11 4.33
rpdp2 11 4 4.33
rpbp 5 1 .1
rpsp 6 1 7.94
rpdn1 3 7 1.41
rpdn2 7 8 1.41
rpbn 9 57 .1
rpsn 10 57 3.21
co 3 57 5pf
.ends
*
*independent sources
*
vdd 1 0 dc 10volts
vss 6 0 dc  0volts
vin  3 6 pulse (0volts 10volts 10ns 20ns 20ns 50ns 200ns)
*
*circuit description
*
x1 1  3   4 6 in1310
x2 1  4   5 6 in1310
x3 1  5   7 6 in1310
x4 1  7   8 6 in1310
x5 1  8   9 6 in1310
x6 1  9  10 6 in1310
x7 1 10  11 6 in1310
*
*sanca control
*
.tran 2ns 200ns
.options abstol=10n acct list node
.print tran v(3) v(4) v(5) v(7) v(8)
.print tran v(9) v(10) v(11)
.end

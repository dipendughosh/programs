*cram.sp SPICE FILE
.model nenh nmos
+ level = 2
+   vto = 0.779   kp = 3.52e-05   gamma = 1.04
+   phi = 0.6
+
+   cgso = 5.2e-10   cgdo = 5.2e-10
+   rsh = 25   cj = 0.00042
+   mj = 0.5   cjsw = 9e-10   mjsw = 0.33
+   tox = 5e-08   nsub = 1e+16
+   nss = 0   nfs = 1.306e+11   tpg = 1
+   xj = 3.85e-08   ld = 1e-07   uo = 400
+   ucrit = 999000   uexp = 0.001001
+   vmax = 32585.3   neff = 0.01001
+
+   delta = 1.33
.model penh pmos
+ level = 2
+   vto = -0.988   kp = 1.206e-05   gamma = 0.619
+   phi = 0.6
+
+   cgso = 4e-10   cgdo = 4e-10
+   rsh = 95   cj = 0.00032
+   mj = 0.5   cjsw = 5.5e-10   mjsw = 0.33
+   tox = 5e-08   nsub = 8.158e+14
+   nss = 0   nfs = 5.55e+09   tpg = -1
+   xj = 1.46e-07   ld = 2.52e-07   uo = 150
+   ucrit = 54941   uexp = 0.17
+   vmax = 100000   neff = 0.01001
+
+   delta = 1.129
.subckt cram#top 1 2 3 4 5
+ 6 7 8 9 10 11
md6 1 11 3 1 penh l=3e-06 w=1.4e-05 
+ as=5.6e-11 ad=5.6e-11 ps=3.6e-05 pd=3.6e-05 
m1 12 8 3 2 nenh l=3e-06 w=7e-06 
+ as=2.8e-11 ad=2.8e-11 ps=2.2e-05 pd=2.2e-05 
m2 13 8 4 2 nenh l=3e-06 w=7e-06 
+ as=2.8e-11 ad=2.8e-11 ps=2.2e-05 pd=2.2e-05 
m3 13 12 2 2 nenh l=3e-06 w=7e-06 
+ as=2.8e-11 ad=2.8e-11 ps=2.2e-05 pd=2.2e-05 
m4 2 13 12 2 nenh l=3e-06 w=7e-06 
+ as=2.8e-11 ad=2.8e-11 ps=2.2e-05 pd=2.2e-05 
m5 13 12 1 1 penh l=3e-06 w=7e-06 
+ as=2.8e-11 ad=2.8e-11 ps=2.2e-05 pd=2.2e-05 
m6 1 13 12 1 penh l=3e-06 w=7e-06 
+ as=2.8e-11 ad=2.8e-11 ps=2.2e-05 pd=2.2e-05 
m7 14 7 3 2 nenh l=3e-06 w=7e-06 
+ as=2.8e-11 ad=2.8e-11 ps=2.2e-05 pd=2.2e-05 
m8 15 7 4 2 nenh l=3e-06 w=7e-06 
+ as=2.8e-11 ad=2.8e-11 ps=2.2e-05 pd=2.2e-05 
m9 2 14 15 2 nenh l=3e-06 w=7e-06 
+ as=2.8e-11 ad=2.8e-11 ps=2.2e-05 pd=2.2e-05 
m10 14 15 2 2 nenh l=3e-06 w=7e-06 
+ as=2.8e-11 ad=2.8e-11 ps=2.2e-05 pd=2.2e-05 
md11 4 10 6 1 penh l=3e-06 w=1.4e-05 
+ as=5.6e-11 ad=5.6e-11 ps=3.6e-05 pd=3.6e-05 
md12 4 9 6 2 nenh l=3e-06 w=1.4e-05 
+ as=5.6e-11 ad=5.6e-11 ps=3.6e-05 pd=3.6e-05 
md13 5 10 3 1 penh l=3e-06 w=1.4e-05 
+ as=5.6e-11 ad=5.6e-11 ps=3.6e-05 pd=3.6e-05 
md14 5 9 3 2 nenh l=3e-06 w=1.4e-05 
+ as=5.6e-11 ad=5.6e-11 ps=3.6e-05 pd=3.6e-05 
md1 15 14 1 1 penh l=3e-06 w=7e-06 
+ as=2.8e-11 ad=2.8e-11 ps=2.2e-05 pd=2.2e-05 
md2 1 15 14 1 penh l=3e-06 w=7e-06 
+ as=2.8e-11 ad=2.8e-11 ps=2.2e-05 pd=2.2e-05 
md3 1 11 4 1 penh l=3e-06 w=1.4e-05 
+ as=5.6e-11 ad=5.6e-11 ps=3.6e-05 pd=3.6e-05 
cbitoutbar 3 2 5.04e-14
cbitout 4 2 4.62e-14
cbitbar 5 2 6.3e-15
cbit 6 2 1.26e-14
cselect1 7 2 5.4e-15
cselect0 8 2 5.4e-15
cwrite 9 2 1.08e-14
cwritebar 10 2 1.08e-14
cprecharg 11 2 7.2e-15
cI0 12 2 1.08e-14
cI1 13 2 1.17e-14
cI2 14 2 1.08e-14
cI3 15 2 1.17e-14
.ends cram#top
.subckt cram#mid 1 2 3 4 5
+ 6
m11 1 8 7 1 penh l=3e-06 w=7e-06 
+ as=2.8e-11 ad=2.8e-11 ps=2.2e-05 pd=2.2e-05 
m12 8 7 1 1 penh l=3e-06 w=7e-06 
+ as=2.8e-11 ad=2.8e-11 ps=2.2e-05 pd=2.2e-05 
m13 7 8 2 2 nenh l=3e-06 w=7e-06 
+ as=2.8e-11 ad=2.8e-11 ps=2.2e-05 pd=2.2e-05 
m14 2 7 8 2 nenh l=3e-06 w=7e-06 
+ as=2.8e-11 ad=2.8e-11 ps=2.2e-05 pd=2.2e-05 
m15 8 4 5 2 nenh l=3e-06 w=7e-06 
+ as=2.8e-11 ad=2.8e-11 ps=2.2e-05 pd=2.2e-05 
m16 7 4 6 2 nenh l=3e-06 w=7e-06 
+ as=2.8e-11 ad=2.8e-11 ps=2.2e-05 pd=2.2e-05 
m17 1 10 9 1 penh l=3e-06 w=7e-06 
+ as=2.8e-11 ad=2.8e-11 ps=2.2e-05 pd=2.2e-05 
m18 10 9 1 1 penh l=3e-06 w=7e-06 
+ as=2.8e-11 ad=2.8e-11 ps=2.2e-05 pd=2.2e-05 
m19 2 10 9 2 nenh l=3e-06 w=7e-06 
+ as=2.8e-11 ad=2.8e-11 ps=2.2e-05 pd=2.2e-05 
m20 10 9 2 2 nenh l=3e-06 w=7e-06 
+ as=2.8e-11 ad=2.8e-11 ps=2.2e-05 pd=2.2e-05 
m21 10 3 5 2 nenh l=3e-06 w=7e-06 
+ as=2.8e-11 ad=2.8e-11 ps=2.2e-05 pd=2.2e-05 
m22 9 3 6 2 nenh l=3e-06 w=7e-06 
+ as=2.8e-11 ad=2.8e-11 ps=2.2e-05 pd=2.2e-05 
cselect0 3 2 5.4e-15
cselect1 4 2 5.4e-15
cbit 5 2 2.73e-14
cbitbar 6 2 2.73e-14
cI0 7 2 1.08e-14
cI1 8 2 1.17e-14
cI2 9 2 1.08e-14
cI3 10 2 1.17e-14
.ends cram#mid
xI40 1 0 3 4 5
+ 6 7 8 9 10 11 cram#top
xI30 1 0 16 17 18
+ 19 7 8 9 10 11 cram#top
xI20 1 0 24 25 4
+ 3
+ cram#mid
xI10 1 0 24 25 17
+ 16
+ cram#mid
Vprecharg 11 0 pwl (0 5 4e-07 5 4.01e-07 0 4.25e-07 0 
+ 4.26e-07 5 5e-07 5 5.01e-07 0 5.25e-07 0 
+ 5.26e-07 5 6e-07 5 6.01e-07 0 6.25e-07 0 
+ 6.26e-07 5 7e-07 5 7.01e-07 0 7.25e-07 0 
+ 7.26e-07 5 8e-07 5 )
Vwrite 9 0 pwl (0 5 4e-07 5 4.01e-07 0 8e-07 0 
+ 8.01e-07 5 )
Vwritebar 10 0 pwl (0 0 4e-07 0 4.01e-07 5 8e-07 5 
+ 8.01e-07 0 )
Vd 19 0 pwl (0 0 1e-07 0 1.01e-07 5 2e-07 5 
+ 2.01e-07 0 3e-07 0 3.01e-07 5 4e-07 5 
+ 4.01e-07 0 5e-07 0 5.01e-07 5 6e-07 5 
+ 6.01e-07 0 7e-07 0 7.01e-07 5 8e-07 5 
+ 8.01e-07 0 )
Vd1 6 0 pwl (0 0 2e-07 0 2.01e-07 5 4e-07 5 
+ 4.01e-07 0 6e-07 0 6.01e-07 5 8e-07 5 
+ 8.01e-07 0 )
Vdbar 18 0 pwl (0 5 1e-07 5 1.01e-07 0 2e-07 0 
+ 2.01e-07 5 3e-07 5 3.01e-07 0 4e-07 0 
+ 4.01e-07 5 5e-07 5 5.01e-07 0 6e-07 0 
+ 6.01e-07 5 7e-07 5 7.01e-07 0 8e-07 0 
+ 8.01e-07 5 )
Vdbar1 5 0 pwl (0 5 2e-07 5 2.01e-07 0 4e-07 0 
+ 4.01e-07 5 6e-07 5 6.01e-07 0 8e-07 0 
+ 8.01e-07 5 )
Vselect1 8 0 pwl (0 0 2.5e-08 0 2.6e-08 5 7.5e-08 5 
+ 7.6e-08 0 4.25e-07 0 4.26e-07 5 4.75e-07 5 
+ 4.76e-07 0 8e-07 0 )
Vselect2 7 0 pwl (0 0 1.25e-07 0 1.26e-07 5 1.75e-07 5 
+ 1.76e-07 0 5.25e-07 0 5.26e-07 5 5.75e-07 5 
+ 5.76e-07 0 8e-07 0 )
Vselect3 24 0 pwl (0 0 2.25e-07 0 2.26e-07 5 2.75e-07 5 
+ 2.76e-07 0 6.25e-07 0 6.26e-07 5 6.75e-07 5 
+ 6.76e-07 0 8e-07 0 )
Vselect4 25 0 pwl (0 0 3.25e-07 0 3.26e-07 5 3.75e-07 5 
+ 3.76e-07 0 7.25e-07 0 7.26e-07 5 7.75e-07 5 
+ 7.76e-07 0 8e-07 0 )
VVDD 1 0 5
.print TRAN v(19) v(6) v(11) v(9) v(8) v(7) 
+v(17) v(4) 
*.options limpts=50000 itl5=50000
.TRAN 1e-09 8e-07
.end

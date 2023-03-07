** spice exercise ***
 .width in=72 out=72
 .opt abstol=1u
 .opt acct list node
* .tran 5ns 500ns
 vbb 1 0 dc 0.0
 vdd  3 0 dc  5.0
 m1  13   23  24   1 enh   w=20u   l=5u
 m2  3   3  14   1 enh   w=50u   l=5u
 m3  3   3  13   1 enh   w=50u   l=5u
 m4  3   3  21   1 enh   w=50u   l=50u
 m5  21   21  0   1 enh   w=50u   l=50u
 m6  6   17  16   1 enh   w=85u   l=5u
 m7  15   9  11   1 enh   w=85u   l=5u
 m9  16   17  11   1 enh   w=85u   l=5u
 m10 7   9  15   1 enh   w=85u   l=5u
 m14 19   14  0   1 enh   w=15u   l=5u
 m15 18   13  0   1 enh   w=15u   l=5u
 m16 23   9  20   1 enh   w=20u   l=5u
 m18 3   19  5   1 dep   w=10u   l=10u
 m19 5   18  0   1 enh   w=50u   l=5u
 m20 17   9  0   1 enh   w=15u   l=5u
 m21 3   17  17   1 dep   w=8u   l=20u
 m22 9   5  0   1 enh   w=100u   l=5u
 m24 3   14  18   1 dep   w=8u   l=20u
 m25 22   11  20   1 enh   w=20u   l=5u
 m26 3   13  19   1 dep   w=8u   l=20u
 m27 20   21  0   1 enh   w=50u   l=5u
 m28 3   3  23   1 enh   w=50u   l=5u
 m29 3   3  22   1 enh   w=50u   l=5u
 m30 24   21  0   1 enh   w=50u   l=5u
 m31 14   22  24   1 enh   w=20u   l=5u
 r0  9  3   10k
 r11 6  7   6k
 r12 7  3   6k
 r13 6  0   6k
 c8  9  0   100p
 c17 11  0   .1p
 c23 5  0   .5p
 .model enh nmos(level=3 vto=.80 phi=.75 kp=3.6e-5 gamma=.346
 +               tox=6.5e-8 nsub=5e15 xj=5e-7 ld=9.5e-7 uo=600
 +               vmax=195000 delta=1.35 theta=0.15 eta=.40 kappa=00
 +               nfs=0 xqc=0.3)
 .model dep nmos(level=3 vto=-3.5 phi=.75 kp=3.80e-5 gamma=.368
 +               tox=6.5e-8 nsub=8e15 xj=5e-7 ld=9.2e-7 uo=500
 +               vmax=124000 delta=1.5 theta=0.0 eta=.35 kappa=.1
 +               nfs=0 xqc=0.3)

 .print dc v(5) v(11) v(14)
 .plot dc v(9) v(5) v(11) v(14)
 .plot tran v(9) v(5) v(11) v(14)
 *** v(9) := osc
 *** v(5) := sense
 *** v(11) := thres
 *** v(14) := xsig12

 .end

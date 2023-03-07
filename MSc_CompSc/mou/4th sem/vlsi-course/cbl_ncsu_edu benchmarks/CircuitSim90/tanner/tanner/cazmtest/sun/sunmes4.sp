34 bit adder simulation 900920v10

* @(#)models	1.2 11/19/90
*
* These models were derived from files "models" and "skew.parameters"
* in the typical-typical case.  Parameters not needed by CAzM were
* deleted.
*
* Hspice's models were based on:
*	+ Meta-Software's variable saturation model (SAT=3)
*	+ Charge conserving, symmetric capacitor model (CAPOP=1)
*	+ Physically based method for area calculation (ACM=1)
*
* CAzM models are based on:
*	+ Statz model (SAT=2)
*	+ Artificial charge splitting capacitor model
*	+ SPICE method for area calculation (ACM=0)
*
* Created: 11/20/90 ryu
*

.model jfet15 njf
+ vto=-0.479 beta=2.72e-04 is=3.88e-14 alpha=3.94 lambda=0.127 rs=0 rd=0
+ pb=0.8 

.model jfet16 njf
+ vto=-0.896 beta=3.08e-04 is=7.66e-14 alpha=3.91 lambda=0.037 rs=0 rd=0
+ pb=0.8

.model jfet19 njf
+ vto=-0.819 beta=2.83e-04 is=1.10e-13 alpha=3.51 lambda=0.083 rs=0 rd=0
+ pb=0.8

.model jfet20 njf
+ vto=-0.798 beta=3.14e-04 is=3.88e-14 alpha=3.94 lambda=0.127 rs=0 rd=0
+ pb=0.8

.model jfet04 njf
+ vto=0.267 beta=3.56e-04 is=1.02e-14 alpha=6.53 lambda=0.072 rs=0 rd=0
+ pb=0.8

.model jfet10 njf
+ vto=0.276 beta=3.78e-04 is=1.10e-14 alpha=6.28 lambda=0.091 rs=0 rd=0
+ pb=0.8
*
*
*
*.include '34_bit_all_core'
*************************************************************
* Run Control Statements
*************************************************************
*vcin cin 0 pulse(.6 .1 200ps 200ps 200ps 2 4)
vcin cin 0 pwl(0 .6 0.2ns .1 1ns .1 1.2ns .6 2ns .6 2.2ns .1 3ns .1
+ 3.2ns .6 4.0ns .6 4.2ns .1 5.0ns .1
+ 5.2ns .6 6.0ns .6 6.2ns .1 7.0ns .1
+ 7.2ns .6 8.0ns .6 8.2ns .1 9.0ns .1
+ 9.2ns .6 10.0ns .6 10.2ns .1 11.0ns .1)
.tran 100ps 15ns
.print tran v(cin) v(s0) v(s1) v(s2) v(s3) v(s4) v(s5) v(s6) 
.options  limpts=10000 method=gear  maxord=2  dcon=1 abstol=1.0e-10
.temp 25

*.width out=80
*.alter
*vcin cin 0 pulse(.1 .6 200ps 200ps 200ps 2 4)
*.alter
*vcc vcc 0 2.2
*.alter
*vcin cin 0 pulse(.6 .1 200ps 200ps 200ps 2 4)
*
*	34_bit_all_core
*
*
*
.subckt not_gate out in vcc vbg GND1
j1 vcc out out vbg jfet19 w=1.7u l=2.4u
j2 out  in   GND1 vbg jfet04 w=6.2u l=1u
cg1 out GND1 3.2ff
cg2 in  GND1 2.5ff
.ends
.subckt not_gate19 out in vcc vbg GND1
j1 vcc out out vbg jfet19 w=1.7u l=2.4u m=19
j2 out  in   GND1 vbg jfet04 w=6.2u l=1u m=19
cg1 out GND1 3.2ff
cg2 in  GND1 2.5ff
.ends
.subckt not_gate8 out in vcc vbg GND1
j1 vcc out out vbg jfet19 w=1.7u l=2.4u m=8
j2 out  in   GND1 vbg jfet04 w=6.2u l=1u m=8
cg1 out GND1 3.2ff
cg2 in  GND1 2.5ff
.ends
.subckt not_h_gate out in vcc vbg GND1
j1 vcc out out vbg jfet19 w=3.4u l=2.4u
j2 out  in   GND1 vbg jfet04 w=12.4u l=1u
cg1 out GND1 6.3ff
cg2 in  GND1 5.0ff
.ends
.subckt nor2_gate out in1 in2 vcc vbg GND1
j1 vcc out out vbg jfet19 w=1.7u l=2.4u
j2 out in1 GND1   vbg jfet04 w=6.2u l=1u
j3 out in2 GND1   vbg jfet04 w=6.2u l=1u
cg1 out GND1 5.6ff
cg2 in1 GND1 2.5ff
cg3 in2 GND1 2.5ff
.ends
.subckt nor2_gate19 out in1 in2 vcc vbg GND1
j1 vcc out out vbg jfet19 w=1.7u l=2.4u m=19
j2 out in1 GND1   vbg jfet04 w=6.2u l=1u m=19
j3 out in2 GND1   vbg jfet04 w=6.2u l=1u m=19
cg1 out GND1 5.6ff
cg2 in1 GND1 2.5ff
cg3 in2 GND1 2.5ff
.ends
.subckt nor2_gate8 out in1 in2 vcc vbg GND1
j1 vcc out out vbg jfet19 w=1.7u l=2.4u m=8
j2 out in1 GND1   vbg jfet04 w=6.2u l=1u m=8
j3 out in2 GND1   vbg jfet04 w=6.2u l=1u m=8
cg1 out GND1 5.6ff
cg2 in1 GND1 2.5ff
cg3 in2 GND1 2.5ff
.ends
.subckt nor2_h_gate out in1 in2 vcc vbg GND1
j1 vcc out out vbg jfet19 w=6.8u l=2.4u 
j2 out in1 GND1   vbg jfet04 w=24.8u l=1u 
j3 out in2 GND1   vbg jfet04 w=24.8u l=1u 
cg1 out GND1 22.6ff
cg2 in1 GND1 9.9ff
cg3 in2 GND1 9.9ff 
.ends
.subckt nor3_gate out in1 in2 in3 vcc vbg GND1
j1 vcc out out vbg jfet19 w=1.7u l=2.4u
j2 out in1 GND1   vbg jfet04 w=6.2u l=1u
j3 out in2 GND1   vbg jfet04 w=6.2u l=1u
j4 out in3 GND1   vbg jfet04 w=6.2u l=1u
cg1 out GND1 8.1ff
cg2 in1 GND1 2.5ff
cg3 in2 GND1 2.5ff
cg4 in3 GND1 2.5ff
.ends
.subckt nor4_gate out in1 in2 in3 in4 vcc vbg GND1
j1 vcc out out vbg jfet19 w=1.7u l=2.4u 
j2 out in1 GND1   vbg jfet04 w=6.2u l=1u 
j3 out in2 GND1   vbg jfet04 w=6.2u l=1u 
j4 out in3 GND1   vbg jfet04 w=6.2u l=1u
j5 out in4 GND1   vbg jfet04 w=6.2u l=1u
cg1 out GND1 10.6ff
cg2 in1 GND1  2.5ff
cg3 in2 GND1  2.5ff
cg4 in3 GND1  2.5ff
cg5 in4 GND1  2.5ff
.ends
.subckt nor4_h_gate out in1 in2 in3 in4 vcc vbg GND1
j1 vcc out out vbg jfet19 w=3.4u l=2.4u
j2 out in1 GND1   vbg jfet04 w=12.4u l=1u
j3 out in2 GND1   vbg jfet04 w=12.4u l=1u
j4 out in3 GND1   vbg jfet04 w=12.4u l=1u
j5 out in4 GND1   vbg jfet04 w=12.4u l=1u
cg1 out GND1 21.2ff
cg2 in1 GND1  5.0ff
cg3 in2 GND1  5.0ff
cg4 in3 GND1  5.0ff
cg5 in4 GND1  5.0ff
.ends
.subckt nor5_gate out in1 in2 in3 in4 in5 vcc vbg GND1
j1 vcc out out vbg jfet19 w=3.4u l=2.4u
j2 out in1 GND1   vbg jfet04 w=12.4u l=1u
j3 out in2 GND1   vbg jfet04 w=12.4u l=1u
j4 out in3 GND1   vbg jfet04 w=12.4u l=1u
j5 out in4 GND1   vbg jfet04 w=12.4u l=1u
j6 out in5 GND1   vbg jfet04 w=12.4u l=1u
cg1 out GND1 26.2ff
cg2 in1 GND1  5ff
cg3 in2 GND1  5ff
cg4 in3 GND1  5ff
cg5 in4 GND1  5ff
cg6 in5 GND1  5ff
.ends
.subckt bdcfl3_gate out in vcc vbg GND1
j1 vcc in out vbg jfet04 w=35u l=1u
j2 out GND1  GND1   vbg jfet19 w=7u  l=2.4u
cg1 in  GND1 14ff
cg2 out GND1 16.8ff
.ends
.subckt bdcfl2_gate out in vcc vbg GND1
j1 vcc in out vbg jfet04 w=105u l=1u
j2 out GND1  GND1   vbg jfet19 w=21u  l=2.4u
cg1 in  GND1 42ff
cg2 out GND1 50.4ff
.ends
.subckt and_gate out in1 in2 vcc vbg GND1
j1 in2 in1 out vbg jfet04 w=6.2u l=1u
j2 out GND1   GND1   vbg jfet19 w=2.2u l=2.4u
cg1d in2 GND1 2.5ff
cg1g in1 GND1 2.5ff
cg2  out GND1 3.4ff
.ends
.subckt and_gate19 out in1 in2 vcc vbg GND1
j1 in2 in1 out vbg jfet04 w=6.2u l=1u m=19
j2 out GND1   GND1   vbg jfet19 w=2.2u l=2.4u m=19
cg1d in2 GND1 2.5ff
cg1g in1 GND1 2.5ff
cg2  out GND1 3.4ff
.ends
.subckt and_gate8 out in1 in2 vcc vbg GND1
j1 in2 in1 out vbg jfet04 w=6.2u l=1u m=8
j2 out GND1   GND1   vbg jfet19 w=2.2u l=2.4u m=8
cg1d in2 GND1 2.5ff
cg1g in1 GND1 2.5ff
cg2  out GND1 3.4ff
.ends
.subckt and_gate2 out in1 in2 vcc vbg GND1
j1 in2 in1 out vbg jfet04 w=6.2u l=1u m=2
j2 out GND1   GND1   vbg jfet19 w=2.2u l=2.4u m=2
cg1d in2 GND1 2.5ff
cg1g in1 GND1 2.5ff
cg2  out GND1 3.4ff
.ends
.subckt not_special_gate out in vcc vbg GND1
x_out1g out1 in1 in vcc vbg GND1 and_gate
x_outg out out1 vcc vbg GND1 not_gate
j1 vcc in1 in1 vbg jfet19 w=1.7u l=2.4u
cin1 in1 GND1 .7ff
.ends
.subckt eigthbitadder s7 s6 s5 s4 s3 s2 s1 s0 c7 c7b a7 a6 a5
+ a4 a3 a2 a1 a0 b7 b6 b5 b4 b3 b2 b1 b0 cin vcc vbg GND1
*not #1
x_cinb_andg cinb_and cin vcc vbg GND1 not_gate
x_cinbg cinb cin vcc vbg GND1 not_gate
x_a0bg a0b a0 vcc vbg GND1 not_gate
x_a1bg a1b a1 vcc vbg GND1 not_gate
x_a2bg a2b a2 vcc vbg GND1 not_gate
x_a3bg a3b a3 vcc vbg GND1 not_gate
x_a4bg a4b a4 vcc vbg GND1 not_gate
x_a5bg a5b a5 vcc vbg GND1 not_gate
x_a6bg a6b a6 vcc vbg GND1 not_gate
x_a7bg a7b a7 vcc vbg GND1 not_gate
*
x_b0bg b0b b0 vcc vbg GND1 not_gate
x_b1bg b1b b1 vcc vbg GND1 not_gate
x_b2bg b2b b2 vcc vbg GND1 not_gate
x_b3bg b3b b3 vcc vbg GND1 not_gate
x_b4bg b4b b4 vcc vbg GND1 not_gate
x_b5bg b5b b5 vcc vbg GND1 not_gate
x_b6bg b6b b6 vcc vbg GND1 not_gate
x_b7bg b7b b7 vcc vbg GND1 not_gate
*
*nor #1
x_p0bg p0b a0 b0 vcc vbg GND1 nor2_gate
x_p1bg p1b a1 b1 vcc vbg GND1 nor2_gate
x_p1bag p1ba a1 b1 vcc vbg GND1 nor2_gate
x_p2bg p2b a2 b2 vcc vbg GND1 nor2_gate
x_p3bg p3b a3 b3 vcc vbg GND1 nor2_gate
x_p4bg p4b a4 b4 vcc vbg GND1 nor2_gate
x_p5bg p5b a5 b5 vcc vbg GND1 nor2_gate
x_p6bg p6b a6 b6 vcc vbg GND1 nor2_gate
x_p7bg p7b a7 b7 vcc vbg GND1 nor2_gate
*
x_n0b_andg n0b_and a0b b0b vcc vbg GND1 nor2_gate
x_n0bg n0b a0b b0b vcc vbg GND1 nor2_gate
x_n1b_andg n1b_and a1b b1b vcc vbg GND1 nor2_gate
x_n1bg n1b a1b b1b vcc vbg GND1 nor2_gate
x_n2b_andg n2b_and a2b b2b vcc vbg GND1 nor2_gate
x_n2bg n2b a2b b2b vcc vbg GND1 nor2_gate
x_n3bg n3b a3b b3b vcc vbg GND1 nor2_gate
x_n4bg n4b a4b b4b vcc vbg GND1 nor2_gate
x_n5b_andg n5b_and a5b b5b vcc vbg GND1 nor2_gate
x_n5bg n5b a5b b5b vcc vbg GND1 nor2_gate
x_n6b_andg n6b_and a6b b6b vcc vbg GND1 nor2_gate
x_n6bg n6b a6b b6b vcc vbg GND1 nor2_gate
x_n7bg n7b a7b b7b vcc vbg GND1 nor2_gate
*
x_s0g s0 a0bb0bcinb a0bb0cin a0b0cinb a0b0bcin vcc vbg GND1 nor4_gate
x_s1g s1 a1bb1bc0b a1bb1c0 a1b1c0b a1b1bc0 vcc vbg GND1 nor4_gate
x_s2g s2 a2bb2bc1b a2bb2c1 a2b2c1b a2b2bc1 vcc vbg GND1 nor4_gate
x_s3g s3 a3bb3bc2b a3bb3c2 a3b3c2b a3b3bc2 vcc vbg GND1 nor4_gate
x_s4g s4 a4bb4bc3b a4bb4c3 a4b4c3b a4b4bc3 vcc vbg GND1 nor4_gate
x_s5g s5 a5bb5bc4b a5bb5c4 a5b5c4b a5b5bc4 vcc vbg GND1 nor4_gate
x_s6g s6 a6bb6bc5b a6bb6c5 a6b6c5b a6b6bc5 vcc vbg GND1 nor4_gate
x_s7g s7 a7bb7bc6b a7bb7c6 a7b7c6b a7b7bc6 vcc vbg GND1 nor4_gate
*
x_a0bb0bcinbg a0bb0bcinb a0 b0 cin vcc vbg GND1 nor3_gate
x_a1bb1bc0bg a1bb1bc0b a1 b1 c0 vcc vbg GND1 nor3_gate
x_a2bb2bc1bg a2bb2bc1b a2 b2 c1 vcc vbg GND1 nor3_gate
x_a3bb3bc2bg a3bb3bc2b a3 b3 c2 vcc vbg GND1 nor3_gate
x_a4bb4bc3bg a4bb4bc3b a4 b4 c3 vcc vbg GND1 nor3_gate
x_a5bb5bc4bg a5bb5bc4b a5 b5 c4 vcc vbg GND1 nor3_gate
x_a6bb6bc5bg a6bb6bc5b a6 b6 c5 vcc vbg GND1 nor3_gate
x_a7bb7bc6bg a7bb7bc6b a7 b7 c6 vcc vbg GND1 nor3_gate
* 
x_a0bb0cing a0bb0cin a0 b0b cinb vcc vbg GND1 nor3_gate
x_a1bb1c0g a1bb1c0 a1 b1b c0b vcc vbg GND1 nor3_gate
x_a2bb2c1g a2bb2c1 a2 b2b c1b vcc vbg GND1 nor3_gate
x_a3bb3c2g a3bb3c2 a3 b3b c2b vcc vbg GND1 nor3_gate
x_a4bb4c3g a4bb4c3 a4 b4b c3b vcc vbg GND1 nor3_gate
x_a5bb5c4g a5bb5c4 a5 b5b c4b vcc vbg GND1 nor3_gate
x_a6bb6c5g a6bb6c5 a6 b6b c5b vcc vbg GND1 nor3_gate
x_a7bb7c6g a7bb7c6 a7 b7b c6b vcc vbg GND1 nor3_gate
* 
x_a0b0cinbg a0b0cinb a0b b0b cin vcc vbg GND1 nor3_gate
x_a1b1c0bg a1b1c0b a1b b1b c0 vcc vbg GND1 nor3_gate
x_a2b2c1bg a2b2c1b a2b b2b c1 vcc vbg GND1 nor3_gate
x_a3b3c2bg a3b3c2b a3b b3b c2 vcc vbg GND1 nor3_gate
x_a4b4c3bg a4b4c3b a4b b4b c3 vcc vbg GND1 nor3_gate
x_a5b5c4bg a5b5c4b a5b b5b c4 vcc vbg GND1 nor3_gate
x_a6b6c5bg a6b6c5b a6b b6b c5 vcc vbg GND1 nor3_gate
x_a7b7c6bg a7b7c6b a7b b7b c6 vcc vbg GND1 nor3_gate
* 
x_a0b0bcing a0b0bcin a0b b0 cinb vcc vbg GND1 nor3_gate
x_a1b1bc0g a1b1bc0 a1b b1 c0b vcc vbg GND1 nor3_gate
x_a2b2bc1g a2b2bc1 a2b b2 c1b vcc vbg GND1 nor3_gate
x_a3b3bc2g a3b3bc2 a3b b3 c2b vcc vbg GND1 nor3_gate
x_a4b4bc3g a4b4bc3 a4b b4 c3b vcc vbg GND1 nor3_gate
x_a5b5bc4g a5b5bc4 a5b b5 c4b vcc vbg GND1 nor3_gate
x_a6b6bc5g a6b6bc5 a6b b6 c5b vcc vbg GND1 nor3_gate
x_a7b7bc6g a7b7bc6 a7b b7 c6b vcc vbg GND1 nor3_gate
* 
x_p0to3g p0to3 p0b p1b p2b p3b vcc vbg GND1 nor4_gate
x_p2to3g p2to3 p2b p3b vcc vbg GND1 nor2_gate
x_p4to5g p4to5 p4b p5b vcc vbg GND1 nor2_gate
x_p6to7g p6to7 p6b p7b vcc vbg GND1 nor2_gate
*
x_n1to2g n1to2 n1b n2b vcc vbg GND1 nor2_gate
x_n4to5g n4to5 n4b n5b vcc vbg GND1 nor2_gate
x_k4to5g k4to5 n5b p4to5 vcc vbg GND1 nor2_gate
* 
x_c7g c7 k4to7 n4to7k0to3 vcc vbg GND1 nor2_gate
x_c7cg c7c k4to7 n4to7k0to3 vcc vbg GND1 nor2_gate
x_c6g c6 k4to6 n4to6k0to3 vcc vbg GND1 nor2_gate
x_c5g c5 k4to5 n4to5k0to3 vcc vbg GND1 nor2_gate
x_c4g c4 p4b n4k0to3 vcc vbg GND1 nor2_gate
x_c2g c2 p2b n2k1 n1to2c0b vcc vbg GND1 nor3_gate
x_c1g c1 p1b n1c0b vcc vbg GND1 nor2_gate
x_c0g c0 p0b n0cinb vcc vbg GND1 nor2_gate
*
x_c7bg c7b c7c vcc vbg GND1 not_h_gate
* 
x_k4to7g k4to7 n7b p7g6 p6to7g5 p4to7 vcc vbg GND1 nor4_gate
x_k4to6g k4to6 n6b p6g5 p4to6 vcc vbg GND1 nor3_gate
x_k0to3ig k0to3i n3b p3g2 p0to3cin p2to3g1 p1to3g0 vcc vbg GND1 nor5_gate
*
x_k0to3g k0to3 k0to3i vcc vbg GND1 bdcfl3_gate
* 
x_p4to7g p4to7 p4b p5b p6b p7b vcc vbg GND1 nor4_gate
x_p4to6g p4to6 p4b p5b p6b vcc vbg GND1 nor3_gate
x_p1to3g p1to3 p1b p2b p3b vcc vbg GND1 nor3_gate
* 
x_n4to7g n4to7 n4b n5b n6b n7b vcc vbg GND1 nor4_h_gate
x_n4to6g n4to6 n4b n5b n6b vcc vbg GND1 nor3_gate
*
*buf #0
*	g0 to g3, g5 to g7, k0 to k2 and k4 are replaced by their
*	equivalent wherever they appear as nodes.  They are b replaced
*	if they merely appear as part of a longer name.
*
*        g0buf(g0, n0b),
*        g1buf(g1, n1b),
*        g2buf(g2, n2b),
*        g3buf(g3, n3b),
*        g5buf(g5, n5b),
*        g6buf(g6, n6b),
*        g7buf(g7, n7b),
* 
*        k0buf(k0, p0b),
*        k1buf(k1, p1b),
*        k2buf(k2, p2b),
*        k4buf(k4, p4b);
* 
*not #1
x_c0b_andg c0b_and c0 vcc vbg GND1 not_h_gate
x_c0bg c0b c0 vcc vbg GND1 not_gate
x_c1bg c1b c1 vcc vbg GND1 not_gate
x_c2bg c2b c2 vcc vbg GND1 not_gate
x_c3bg c3b c3 vcc vbg GND1 not_gate
x_c4bg c4b c4 vcc vbg GND1 not_gate
x_c5bg c5b c5 vcc vbg GND1 not_gate
x_c6bg c6b c6 vcc vbg GND1 not_gate
* 
x_p3g p3 p3b vcc vbg GND1 not_gate
x_p6g p6 p6b vcc vbg GND1 not_gate
x_p7g p7 p7b vcc vbg GND1 not_gate
x_n0g n0 n0b vcc vbg GND1 not_gate
x_n1g n1 n1b vcc vbg GND1 not_gate
x_n2g n2 n2b vcc vbg GND1 not_gate
x_n4g n4 n4b vcc vbg GND1 not_gate
*
x_c3g c3 k0to3 vcc vbg GND1 not_special_gate
*
*and #1
x_n4to7k0to3g n4to7k0to3 n4to7 k0to3 vcc vbg GND1 and_gate2
x_n4to6k0to3g n4to6k0to3 n4to6 k0to3 vcc vbg GND1 and_gate
x_n4to5k0to3g n4to5k0to3 n4to5 k0to3 vcc vbg GND1 and_gate
x_n4k0to3g n4k0to3 n4 k0to3 vcc vbg GND1 and_gate
x_n2k1g n2k1 n2 p1ba vcc vbg GND1 and_gate
x_n1to2c0bg n1to2c0b n1to2 c0b_and vcc vbg GND1 and_gate
x_n1c0bg n1c0b n1 c0b_and vcc vbg GND1 and_gate
x_n0cinbg n0cinb n0 cinb_and vcc vbg GND1 and_gate
*
x_p7g6g p7g6 p7 n6b_and vcc vbg GND1 and_gate
x_p6to7g5g p6to7g5 p6to7 n5b_and vcc vbg GND1 and_gate
x_p6g5g p6g5 p6 n5b_and vcc vbg GND1 and_gate
x_p3g2g p3g2 p3 n2b_and vcc vbg GND1 and_gate
x_p2to3g1g p2to3g1 p2to3 n1b_and vcc vbg GND1 and_gate
x_p1to3g0g p1to3g0 p1to3 n0b_and vcc vbg GND1 and_gate
x_p0to3cing p0to3cin p0to3 cin vcc vbg GND1 and_gate
* 
*endmodule
.ends
.subckt sixteenbitadder c15ncbc7b c15wcbc7 c15ncc7b c15wcc7
+ syy s7 s6 s5 s4 s3 s2 s1 s0
+ ayy a7 a6 a5 a4 a3 a2 a1 a0
+ byy b7 b6 b5 b4 b3 b2 b1 b0
+ cin vcc vbg GND1
*
x_0to7adder s7 s6 s5 s4 s3 s2 s1 s0 c7i c7bi a7 a6 a5
+ a4 a3 a2 a1 a0 b7 b6 b5 b4 b3 b2 b1 b0 cin vcc vbg GND1 eigthbitadder
*
x_syywcbg syywcb syywc vcc vbg GND1 not_gate8
x_syyncbg syyncb syync vcc vbg GND1 not_gate8
x_c15ncbg c15ncb c15nc vcc vbg GND1 not_gate
x_c15ncg c15nc ayyb byyb vcc vbg GND1 nor2_gate
*
x_c15nc_andg c15nc_and ayyb byyb vcc vbg GND1 nor2_gate
x_c15wcb_andg c15wcb_and ayy byy vcc vbg GND1 nor2_gate
*
*	The two statements above are added 11/21/90.
*
x_c15wcg c15wc c15wcb vcc vbg GND1 not_gate
x_c15wcbg c15wcb ayy byy vcc vbg GND1 nor2_gate
*
*and #1
*
x_syyncbc7bg syyncbc7b syyncb c7b vcc vbg GND1 and_gate8
*
x_c15ncbc7bg c15ncbc7b c15ncb c7b vcc vbg GND1 and_gate
x_c15ncc7bg  c15ncc7b  c15nc_and  c7b vcc vbg GND1 and_gate
*
x_syywcbc7g syywcbc7 syywcb c7 vcc vbg GND1 and_gate8
*
x_c15wcbc7g c15wcbc7 c15wcb_and c7 vcc vbg GND1 and_gate
x_c15wcc7g  c15wcc7  c15wc  c7 vcc vbg GND1 and_gate
*
*nor #1
x_syyg syy s8ncbc7b s8wcbc7 vcc vbg GND1 nor2_gate
x_syywcg syywc abnotyy vcc vbg GND1 not_gate8
x_syyncg syync anorbyy vcc vbg GND1 not_gate8
x_abnotyyg abnotyy ayyb byy vcc vbg GND1 nor2_gate8
x_anorbyyg anorbyy ayy byy vcc vbg GND1 nor2_gate8
x_ayybg ayyb ayy vcc vbg GND1 not_gate8
x_byybg byyb byy vcc vbg GND1 not_gate8
*
x_c7bg c7b c7bi vcc vbg GND1 bdcfl3_gate
x_c7g c7 c7i vcc vbg GND1 bdcfl3_gate
*
*endmodule
*
.ends
*
*
*       Dummy load for outputs s0 to s15 and szz
*
j0 vcca s0 GND1 vbg jfet04 w=6.2u l=1u
j1 vcca s1 GND1 vbg jfet04 w=6.2u l=1u
j2 vcca s2 GND1 vbg jfet04 w=6.2u l=1u
j3 vcca s3 GND1 vbg jfet04 w=6.2u l=1u
j4 vcca s4 GND1 vbg jfet04 w=6.2u l=1u
j5 vcca s5 GND1 vbg jfet04 w=6.2u l=1u
j6 vcca s6 GND1 vbg jfet04 w=6.2u l=1u
j7 vcca s7 GND1 vbg jfet04 w=6.2u l=1u
jyy vcca syy GND1 vbg jfet04 w=6.2u l=1u m=8
jzz vcca szz GND1 vbg jfet04 w=6.2u l=1u m=19
j33 vcca c33 GND1 vbg jfet04 w=6.2u l=1u
*
x_szzwcg szzwc abnotzz vcc vbg GND1 not_gate19
x_szzncg szznc anorbzz vcc vbg GND1 not_gate19
*
x_abnotzzg abnotzz azzb bzz vcc vbg GND1 nor2_gate19
x_anorbzzg anorbzz azz  bzz vcc vbg GND1 nor2_gate19
*
x_0to15adder c15inor1 c15inor2 c15binor1 c15binor2
+ syy s7 s6 s5 s4 s3 s2 s1 s0
+ ayy ai ai ai ai ai ai ai ai
+ byy bi bi bi bi bi bi bi bi
+ cin vcc vbg GND1 sixteenbitadder
*
x_c15ig c15i c15inor1 c15inor2 vcc vbg GND1 nor2_h_gate
x_c15big c15bi c15binor1 c15binor2 vcc vbg GND1 nor2_h_gate
*
*
x_azzbg azzb azz vcc vbg GND1 not_gate19
x_bzzbg bzzb bzz vcc vbg GND1 not_gate
*
x_c15g c15 c15i vcc vbg GND1 bdcfl2_gate
x_c15bg c15b c15bi vcc vbg GND1 bdcfl2_gate
*
x_szzwcbg szzwcb szzwc vcc vbg GND1 not_gate19
x_szzncbg szzncb szznc vcc vbg GND1 not_gate19
* 
*
x_c33ncbc15bg c33ncbc15b c33ncb c15b vcc vbg GND1 and_gate
x_c33wcbc15g c33wcbc15 c33wcb c15 vcc vbg GND1 and_gate
x_c33g c33 c33ncbc15b c33wcbc15 vcc vbg GND1 nor2_gate
*
x_szzncbc15bg szzncbc15b szzncb c15b vcc vbg GND1 and_gate19
x_szzwcbc15g  szzwcbc15  szzwcb c15  vcc vbg GND1 and_gate19
*
x_gzzg gzz azzb bzzb vcc vbg GND1 nor2_gate
*
*
x_c33wcbg c33wcb azz bzz vcc vbg GND1 nor2_gate
x_c33ncbg c33ncb gzz vcc vbg GND1 not_gate
x_szzg    szz    szzncbc15b szzwcbc15 vcc vbg GND1 nor2_gate19
*
*endmodule
*
*
*************************************************************
*	Voltage Sources
*************************************************************
vGND1 GND1 0 0
vcc vcc GND1 1.8v
vcca vcca GND1 2v
vbg vbg GND1 0.5v
rbg vbg GND1 10k
*
vai  ai  GND1 .6
vazz azz GND1 .6
vayy ayy GND1 .6
*
vbi  bi  GND1 .1
vbzz bzz GND1 .1
vbyy byy GND1 .1
*	end of 34_bit_all_core
*	end of 34_bit_all_core
*

.end

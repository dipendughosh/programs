
.MODEL QNL NPN BF=80 RB=100 TF=0.3N TR=6N CJE=3P CJC=2P VAF=50
+ cjs=2.0e-12 

Rc 1 3 10
Rb 2 4 10
Re 6 7 10
Rs 8 9 10

Q1 3 4 6 8 QNL

Vee 7 0 0.0
Vss 9 0 10.0
Vcc 1 0 5.0
Vin 2 0 0.0 AC 0.3 0.0
.ac lin 10 10 1000
.print ac ir(Vin) ii(Vin)
.op
.end





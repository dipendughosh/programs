
.MODEL QNL NPN BF=80 RB=100 TF=0.3N TR=6N CJE=3P CJC=2P VAF=50

Rc 1 3 1000
Rb 2 4 100
Re 6 7 1
Rs 8 9 1

Q1 3 4 6 8 QNL

Vee 7 0 0.0
Vss 9 0 0.0
Vcc 1 0 5.0
Vin 2 0 .8 AC 0.3 90.0
.ac lin 100 10MEG 1000MEG
.print ac ir(Vcc) ii(Vcc)
.options limpts=10000
.end




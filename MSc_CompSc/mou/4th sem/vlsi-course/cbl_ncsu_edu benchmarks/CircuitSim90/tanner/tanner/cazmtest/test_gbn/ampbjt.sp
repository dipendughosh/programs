
.MODEL QNL NPN BF=80 RB=100 TF=0.3N TR=6N CJE=3P CJC=2P VAF=50

Rc 1 3 1000
Rb 2 4 100
Q1 3 4 0 0 QNL


Vcc 1 0 13.0
*Vin 2 0 .8 AC 0.3 45.0
*wave in sin amp=0.3 freq=50000000 offset=.8 delay=20.0n
Vin 2 0  SIN(0.8 0.3 50000000 20NS 0.0)
.options limpts=10000
.tran .1ns 150ns
.print tran v(1) v(4) v(3)
.end







R1 1 0 20K
R2 2 0 20K
R3 3 0 20K
R4 4 0 20K
R5 5 0 20K
R6 6 0 20K
R7 7 0 20K
R8 8 0 20K
R9 9 0 20K
R10 10 0 20K
R11 11 0 20K
R12 12 0 20K


vpulse 8 0 PULSE (.2 1.2)
vpulse2 9 0 PULSE (.2 1.2 0NS 2NS 2NS)
vpulse3 6 0 PULSE (.2 1.2 0NS 2NS 2NS 50NS 100NS )
vpulse4 10 0 PULSE (.2 1.2 0NS 2NS 2NS 50NS 100NS )
vpulse5 1 0 PULSE (.2 1.2 2NS 2NS 2NS 50NS 50NS )

vsin 7 0 SIN(0 1.0 ) 
vsin2 2 0 SIN(0 1.0 100MEG 10ns 1E7) 

vexp 3 0 EXP(0 1.0 ) 
vexp2 12 0 EXP(0 1.0 2ns 30NS 60ns 40ns) 

vsffm 11 0 SFFM(0 1.0 ) 
vsffm2 4 0 SFFM(0 1.0 10MEG 3 8MEG ) 

vpwl 5 0 PWL(0ns 0 2ns 0 4ns 5 8ns 5 10ns 0 40ns 0)


.options limpts=10000
.tran .5n 200ns 
.print tran v(11) v(12) v(7) v(8) v(9) v(6) v(10) v(1) v(2) v(3) v(4) v(5) 
.end

4/3 n-channel level 2, gate capacitor circuit
*                          
*define libraries
* 
*.libs ps0e0n.lv2
*
* define models                                                                
*.model nn4a lib


.model nn4a nmos(
+ vto    =  8.80917e-1
+ uo     =  6.47721e+2
+ nsub   =  5.92489e+16
+ ucrit  =  1.71094e+5
+ uexp   =  4.05602e-1
+ vmax   =  9.59195e+4
+ neff   =  7.72162e-1
+ tox    =  4.50000e-8
+ xj     =  6.00000e-7
+ tpg    =  1.00000e+0
+ js     =  1.00000e-7
+ cj     =  4.00000e-4
+ pb     =  9.20000e-1
+ rd     =  4.73958e+0
+ rs     =  4.73958e+0
+ level  =  2)
* seq. #:   25 process: b3908an 3123 wafer: 19 loc: 13; 87 date: 14may82


*                                                                              
c1   3 0 1.pf
*
m123 3 2 3 4    nn4a  l=3u w=16u  
*                                                                              
* biasing conditions                                                           
vbb 4 0 dc 0.
vin 2 0 pulse(0 5 0n 5n 5n 5n 20ns)
*                                                                              
.op
.option limpts=10000, node, opts, lvltim=1 itl5=0 cptime=5000


.tr 1n 200n
.plot tran v(2) v(3)
*                                                                              
* that's all folks                                                             
.end                                                                           

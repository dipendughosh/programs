charge pump circuit from pacsim manual
*
* nominal 1 micron model 0e0 at 25c level 3
.model nmod nmos(
+ vto    =  1.25000e+0
+ uo     =  4.46165e+2
+ nsub   =  2.62626e+17
+ nfs    =  1.53239e+12
+ kappa  =  2.00000e-2
+ theta  =  6.51301e-2
+ vmax   =  1.54382e+5
+ eta    =  2.11645e-1
+ tox    =  2.00000e-8
+ xj     =  3.00000e-7
+ tpg    =  1.00000e+0
+ cj     =  1.48623e-3
+ pb     =  9.93752e-1
+ js     =  4.62000e-6
+ rsh    =  65.0000e+0
+ level  =  3)
* seq no:     1    21257  w8  d6  1.25/16-n  25c
*
c1   3  4 .5pf
c2   1  4 .5pf
*
m123 1 2 3 5    nmod  l=1.25u w=16u  
*                                                                              
* biasing conditions                                                           
vgg 4 0 dc 5.
vin 2 0 pulse(0  5 0n 2n 2n 5n 10ns)
vbb 5 0 dc -3.
*                                                                              
.op
.option limpts=10000, node, opts, chgtol=1e-18
.tr .4n 200n
.print tran v(2) v(3)
*                                                                              
* that's all folks                                                             
.end                                                                           

* This file contains several transistors, each turned OFF,
* whose drains will act simply as capacitive loads for simple
* RC networks.  The transistors were extracted from magic
* layouts, and the area/perimeters were figured by ext2spice.

m0 8 1 1 1 pfet l=1.60u w=160.00u ad=576.00p as=576.00p pd=327.20u 
+ ps=332.34u nrd=0.02 nrs=0.02
m1 7 1 1 1 pfet l=1.60u w=80.00u ad=288.00p as=288.00p pd=167.20u 
+ ps=166.17u nrd=0.05 nrs=0.05
m2 6 1 1 1 pfet l=1.60u w=40.00u ad=144.00p as=144.00p pd=87.20u 
+ ps=83.09u nrd=0.09 nrs=0.09
m3 0 0 5 0 nfet l=1.60u w=160.00u ad=576.00p as=576.00p pd=332.34u 
+ ps=327.20u nrd=0.02 nrs=0.02
m4 0 0 4 0 nfet l=1.60u w=80.00u ad=288.00p as=288.00p pd=166.17u 
+ ps=167.20u nrd=0.05 nrs=0.05
m5 0 0 3 0 nfet l=1.60u w=40.00u ad=144.00p as=144.00p pd=83.09u 
+ ps=87.20u nrd=0.09 nrs=0.09

r1 2 30 1k
r2 2 40 1k
r3 2 50 1k
r4 2 60 1k
r5 2 70 1k
r6 2 80 1k

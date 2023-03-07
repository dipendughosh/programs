volt Vdd 5.0v
* Initially setting value of FF's to 1
* to observe carry delay

ic{int4=5.0v out=0.0v int1=5.0v int2=5.0v int3=0.0v}

plot { int4 out int1 int2 int3 }

temp 75
transient 4000000ns 

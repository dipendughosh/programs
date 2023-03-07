
wave set bit { (100(0)100(1)) 
             3(5(0)5(1)) 3(4(0)4(1)) 3(3(0)3(1))
             3(2(0)2(1)) 
             }pw=.4n rt=.1n ft=.1n
plot {in  out}
options chargetol=5.0e-16
transient 600n 
 

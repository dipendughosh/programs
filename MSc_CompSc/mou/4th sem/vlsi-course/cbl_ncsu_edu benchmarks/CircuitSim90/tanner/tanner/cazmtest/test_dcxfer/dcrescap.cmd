

volt n1 GND 6v
dcg { n2 = 5v n3 = 1v }
plot { n1 n2 n3 n4 i(GND,n1) i(n1,n2) i(n2,n3) i(n3,n4) i(n3,GND) i(n4,GND)}
plot {  q(GND,n1) q(n1,n2) q(n2,n3) q(n3,n4) q(n3,GND) q(n4,GND)}
dcoppt


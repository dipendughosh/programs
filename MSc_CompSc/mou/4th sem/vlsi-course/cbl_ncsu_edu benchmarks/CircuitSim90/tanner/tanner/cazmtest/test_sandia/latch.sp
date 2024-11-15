*static latch\\ic=1ma\\re6=3k\\1-7-80
***   resistors
ree2 9 0 200
rcc2 6 8 3.33k
***   transistors
q1 6 8 4 npn1
q2 8 4 9 npn1
***   models
.model npn1 npn(bf=50 br=0.2 rb=81 rc=100 re=6.1 ccs=0.3pf tf=0.36ns 
+tr=10ns cje=0.13pf cjc=0.1pf is=1e-16 ne=1 nc=1.082 pe=0.84v 
+pc=1.1v me=0.36 mc=0.76 va=50v eg=1.1)
***   sources
vcc 6 0 5v
vref 3 0 2.5v
vrset 1 0 pulse(0v 3v 1ns 1ns 1ns 10ns 40ns)
vset 7 0 pulse(0v 3v 20ns 1ns 1ns 10ns 40ns)
***   subcircuits
.subckt eclg2 1 2 3 4 5 6
*nodes:  input(1 2) vref(3) bias(4) output(5) vcc(6)
**  resistors
rs 6 11 619
rc2 11 10 900
re4 12 0 200
re6 5 0 6k
**  transistors
q1 9 1 8 npn1
q2 9 2 8 npn1
q3 11 3 8 npn1
q4 8 4 12 npn1
q5 10 10 9 npn1
q6 6 9 5 npn1
.ends eclg2
x1 1 2 3 4 5 6 eclg2
x2 5 7 3 4 2 6 eclg2
***   control cards
*.tran 1ns 75ns
.print tran v(1) v(7) v(5) v(2)
.plot tran v(1) v(7) v(5) v(2)
.options acct node list
*.end

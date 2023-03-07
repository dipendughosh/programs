
*
*  CAZM
*




*cl data 160ns 10
*cl phi1clk 80ns 1000 5.0 0.0
*cl phi2clk 80ns 0010 5.0 0.0
*as data in
*as phi1clk phi1
*as phi2clk phi2
*pl in phi1 phi2 inbar pass1 inbarbar pass2 out 
*pf sim_n_shifter_f
*sl 160n


*temp 85
*wave  in  pie {0n 0 10n 5}
wave  in  bit {10} ph=80n on=5 off=0
wave  phi1  bit {1000} ph=20n on=5 off=0
wave  phi2  bit {0010001} ph=20n on=5 off=0 
plot {in phi1 phi2 inbar pass1 inbarbar pass2 out}
transient 160n 

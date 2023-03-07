lcm([X],1,X).
lcm([X,Y|L1],C,N):- gen_int(N1),
	A1 is N1 mod X, A2 is N1 mod Y,
	A1=0,A2=0,C1 is C-1,
	lcm([N1|L1],C1,N).

   gen_int(1).
gen_int(N):-gen_int(N1), N is N1+1.

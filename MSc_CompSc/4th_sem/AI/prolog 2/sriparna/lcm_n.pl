lcm_n([X],1,X).
lcm_n([X,Y|L],N,Lcm):-
	N1 is N-1,
	gcd(X,Y,G),
	L1 is X*Y/G,
	lcm_n([L1|L],N1,Lcm).
gcd(G,0,G).
gcd(X,Y,G):-
	Y>0,
	Y1 is X mod Y,
	gcd(Y,Y1,G).

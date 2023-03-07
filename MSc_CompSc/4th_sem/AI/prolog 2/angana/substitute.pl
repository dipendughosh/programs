conc([],L,L).
conc([X|L1],L2,[X|L3]):-conc(L1,L2,L3).
sublist(S,L):-conc(L1,L2,L),conc(S,L3,L2).
substitute(X,Y,[],[]).
substitute(X,Y,L1,L1):-not(sublist(X,L1)).
substitute(X,Y,L1,L2):-conc(Q1,P2,L1),conc(P1,X,Q1),conc(P1,Y,Q2),substitute(X,Y,P2,P3),conc(Q2,P3,L2).
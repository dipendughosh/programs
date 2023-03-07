
substitut(X,Y,[],[]).
substitut(X,Y,L1,L2):-conc(Q1,P1,L1),conc(Q2,X,Q1),
conc(Q2,Y,P2),conc(P2,P3,L2),substitut(X,Y,P1,P3).

conc([],L,L).
conc([X|L1],L2,[X|L3]):-conc(L1,L2,L3).

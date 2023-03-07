conc([],L,L).
conc([X|L1],L2,[X|L3]):-conc(L1,L2,L3).
found(X,L):-conc(L1,L2,L),conc(X,L3,L2).
acceptable([]).
acceptable(L):-not(found([0,1],L)).
acceptable(L):-found([0,1],L),conc(L1,L2,L),conc([0,1],L3,L2),found([1,0,0],L3),acceptable(L3).
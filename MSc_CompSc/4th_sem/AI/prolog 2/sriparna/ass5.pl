conc([],L,L).
conc(L,[],L).
conc([X|L1], L2, [X|L3]):- conc(L1,L2,L3).
accept([]).
accept(L):-not(conc(L1,[0,1|L2],L)).
accept(L):-conc(L1,[0,1|L2],L), conc(L3,[1,0,0|L4],L2), accept(L2).


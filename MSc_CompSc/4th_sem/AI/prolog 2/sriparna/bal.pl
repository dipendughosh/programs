conc([],L,L).
conc(L,[],L).
conc([X|L1], L2, [X|L3]):- conc(L1,L2,L3).

balanced([]).
balanced(['{'|L]):-conc(['}'],[],L).
balanced(['{'|L]):-conc(L1,['}'|L2],L), balanced(L1), balanced(L2).

del(X,[X|L],L).
del(X,[Y|L],[Y|L1]):-not(X=Y),del(X,L,L1).
balanced([]).
balanced(['('|L]):-del(')',L,L1),balanced(L1).
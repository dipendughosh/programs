del(X,[],[]).
del(X,[X|L],L1):-del(X,L,L1).
del(X,[Y|L],[Y|L1]):- not(X=Y),del(X,L,L1).
nodoubles([],[]).
nodoubles([X|L1],[X|L2]):- del(X,L1,LL1),nodoubles(LL1,L2).
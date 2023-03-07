
nodbl([],[]).
nodbl([X|L1],[X|L2]):-delall(L1,X,L),nodbl(L,L2).
delall([],X,[]).
delall([H|T],X,R):- H=X,delall(T,X,R).
delall([H|T],X,[H|R]):- delall(T,X,R).

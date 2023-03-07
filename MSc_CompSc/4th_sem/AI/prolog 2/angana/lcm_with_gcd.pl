gcd(X,X,X).
gcd(X,Y,Z):-X>Y, X1 is X-Y,gcd(X1,Y,Z).
gcd(X,Y,Z):-X<Y, Y1 is Y-X,gcd(X,Y1,Z).
listlcm([X,Y],N):-gcd(X,Y,D),N is (X*Y)/D.
listlcm([X,Y|L],N):-gcd(X,Y,D), N1 is (X*Y)/D, listlcm([N1|L],N).
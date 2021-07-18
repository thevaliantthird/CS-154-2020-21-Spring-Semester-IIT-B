findk([X|Y],1,X).
findk([A|B],K,X):-S is K-1,findk(B,S,X).

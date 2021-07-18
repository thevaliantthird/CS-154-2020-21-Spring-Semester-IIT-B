connected(delhi,mumbai).
connected(mumbai,bangalore).
connected(bangalore,chennai).
connected(chennai,kolkata).
connected(kolkata,patna).

% connected(mumbai,delhi).
% connected(bangalore,mumbai).
% connected(chennai,bangalore).
% connected(kolkata,chennai).
% connected(patna,kolkata).


% connected(A,C):-(connected(A,B);connected(B,A)),(connected(B,C);connected(C,B)).

path(A,B):-connected(A,B).

path(A,C):-connected(A,B),path(B,C).

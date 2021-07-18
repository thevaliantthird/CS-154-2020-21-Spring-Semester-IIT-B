% CS 154 Lab 12
% Prolog Program to calculate the factorial of a given integer
% Author: Shubh Kumar, 200050134

fact(1,0).
fact(X,N):- N > 0 , S is N-1,fact(Z,S), X is N*Z.

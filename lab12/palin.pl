% CS 154 Lab 12
% Building a Prolog Program to check if a particular list is a palindrome.
% Author: Shubh Kumar, 200050134

conc([],L,L).
conc([H|T],L,[H|L1]):- conc(T,L,L1).

palindrome([_]).
palindrome([]).
palindrome(L):- conc([X|Y],[X],L), palindrome(Y).

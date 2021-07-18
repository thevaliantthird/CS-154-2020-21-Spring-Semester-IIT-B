% CS 154 Lab 12
% Prolog Program to append a list with another
% Author: Shubh Kumar, 200050134

appen([],L,L).
appen([H|T],L,[H|L1]):- appen(T,L,L1).

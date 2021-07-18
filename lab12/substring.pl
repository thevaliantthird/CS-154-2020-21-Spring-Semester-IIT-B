% CS 154 Lab 12
% Building a program to check if one list is a substring of another
% Author: Shubh Kumar, 200050134



conti([],L).
conti([X|Y],[X|Z]):-conti(Y,Z).

subs([],_).
subs([X|Y],[X|Z]):-conti(Y,Z).
subs([X|Y],[A|B]):- subs([X|Y],B).

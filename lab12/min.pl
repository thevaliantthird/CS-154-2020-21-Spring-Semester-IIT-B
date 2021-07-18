% CS 154 Lab 12
% Prolog Program to get the minimum of a list
% Author: Shubh Kumar, 200050134

minimum([X],X).
minimum([A,B|C],D):- A=<B, minimum([A|C],D).
minimum([A,B|C],D):- A>B, minimum([B|C],D).

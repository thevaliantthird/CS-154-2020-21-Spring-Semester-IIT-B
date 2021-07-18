%CS 154 Lab 12
%Prolog Program to calculate the number of occurences of an element in a list
%Author: Shubh Kumar, 200050134

reverse([SameElement],[SameElement]).
reverse([A|B],[C|D]):-reverse(C,B),reverse(A,D).

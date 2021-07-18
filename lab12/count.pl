%CS 154 Lab 12
%Prolog Program to calculate the number of occurences of an element in a list
%Author: Shubh Kumar, 200050134

count([],_,0).
count([Element|Tail],Element,Count):- count(Tail,Element,RedCount), Count is 1+RedCount.
count([NotMyElement|Tail],Element,RedCount):- count(Tail,Element,RedCount), NotMyElement\=Element.

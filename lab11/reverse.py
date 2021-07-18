#CS 154 Lab 11  Problem 2

# A Recursive Program to get a particular list with its order reversed!

#Author: Shubh Kumar, 200050134


def reverse(l):
    if len(l)==1:           #Base Case
        return l;
    else:                   #Recursive Call
        return reverse(l[int(len(l)/2):])+reverse(l[0:int(len(l)/2)])


print(reverse([1,2,3,4,5,6,7,8,9]))     #Application of the Function!

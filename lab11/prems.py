# CS 154 Lab 11 Problem 2

# A recursive program to generate all permutations of a given list.

#Author: Shubh Kumar, 200050134

def prem(l):
    #Base Cases
    if len(l)==0:
        return [[]]
    elif len(l)==1:
        return [l]
    #Recursive Call
    else:
        return [ x[0:i-1]+[l[0]]+x[i-1:] for i in range(1,len(l)+1) for x in prem(l[1:])]           #The Main Functional Embedding!


#Application

Z = prem([1,2,3,4,5,6])
i = 1
for x in Z:
    print('The ',i,'th, permutation looks like : ',x)
    i+=1

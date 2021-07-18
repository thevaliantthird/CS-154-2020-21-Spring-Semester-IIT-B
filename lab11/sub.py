#CS 154 Lab 11 Problem 2

#Implementing a Program which returns True, if a particular list is a sublist(with order conserved!)
#of another list, and false otherwise.

#Remark: The program treat them as lists(will return true only if the elements occur in the same order in both the lists, but not
#necessarily contiguous!)

#Author: Shubh Kumar, 200050134

def sub(l1,l2) :
    #Base Cases
    if len(l1)==0:
        return True
    if len(l2)==0:
        return False
    #Recursive Calls
    if l1[0]==l2[0]:
        return sub(l1[1:],l2[1:])
    else:
        return sub(l1,l2[1:])


#Applications!
print(sub([1,2,3],[1,5,7,5353,2,565,7,7565452,45,3,75757]))
print(sub([1,2,3],[1,5,7,5353,2,565,7,7565452]))

#CS 154 Lab 11 Problem 2

#Implemented a Divide and Conquer Strategy to recursively compute the Cartesian Product of two given lists

#Author: Shubh Kumar, 200050134

def cross(l1,l2):
    #Base Cases
    if len(l1)==0 or len(l2)==0:
        return []
    elif len(l1)==1 and len(l2)==1:
        return [(l1[0],l2[0])]

    #Dividing into various Recursive Calls
    else:
        return cross(l1[0:int(len(l1)/2)],l2[0:int(len(l2)/2)]) + \
        cross(l1[0:int(len(l1)/2)],l2[int(len(l2)/2):]) +  \
        cross(l1[int(len(l1)/2):],l2[0:int(len(l2)/2)])+ \
        cross(l1[int(len(l1)/2):],l2[int(len(l2)/2):])


print(cross([5,2,4],[1,6,8]))       #Application of the function!

#CS 154 Lab 11 Problem 1

#Implementing a basic recursive Program for the Ackerman Function
#Tabulating the number of calls to the Ackerman Function with each tuple of arguements
#This is done using a Hashmap pre-implemented in Python as Dictionary

#Author: Shubh Kumar, 200050134

def Ack(m,n):
    global count                #Global variable to tabulate function calls
    if (m,n) in count.keys():   #Tabulating
        count[(m,n)]+=1
    else:
        count[(m,n)] = 1
    if m==0:
        return n+1
    elif n==0:
        return Ack(m-1,1)
    else:
        return Ack(m-1,Ack(m,n-1))





count = {}
print(Ack(3,5))
for x in count.keys() :                             #Printing function calls for each argument
    print('The Ackermann Function was called on '+str(x)+' '+str(count[x])+' times.')

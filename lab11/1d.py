#CS 154 Lab 11 Problem 1

#Implementing Memoization to optimize the calculation of the Ackerman Function
#We see that this enables us to calculate upto (3,8) in the Ackerman Function whereas the
#Implementation without Memoization wasn't able to progress beyond (3,5)
#We see from Line 36 that it could even go beyond (3,8) when we calculate sequentially

#Author: Shubh Kumar, 200050134

def Ack(m,n):
    global Mem,i,j                      #Global Variables for Memoization and call-count
    if (m,n) in Mem.keys():
        j+=1
        return Mem[(m,n)]               #Checking if already memorized
    i+=1
    if m==0:
        Mem[(m,n)] = n+1                            #Memorizing
        return n+1
    elif n==0:
        Mem[(m,n)] = Ack(m-1,1)                     #Memorizing
        return Mem[(m,n)]
    else:
        Mem[(m,n)] = Ack(m-1,Ack(m,n-1))            #Memorizing
        return Mem[(m,n)]


#Initializing Global Variables for Memoization and Counting calls
Mem = {}
i = 0
j = 0

print(Ack(3,8))
print('It took '+str(i)+' calls to the Ackerman Function!')
print('It took '+str(j)+' table lookups!')


#Running the function again sequentially to prove robustness
#The function fails to run beyond n = 14, only because of recursive depth limit in Python
i = 0
j = 0
Mem = {}

for x in range(0,4):
    for y in range(0,100000):
        print('For m = '+ str(x) +' and n = '+str(y)+', The value is :  ', str(Ack(x,y)))

print('It took '+str(i)+' calls to the Ackerman Function!')
print('It took '+str(j)+' table lookups!')

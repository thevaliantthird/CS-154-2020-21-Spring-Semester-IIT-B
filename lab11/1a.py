#CS 154 Lab 11    Problem 1

#Implementing a basic recursive version of the Ackerman Function.
#Author: Shubh Kumar, 200050134

def Ack(m,n):
    if m==0:
        return n+1
    elif n==0:
        return Ack(m-1,1)
    else:
        return Ack(m-1,Ack(m,n-1))

#Tesing for m = 0
print(Ack(0,2))
print(Ack(0,3))
print(Ack(0,4))
print(Ack(0,5))
#Tesing for m = 1
print(Ack(1,2))
print(Ack(1,3))
print(Ack(1,4))
print(Ack(1,5))
#Tesing for m = 2
print(Ack(2,2))
print(Ack(2,3))
print(Ack(2,4))
print(Ack(2,5))
#Tesing for m = 3
print(Ack(3,2))
print(Ack(3,3))
print(Ack(3,4))
print(Ack(3,5))

#Implementation using Lambda Function

# ack = lambda m,n : n+1 if m==0 else (lambda x,y : ack(x-1,1) if y==0 else ack(x-1,ack(x,y-1)))(m,n)

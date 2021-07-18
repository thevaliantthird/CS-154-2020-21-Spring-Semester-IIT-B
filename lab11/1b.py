#CS154 Lab 11 Problem 1

#Implementing a recursive version of the Ackerman Function, counting the number of
#calls to the function.

#Author : Shubh Kumar, 200050134

def Ack(m,n):
    global i        #Global Variable required to maitain count of calls
    i+=1
    if m==0:
        return n+1
    elif n==0:
        return Ack(m-1,1)
    else:
        return Ack(m-1,Ack(m,n-1))





i = 0                           #Setting number of calls to the function to 0
print(Ack(3,5))                 #Testing
print('It took '+str(i)+' calls to the Ackerman Function!')


#Implementation using lambda functions

#ack = lambda m,n : (n[0]+1,n[1]+1) if m==0 else (lambda x,y : ack(x-1,(1,y[1]+1)) if y[0]==0 else ack(x-1 , ack(x,(y[0]-1,y[1]+1)) ) )(m,n)

#print(ack(3,(5,0)))

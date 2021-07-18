#CS 154 Lab 11 Problem 1
#Implementing Fibonacci Sequence Generator
#Using Memoization to speed up the process

#Author: Shubh Kumar, 200050134


#Fast Implementation which easily runs till n = 100000!

def Fib(n) :
    global fib
    if n in fib.keys():             #Checking if already calculated and memorized
        return fib[n]
    else:
        fib[n] = Fib(n-1)+Fib(n-2)      #Memorizing
        return fib[n]



fib = {}
fib[0] = 0
fib[1] = 1
for i in range(0,int(input('How many terms of Fibonacci would you want?'))):
    print( str(i)+'th : ' + str(Fib(i)) )




# Naive Implementation without memoization which fails to run beyond n = 34-40 (extremely slow till it reaches there!)

# def Fib(n):
#     if n==0 or n== 1:
#         return n
#     else:
#         return Fib(n-1)+Fib(n-2)
#
#
# for i in range(0,int(input('How many terms of Fibonacci would you want?'))):
#     print( str(i)+'th : ' + str(Fib(i)) )

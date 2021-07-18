# CS 154 Lab 10
# Functional Python Program to catalogue list of words from a text,
# with minimal use of variables. (Modified to be ultra-short and functional, but not very efficient)

# Author: Shubh Kumar, 200050134

l = open(input("Please enter the file name:"),'r').read().replace(r"@","").replace(r"[^A-Za-z0-9()!?\'\`\"]", " ").replace("\s{2,}", " ").replace(r"\n"," ").split(' ')
for s in set(l):
    print(s,l.count(s))

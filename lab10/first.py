# CS 154 Lab 10
# Functional Python Program to catalogue list of words from a text,
# with minimal use of variables.

# Author: Shubh Kumar, 200050134

def reader(file):
    word_count = {}
    #Now, iterate over all words, nicely separated and useless symbols removed
    for word in file.read().lower().replace(r"@","").replace(r"[^A-Za-z0-9()!?\'\`\"]", " ").replace("\s{2,}", " ").replace(r"\n"," ").split(' '):
        if word not in word_count.keys():
            word_count[word] = 1
        else:
            word_count[word]+=1
    return word_count

def Print(counter):
    for key in counter.keys():
        print(key,counter[key])


#The main function call
Print(reader(open(input("Please enter the file name:"),'r')))

# ^ Here we make a call to the reader function which returns the dictionary for printing

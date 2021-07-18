import numpy as np
x = input('Please enter your word : ').encode('ASCII')
dict = {}
for word in [ word.replace("\n","") for word in open('words.txt','r',encoding = 'ASCII').readlines() ]:
    dict[word] = sum([abs(ord(word[i])-x[i])*250*(len(x)-i) for i in range(0,min(len(x),len(word)))])
    if dict[word] == 0 and len(word)==len(x):
        print('The Word '+word+' was found in Dictionary!')
        break
else:
    dict = np.array([ [key, dict[key]] for key in dict.keys()])
    print(dict[np.argsort(dict[:,1])[0:5]])

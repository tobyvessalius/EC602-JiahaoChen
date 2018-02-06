# -*- coding: utf-8 -*-
from numpy import array,reshape
import json

a = open("puzzles.txt")
b = a.readlines()
#b = [x.replace(": ","").replace("'","").replace("{","").replace("}","").replace("[","").replace("]","").replace("\n","").split("\"") for x in b]
#c = b[1],b[2],b[3]
bc = []
bd = []
for i in b:
    c = []
    d = []
    for j in i:
        if j in 'qwertyuioplkjhgfdsazxcvbnm':
            c.append(j)
        elif j in '1234567890':
            d.append(j)
    bc.append([c])
    bd.append([d])

size = []
for i in range((len(bd)-1)):
    size.append(bd[i][0][0])
    del bd[i][0][0]    

del bd[len(bd)-1]

for i in range(len(bc)-1):
    bc[i] = bc[i][0][4:len(bc[i][0])-11]

for i in range(len(bc)-1):
    bc[i] = array(bc[i])
    bc[i] = reshape(array(bc[i]),(int(size[i]),int(size[i])))
    bc[i] = bc[i].transpose()
    

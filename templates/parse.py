import sys
import datetime
head = raw_input()
i=1
line = raw_input()
while line!=None:
    tokens = line.split(',')
    tokens1 = []
    for t in tokens:
        t = t.strip()[1:-1]
        t = t.strip()
        if t.replace('.','',1).isdigit(): 
            t = float(t)
            tokens1.append(t)
    # for t in tokens1:
    #     print t,
    print str(i)+" "+str(tokens1[0])
    i+=1
    try:
        line = raw_input()
    except:
        break
        
import math
import sys
tc= input()
for _ in range(tc):
    n= input()
    opt = 0
    for i in range(int(math.ceil(math.pow(n*1.0,0.5)))):
        t = int(math.sqrt(n-i*i))
        if (t**2 + i**2 )==n: opt=1 
    if opt==1: print "Yes"
    else: print "No" 

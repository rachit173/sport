import random
m =1000
print m
for i in range(m):
    print random.randint(1,1000000),
q = 100
print
print q
for i in range(q):
    a = random.randint(1,m)
    b = random.randint(a,m)
    print str(a)+" "+str(b) 
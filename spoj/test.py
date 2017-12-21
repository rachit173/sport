import random
T=10
print T
for t in range(T):
    n = random.randint(1,100000)
    p = random.randint(2,100000000)
    q = random.randint(2,100000)
    print str(n)+" "+str(p)+" "+str(q)
    for i in range(n):
        print random.randint(1,1000000000),
    print
    for i in range(q/64+2):
        print random.randint(0,n-1),
    print
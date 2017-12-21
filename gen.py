import random
T=10
print T
for i in range(T):
    n = random.randint(1,1000)
    print n
    for _ in range(n):
        print random.randint(0,9),
    print

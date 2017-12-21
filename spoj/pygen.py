import random
f=open('test.in','w')
n = random.randint(20000,40000)
f.write(str(n)+"\n")
for i in range(n):
    f.write(str(random.randint(1,1000000))+" ")
f.write("\n")
m = 200000
f.write(str(m)+"\n")
for i in range(m):
    a=random.randint(1,n)
    b=random.randint(a,n)
    f.write(str(a)+' '+str(b)+'\n')
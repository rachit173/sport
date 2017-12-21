k=input()
str=raw_input().strip()
lst=map(int,str[:])
sum=0
for i in range(len(lst)): sum+=lst[i]
if sum>=k: print "0"
else:
    t=k-sum
    ans=0
    lst=sorted(lst)
    for i in range(len(lst)):
        if t<=0: break
        t=t-(9-lst[i])
        ans=ans+1
    print ans
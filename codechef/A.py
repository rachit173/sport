T=input()
for i in range(T):
    a,b = map(int,raw_input().strip().split())
    x = min([a,b])
    y = max([a,b])
    ans = x*y*(x*(x+1))/2-((x+y)*(x*(x+1)*(2*x+1))/6)+(((x*(x+1))/2)**2)
    ans =ans%(10**9+7)
    print "Case #"+str(i+1)+": "+str(ans)
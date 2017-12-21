t=input()
for i in range(t):
    n,k=map(int,raw_input().strip().split())
    nom=1
    denom=1
    n=n-1
    k=k-1
    if 2*k>n: k=n-k
    for i in range(k):
        nom=nom*(n-i)
    for i in range(k):
        denom=denom*(i+1)
    print nom/denom
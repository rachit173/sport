n = input()
a = map(int, raw_input().split())
res = 0
mp = {}
mp1 = {}
for i in range(n):
    res += (2*i+1-n)*a[i]
    mp[a[i]] = mp.get(a[i], 0) + 1
for i in range(n):
    res += mp.get(a[i]-1, 0) - 2*mp1.get(a[i]-1, 0)
    mp1[a[i]] = mp1.get(a[i], 0) + 1

print res
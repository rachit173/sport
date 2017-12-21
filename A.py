def gcd(a,b):
	if b==0: return a
	else : return gcd(b,a%b)
n=input()
for i in range(n):
	a,b=map(int,raw_input().strip().split())
	print gcd(a,b)
	
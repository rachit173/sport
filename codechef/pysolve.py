n = input()
str=raw_input()
lst = map(int,str.strip().split())
m = input()
for i in range(m):
    x,y  = map(int,raw_input().strip().split())
    print min(lst[x-1:y])
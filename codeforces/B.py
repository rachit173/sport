import sys
s=raw_input().strip()
str=raw_input().strip()
q=input()
s='['+s+']'
str.replace('?',s)
str.replace('*','[a-z]')


all=sys.stdin.readlines()
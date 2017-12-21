import sys
all=sys.stdin.readlines()
lst=map(int,all)
for x in lst:
    if x==1: print "1"
    else:
        print 2*(x-1)

import re
n=input()
s1 = '(\?)@'
w1 = '\w{0,4}'
# print s1,w1
for t_i in range(n):
    a = raw_input().strip()
    b = raw_input().strip()
    lst = list(a)
    a = s1.join(lst)
    # print a
    
    a = a.replace('*',w1)
    b = b.replace('*','????')

    a = s1+a+s1+'$'
    a = a.replace('@','*')
    lst = list(a)
    l = len(lst)
    for i in range(l):
        if i==0:
            if lst[i].isalpha() and lst[i+1]=='(':
                lst[i] = '['+lst[i]+'?]'
        if lst[i].isalpha() and lst[i-1]=='*' and lst[i+1]=='(':
            lst[i] = '['+lst[i]+'?]'
        if i==l-1:
            if lst[i].isalpha() and lst[i-1]=='*':
                lst[i] = '['+lst[i]+'?]'
    a = ''.join(lst)
    # print a
    # print b
    m = re.compile(a)
    t = m.match(b)
    if t==None:
        print 'Case #'+str(t_i+1)+': FALSE'
    else:
        print 'Case #'+str(t_i+1)+': TRUE'
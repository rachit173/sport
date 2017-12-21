s = raw_input().strip()
c = 0
c+=s.count('Nikita')
c+=s.count("Olya")
c+=s.count("Slava")
c+=s.count("Danil")
c+=s.count("Ann")
if c==1: print "YES"
else: print "NO"
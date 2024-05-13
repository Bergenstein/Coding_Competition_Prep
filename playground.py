s = set()
a = 2; b = 3
s.add(a)
s.add(b)
print(a in s) 
print(3 in s) 
print(4 in s)
s.discard(b)
print(b in s)
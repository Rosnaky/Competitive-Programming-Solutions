from collections import defaultdict


s1 = input("")
s2 = input("")

count = defaultdict(int)


for c in s1:
    count[c] += 1

good = True
for c in s2:
    if count[c] == 0 and count["*"] == 0:
        good = False
        break
    elif count[c] == 0:
        count["*"] -= 1
    
    else:
        count[c] -= 1

if good:
    print("A")
else:
    print("N")

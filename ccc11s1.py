
n = int(input())

s = t = T = S = 0

for i in range(n):
    line = input()

    for c in line:
        if c == "s":
            s+=1
        elif c == "t":
            t += 1
        elif c == "T":
            T += 1
        elif c == "S":
            S += 1

if t+T > s+S:
    print("English")
else:
    print("French") 
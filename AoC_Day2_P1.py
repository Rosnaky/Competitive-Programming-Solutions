import re

fname = "AoC_Day2.in"

with open(fname, "r") as f:
    lines = f.readlines()


ans = 0

for k in range(len(lines)):
    line = lines[k]
    line = re.sub("\n", "", line)
    sets = line[line.index(":")+2:].split("; ")
    for i in range(len(sets)):
        sets[i] = sets[i].split(", ")
        for j in range(len(sets[i])):
            sets[i][j] = sets[i][j].split(" ")
            sets[i][j][0] = int(sets[i][j][0])
    

    good = True
    for j in range(len(sets)):
        s = sets[j]
        red = 12
        green = 13
        blue = 14
        for p in s:
            if p[1] == "red":
                red -= p[0]
            elif p[1] == "blue":
                blue -= p[0]
            elif p[1] == "green":
                green -= p[0]
        
        if red < 0 or blue < 0 or green < 0:
            good = False
            break
    if good:
        ans += k+1


print(ans)
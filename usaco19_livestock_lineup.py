import re
with open("lineup.in", "r") as f:
    inp = f.readlines()

for l in range(len(inp)):
    inp[l] = re.sub("\n", "", inp[l])

ans = []
def backtrack(curr, limits, cows):
    if len(curr) == 8:
        ans.append(curr[:])
    for cow in cows:

        inlimit = False
        for p in limits:
            p.sort()
            p1 = p[0]
            p2 = p[1]
            if cow in p:
                if (p1 not in curr and p2 not in curr):
                    inlimit = True
                    curr.extend([p1, p2])
                    cows.remove(p1)
                    cows.remove(p2)
                    backtrack(curr, limits, cows)
                    curr.remove(p1)
                    curr.remove(p2)
                    cows.append(p1)
                    cows.append(p2)
                    cows.sort()

                    curr.extend([p2, p1])
                    cows.remove(p1)
                    cows.remove(p2)
                    backtrack(curr, limits, cows)
                    curr.remove(p1)
                    curr.remove(p2)
                    cows.append(p1)
                    cows.append(p2)
                    cows.sort()
                elif (p1 not in curr and p2 == curr[-1]):
                    curr.append(p1)
                    cows.remove(p1)
                    backtrack(curr, limits, cows)
                    curr.remove(p1)
                    cows.append(p1)
                    cows.sort()
                elif (p2 not in curr and p1 == curr[-1]):
                    curr.append(p2)
                    cows.remove(p2)
                    backtrack(curr, limits, cows)
                    curr.remove(p2)
                    cows.append(p2)
                    cows.sort()

                elif p1 in curr:
                    return
                elif p2 in curr:
                    return
                else:
                    continue

        if not inlimit:
            curr.append(cow)
            cows.remove(cow)
            backtrack(curr, limits, cows)
            curr.remove(cow)
            cows.append(cow)
            cows.sort()

n = int(inp[0])

cows = ['Beatrice', 'Belinda', 'Bella', 'Bessie', 'Betsy', 'Blue', 'Buttercup', 'Sue']
cows.sort()
constraints = []

for i in range(n):
    constraints.append(inp[i+1].split(' must be milked beside '))



backtrack([], constraints, cows)

ans.sort()

fout = open('lineup.out', 'w')
for c in ans[0]:
    fout.write(c+"\n")
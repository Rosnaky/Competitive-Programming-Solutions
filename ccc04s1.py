
n = int(input())

for i in range(n):
    words = []
    for j in range(3):
        words.append(input())
    good = True

    for j in range(2):
        for k in range(j+1, 3):
            if len(words[j]) < len(words[k]):
                fix = words[j]
                nFix = words[k]
            else:
                fix = words[k]
                nFix = words[j]
            if nFix[:len(fix)+1] == fix or nFix[-len(fix):] == fix:
                good = False
                break

        if not good:
            break

    if good:
        print("Yes")
    else:
        print("No")
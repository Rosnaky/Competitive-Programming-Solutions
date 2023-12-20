import re

n = int(input())
con = [[], [], ["a", "b", "c"], ["d", "e", "f"], ["g", "h", "i"], ["j", "k", "l"], ["m", "n", "o"], ["p", "q", "r", "s"], ["t", "u", "v"], ["w", "x", "y", "z"]]

for i in range(n):
    num = [x for x in re.sub("-", "", input())]
    
    for c in range(len(num)):
        if isinstance(num[c], str):
            for j in range(len(con)):
                if num[c].lower() in con[j]:
                    num[c] = str(j)

    num.insert(3, "-")
    num.insert(7, "-")
    
    num = "".join(num)
    print(num[:12])
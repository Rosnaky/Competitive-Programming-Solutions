
n = int(input())

ans = []

computers = []

for i in range(n):
    temp = input("").split(" ")
    temp[1] = int(temp[1])
    temp[2] = int(temp[2])
    temp[3] = int(temp[3])
    computers.append(temp)

computers = sorted(computers, key=lambda x: x[0])
computers = sorted(computers, key=lambda x: (x[1]*2+x[2]*3+x[3]))

computers = computers[::-1]


if len(computers) >1:
    for pc in computers[:2]:
        print(pc[0])
elif len(computers) == 1:
    print(pc[0])

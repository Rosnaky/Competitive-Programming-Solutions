n = int(input())

p = []

for i in range(n):
    p.append([int(x) for x in input().split(" ")])
p.sort()

speed = 0

for i in range(n-1):
    speed = max(speed, abs(p[i][1] - p[i+1][1]) / abs(p[i][0] - p[i+1][0]))

print(speed)
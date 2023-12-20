import math

a = int(input())
b = int(input())


start = math.ceil(pow(min(a, b), 1/3))
end = math.floor(pow(max(a, b), 1/3))

ans = 0

while start <= end:
    if pow(start, 1/2) == math.floor(pow(start, 1/2)):
        ans += 1

print(ans)


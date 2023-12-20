n = int(input(""))


villages = []

for i in range(n):
    villages.append(int(input("")))

villages.sort()

ans = float("inf")
for i in range(1, n-1):
    ans = min(ans, ((villages[i+1] - villages[i])/2 + (villages[i] - villages[i-1])/2))

print(ans)


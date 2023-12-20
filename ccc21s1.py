n = int(input())

heights = [int(x) for x in input().split(" ")]
widths = [int(x) for x in input().split(" ")]

ans = 0
for i in range(n):
    ans += (heights[i] + heights[i+1]) * widths[i] / 2

print(ans)
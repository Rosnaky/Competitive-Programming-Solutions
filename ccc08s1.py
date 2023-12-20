

line = input("").split(" ")
ans = tuple(line)

while line[0] != "Waterloo":
    line = input("").split(" ")
    if line[1] < ans[1]:
        ans = tuple(line)


print(ans[0])
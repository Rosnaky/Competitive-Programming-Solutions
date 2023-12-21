import re

nums = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]

def makeNum(line):
    firstNumIndex = float("inf")
    lastNumIndex = float("inf")
    firstNum = ""
    lastNum = ""
    
    for v in nums:
        if line.find(v) != -1 and line.find(v) < firstNumIndex:
            firstNumIndex = line.find(v)
            firstNum = v
    
    temp = line[::-1]
    for v in nums:
        if temp.find(v[::-1]) != -1 and temp.find(v[::-1])+len(lastNum)-1 < lastNumIndex:
            lastNum = v
            lastNumIndex = temp.find(v[::-1])+len(lastNum)-1

    print(line, lastNum, lastNumIndex, line[::-1].find(lastNum[::-1])+len(lastNum)-1, end = " ")
    if (line[::-1].find(lastNum[::-1]))+len(lastNum)-1 == lastNumIndex and lastNumIndex != -1 and lastNumIndex != float("inf"):
        line = line.replace(lastNum, str(1+nums.index(lastNum)), 1)

    if firstNumIndex != float("inf"):
        line = line.replace(firstNum, str(1+nums.index(firstNum)), 1)
    
    print(line)
    
    
    return line


fname = "AoC_Day1.in"

with open(fname, 'r') as f:
    inp = f.readlines()

ans = 0


for line in inp:
    first = -1
    last = -1

    line = makeNum(line)


    for i in range(len(line)):
        try: 
            int(line[i])
            if first == -1:
                first = i
            else:
                last = i
        except:
            pass
    if first != -1 and last != -1:
        ans += int(line[first]+line[last])
    elif first != -1:
        ans += int(line[first]*2)

print(ans)
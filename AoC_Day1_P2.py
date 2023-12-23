import re

nums = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]

def makeNum(line):
    firstNumIndex = float("inf")
    lastNumIndex = float("inf")
    firstNum = ""
    lastNum = ""

    firstDigit = float("inf")
    lastDigit = -1

    for i in range(len(line)):
        try:
            int(line[i])
            if firstDigit == float("inf"):
                firstDigit = i
            else:
                lastDigit = i
        except:
            pass

    
    for v in nums:
        if line.find(v) != -1 and line.find(v) < firstNumIndex:
            firstNumIndex = line.find(v)
            firstNum = v
    
    if firstNumIndex != float("inf") and firstNumIndex < firstDigit:
        line = line.replace(firstNum, str(1+nums.index(firstNum)), 1)    
    
    for i in range(len(line)):
        try:
            int(line[i])
            if firstDigit == float("inf"):
                firstDigit = i
            else:
                lastDigit = i
        except:
            pass

    temp = line[::-1]
    for v in nums:
        if temp.find(v[::-1]) != -1 and temp.find(v[::-1]) < lastNumIndex:
            lastNum = v
            lastNumIndex = temp.find(v[::-1])

    if line[::-1].find(lastNum[::-1]) == lastNumIndex and lastNumIndex != float("inf") and len(line)-(lastNumIndex+len(lastNum)) > lastDigit:
        line = line[::-1].replace(lastNum[::-1], str(1+nums.index(lastNum)), 1)
        line = line[::-1]

    
    
    
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
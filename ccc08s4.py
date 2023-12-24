


# 1
# 3
# 3
# 3
# 3

def backtrack(equation, open, close, nums):
    if len(nums) == 0 and open == close:
        possible.append(equation)
        return

    # print(equation)    

    if open < 4 and (len(equation) == 0 or equation[-1] in "(*+-/"):
        equation.append("(")
        backtrack(equation, open+1, close, nums)
        equation.pop()
    if open >= close + 1 and len(nums) != 4 and len(equation) != 0 and equation[-1] not in ["*", "/", "+", "-", "("]:
        equation.append(")")
        backtrack(equation, open, close+1, nums)
        equation.pop()

    if len(nums) == 4:
        for i in range(len(nums)):
            num = nums[i]
            equation.append(num)
            nums.remove(num)
            backtrack(equation, open, close, nums)
            equation.pop()
            nums.insert(i, num)

    try:
        int(equation[-1])

        for op in ["*", "/", "+", "-"]:
            equation.append(op)
            backtrack(equation, open, close, nums)
            equation.pop()

    except:
        for i in range(len(nums)):
            num = nums[i]
            equation.append(num)
            nums.remove(num)
            backtrack(equation, open, close, nums)
            equation.pop()
            nums.insert(i, num)
        




hands = int(input())

for i in range(hands):

    ans = 0
    line = []

    for j in range(4):
        line.append(input())
    
    
    possible = []

    backtrack([], 0, 0, line)

    print(possible)

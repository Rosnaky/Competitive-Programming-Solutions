n = int(input())

for x in range(n):

    temp = [int(x) for x in input().split(" ")]
    curr = temp[0]
    end = temp[1]

    grid = [[curr]]
    moves = 0
    curr += 1
    while (curr <= end):

        if (moves % 2 == 0):
            if (moves % 4 == 0):
                temp = len(grid)
                for i in range(temp-1):
                    grid[i+1].insert(0, " ")
                for i in range(temp-1):
                    grid[i+1][0] = curr
                    curr += 1
                grid.append([curr])
                curr += 1
            else:
                temp = len(grid)
                for i in range(temp-1):
                    grid[temp-i-2].append(curr)
                    curr += 1
                grid.insert(0, [curr])
                curr += 1

        else:
            if (moves % 4 == 1):
                temp = len(grid[0])
                for i in range(temp):
                    grid[-1].append(curr)
                    curr += 1
            else:
                temp = len(grid[0])
                for i in range(temp+1):
                    grid[0].insert(0, curr)
                    curr += 1

        moves += 1

    for i in range(len(grid[1]) - len(grid[0])+1):
        grid[0].insert(0, " ")

    for row in grid:
        for col in row:
            if col != " " and col > end:
                row.remove(col)

    for row in grid:
        for col in row:

            print(col, end=" ")
        print("")
    print("")
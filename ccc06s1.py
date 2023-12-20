
mom = input()
dad = input()

n = int(input())

for c in range(n):

    child = input()
    good = True

    for i in range(len(child)):
        momPair = mom[(i*2):(i*2)+2]
        dadPair = dad[(i*2):(i*2)+2]

        childA = child[i]
        if childA == childA.upper():
            if childA in momPair or childA in dadPair:
                pass
            else:
                good = False
                print("Not their baby!")
                break
        
        else:
            if childA in momPair and childA in dadPair:
                pass
            else:
                good = False
                print("Not their baby!")
                break

    if good:
        print("Possible baby.")
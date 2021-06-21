import sys
numGates = int(sys.stdin.readline())
numPlanes = int(sys.stdin.readline())

gates = [0] * numGates

planeLandCount = 0

failedToFind = False

# answered = False
for i in range(numPlanes):
    # print(gates)
    planeNum = int(sys.stdin.readline()) - 1

    
    if gates[planeNum] == 0: # check if max spot is taken
        if i == numPlanes -1:
            failedToFind = True
        gates[planeNum] += 1
        planeLandCount += 1
    else:
        checkPlaneNum = planeNum
        while True:
            gobackAmount = gates[checkPlaneNum]
            # print(gates)
            # print("checkplaneNum", checkPlaneNum)
            if checkPlaneNum - gobackAmount < 0:
                # print("out")
                failedToFind = True
                break

            if gates[checkPlaneNum - gobackAmount] == 0:
                if i == numPlanes -1:
                    failedToFind = True
                gates[checkPlaneNum - gobackAmount] += 1
                planeLandCount += 1
                break
            else:
                gates[checkPlaneNum] += 1
                checkPlaneNum -= gobackAmount + 1

    if failedToFind:
        print(planeLandCount)
        # answered = True
        break



dimensions = [int(x) for x in input().split()]

nRows = dimensions[0]
nCols = dimensions[1]

oBoard = []
camArr = []
for i in range(nRows):
    line = input()
    for j in range(nCols):
        if line[j] == "S":
            initPos = [i, j]
        elif line[j] == "C":
            camArr.append([i, j])
    oBoard.append([c for c in line])

modBoard = [row[:] for row in oBoard]
end = False

# mark inaccessable positions due to cameras
for c in camArr:
    camPos = c

    modBoard[camPos[0]][camPos[1]] = "W"
    # look up
    checkY = camPos[0]
    for j in range(camPos[0]):
        checkY -= 1
        checkPos = oBoard[checkY][camPos[1]]
        if checkPos == "W":
            break
        elif checkPos == ".":
            modBoard[checkY][camPos[1]] = "W"
        elif checkPos == "S":
            end = True
            break
    # look down
    checkY = camPos[0]
    for j in range(nRows - camPos[0] - 1):
        checkY += 1
        checkPos = oBoard[checkY][camPos[1]]
        if checkPos == "W":
            break
        elif checkPos == ".":
            modBoard[checkY][camPos[1]] = "W"
        elif checkPos == "S":
            end = True
            break
    # look left
    checkX = camPos[1]
    for j in range(camPos[1]):
        checkX -= 1
        checkPos = oBoard[camPos[0]][checkX]
        if checkPos == "W":
            break
        elif checkPos == ".":
            modBoard[camPos[0]][checkX] = "W"
        elif checkPos == "S":
            end = True
            break
    # look right
    checkX = camPos[1]
    for j in range(nCols - camPos[1] - 1):
        checkX += 1
        checkPos = oBoard[camPos[0]][checkX]
        if checkPos == "W":
            break
        elif checkPos == ".":
            modBoard[camPos[0]][checkX] = "W"
        elif checkPos == "S":
            end = True
            break

def findPositions(pos):
    possiblePos = [[pos[0]+1, pos[1]], [pos[0]-1, pos[1]], [pos[0], pos[1]+1], [pos[0], pos[1]-1]]

    accessablePos = []
    for i in range(len(possiblePos)):
        cord = possiblePos[i]
        if cord[0] > nRows-1 or cord[0] < 0 or cord[1] > nCols-1 or cord[1] < 0:
            continue
        
        boardItem = modBoard[cord[0]][cord[1]]

        if boardItem == "W" or boardItem == "C":
            continue

        # check for conveyor
        if boardItem == "L" or boardItem == "R" or boardItem == "U" or boardItem == "D":
            invalidConveyor = False
            visitedConveyors = []
            while True:
                boardItem = modBoard[cord[0]][cord[1]]
                visitedConveyors.append(cord[:])
                
                # apply conveyor movements
                if boardItem == "U":
                    cord[0] -= 1
                elif boardItem == "D":
                    cord[0] += 1
                elif boardItem == "R":
                    cord[1] += 1
                elif boardItem == "L":
                    cord[1] -= 1
                
                if cord[0] > nRows - 1 or cord[0] < 0 or cord[1] > nCols - 1 or cord[1] < 0:
                    invalidConveyor = True
                    break
                
                if boardItem == "W" or boardItem == "C":
                    invalidConveyor = True
                    break
                
                if boardItem == ".":
                    break

                if cord in visitedConveyors:
                    # print(visitedConveyors, cord)
                    invalidConveyor = True
                    break

            if invalidConveyor: # if conveyor does not lead anywhere check to next position
                continue
            
        accessablePos.append(cord)
    
    # print(accessablePos)
    return accessablePos

distances = [[-1] * nCols for i in range(nRows)]

distances[initPos[0]][initPos[1]] = 0
queue = [initPos]

while queue and not end:
    pos = queue.pop(0)

    for c in findPositions(pos):
        if distances[c[0]][c[1]] == -1:
            queue.append(c)
            distances[c[0]][c[1]] = distances[pos[0]][pos[1]] + 1
        else:
            distances[c[0]][c[1]] = min(distances[c[0]][c[1]], distances[pos[0]][pos[1]]+1)

for i in range(nRows):
    for j in range(nCols):
        if oBoard[i][j] == ".":
            print(distances[i][j])


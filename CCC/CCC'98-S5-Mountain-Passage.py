numTrips = int(input())

answers = []

def findNextPositions(pos, size):
    possiblePos = [[pos[0]+1,pos[1]],
                    [pos[0]-1,pos[1]],
                    [pos[0],pos[1]+1],
                    [pos[0],pos[1]-1]]
    positions = []
    for p in possiblePos:
        if p[0]<=size and p[0]>=0 and p[1]<=size and p[1]>=0:
            positions.append(p)
    return positions
            

for i in range(numTrips):
    boardSize = int(input())

    board = [[] for x in range(boardSize)]
    for row in range(boardSize):
        for col in range(boardSize):
            board[col].append(int(input()))
    
    initElev = board[0][0]

    queue = [[[0,0],0]]
    visited = [[0,0]]

    foundPath = False
    while queue:
        data = queue.pop(0)

        location = data[0]
        elev = board[location[0]][location[1]]
        oxygen = data[1]

        if location == [boardSize-1, boardSize-1]:
            foundPath = True
            answers.append(oxygen)
            break

        for pos in findNextPositions(location, boardSize-1):
            stepElev = board[pos[0]][pos[1]]
            
            if pos not in visited and abs(elev-stepElev) < 3:
                visited.append(pos)
                newOxygen = oxygen
                if elev > initElev or stepElev > initElev:
                    newOxygen += 1
                queue.append([pos, newOxygen])
    
    if not foundPath:
        answers.append("CANNOT MAKE THE TRIP")
    
for i in range(len(answers)):
    print(answers[i])
    if i < len(answers)-1:
        print('')
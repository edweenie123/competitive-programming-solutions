finalDist = int(input())
numClub = int(input())
clubs = [int(input()) for i in range(numClub)]

queue = [0]
distances = {0:0}
solutionFound = False
while (queue):
    dist = queue.pop(0)
    
    for d in clubs:
        newDist = dist + d
        if newDist == finalDist:
            solutionFound = True
            print("Roberta wins in", distances[dist] + 1, "strokes.")
            break
        if newDist < finalDist:
            if newDist not in distances:
                queue.append(newDist)
                distances[newDist] = distances[dist] + 1
            else:
                if distances[dist] + 1 < distances[newDist]:
                    distances[newDist] = distances[dist] + 1
    if solutionFound:
        break

if not solutionFound:
    print("Roberta acknowledges defeat.") 
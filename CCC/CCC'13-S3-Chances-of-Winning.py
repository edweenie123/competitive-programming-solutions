def newGame (a, b, p, status):
    newP = p.copy()
    if status == "w":
        newP[a] = newP.get(a, 0) + 3
    elif status == "l":
        newP[b] = newP.get(b, 0) + 3
    else:
        newP[a] = newP.get(a, 0) + 1
        newP[b] = newP.get(b, 0) + 1
    return newP

def isWinner(points, t):
    winner = True
    tScore = points.get(t, 0)
    for key in points:
        if key == t:
            continue
        else:
            if points[key] >= tScore:
                winner = False
                break 
    if winner: return True
    else: return False

tWin = 0
def calcScore(unplayed, fpoints, i):
    global tWin
    teams = unplayed[i]
    a = teams[0]
    b = teams[1]
    
    winP = newGame(a, b, fpoints, "w")
    loseP = newGame(a, b, fpoints, "l")
    tieP = newGame(a, b, fpoints, "t")
    if i < len(unplayed)-1:
        calcScore(unplayed, winP, i+1)
        calcScore(unplayed, loseP, i+1)
        calcScore(unplayed, tieP, i+1)
    else:
        if isWinner(winP,t):
            tWin += 1
        if isWinner(loseP,t):
            tWin += 1
        if isWinner(tieP,t):
            tWin += 1

t = int(input()) # favourite team
g = int(input()) # num games played

points = {}
played = []
for i in range(g):
    a, b, sA, sB = map(int, input().split())
    if sA > sB:
        sA = 3
        sB = 0
    elif sB > sA:
        sA = 0
        sB = 3
    else:
        sA = 1
        sB = 1
    points[a] = points.get(a, 0) + sA
    points[b] = points.get(b, 0) + sB
    played.append([a,b])

games = [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
unplayedGames = []

for i in games:
    if i in played or [i[1],i[0]] in played:
        continue
    unplayedGames.append(i)

tWin = 0
calcScore(unplayedGames, points, 0)
print(tWin)
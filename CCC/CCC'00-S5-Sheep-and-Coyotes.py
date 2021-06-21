numSheep = int(input())

sheepCords = []
for i in range(numSheep):
    sheepCords.append((float(input()), float(input())))

firstSheeps = set()

# print(firstSheeps)

xPos = 0

while xPos <= 1000:
   
    # d = findDistances(xPos)
    # minDistSheep = d[min(d, key=d.get)]
    
    minDistSheep = min(sheepCords, key = lambda cord: (xPos-cord[0])**2  + cord[1]**2)
    firstSheeps.add(minDistSheep)
    xPos += 0.05 
        
# print(firstSheeps)
# alreadyPrint = []

for sheep in firstSheeps:
    x = sheep[0]
    y = sheep[1]
    print("The sheep at (%.2f, %.2f) might be eaten." % (x,y))
    # alreadyPrint.append([x, y])

 

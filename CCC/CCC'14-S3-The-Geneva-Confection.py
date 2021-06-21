import sys

def checkIfPossible(arr, nCars):
    reqCar = 1

    branch = []

    isPossible = "Y"
    while reqCar <= nCars and isPossible == "Y":

        if len(arr) > 0 and arr[-1] == reqCar:
           arr.pop(-1)
           reqCar+=1
        elif len(branch) > 0 and branch[-1] == reqCar:
            branch.pop(-1)
            reqCar += 1
        elif len(arr) > 0:
            branch.append(arr[-1])
            arr.pop(-1)
        else:
            isPossible = "N"
            break
    return isPossible
            

nTests = int(sys.stdin.readline())

answerArr = []
for i in range(nTests):
    nCars = int(sys.stdin.readline())
    arr = []
    for j in range(nCars):
        arr.append(int(sys.stdin.readline()))
    answerArr.append(checkIfPossible(arr, nCars))
for a in answerArr:
    print(a)
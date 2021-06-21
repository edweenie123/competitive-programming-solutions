x = input()

def isType(S):
    streakCnt = 0
    lenS = len(S)
    for i in range(lenS):
        num = int(S[i])
        if (i==lenS-1):
            if (streakCnt!=num): 
                return False
            else: 
                return True
        elif (num==0): 
            streakCnt += 1
        elif num > streakCnt:
            return False
        else: 
            streakCnt -= num - 1
   
    return True

if (isType(x[::-1])): 
    print("Valid")
else: 
    print("Invalid")

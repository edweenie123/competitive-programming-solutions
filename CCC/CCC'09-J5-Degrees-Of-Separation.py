graph = {1:[6],2:[6],3:[4,5,6,15],4:[3,5,6],5:[3,4,6],6:[1,2,3,4,5,7],7:[6,8],8:[7,9],9:[8,10,12],10:[9,11],11:[10,12],12:[9,11,13],13:[12,14,15],14:[13],15:[3,13],16:[17,18],17:[16,18],18:[16,17]}
for key in graph: graph[key] = set([i for i in graph[key]])
a = []
while True:
    com = input()
    if com == "q": break
    x = int(input())
    if com == "i":
        y = int(input())
        if x in graph: graph[x].add(y)
        else: graph[x] = set([y])
        if y in graph: graph[y].add(x)
        else: graph[y] = set([x])
    elif com == "d":
        y = int(input())
        graph[x].remove(y)
        graph[y].remove(x)
    elif com == "n":
        a.append(len(graph[x]))
    elif com == "f":
        fof = set()
        friends = graph[x]
        for f in friends:
            for g in graph[f]:
                if g not in friends and g != x:
                    fof.add(g) 
        a.append(len(fof))
    elif com == "s":
        y = int(input())
        dist = [-1 for x in range(50)]
        dist[x] = 0
        queue = [x]
        while queue:
            v = queue.pop(0)
            if v == y:
                break
            for f in graph[v]:
                if dist[f] == -1:
                    queue.append(f)
                    dist[f] = dist[v] + 1
        if dist[y] == -1: a.append("Not connected")
        else: a.append(dist[y]) 
for i in a: print(i)
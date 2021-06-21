import sys

input = sys.stdin.readline

hullAmount, numVertex, numEdge = map(int, input().split())

graph = {}

for i in range(numEdge):
	d = [int(x) for x in input().split()]
	if d[0] in graph:
		graph[d[0]].append(d[1:])
	else:
		graph[d[0]] = [d[1:]]
	if d[1] in graph:
		graph[d[1]].append([d[0]] + d[2:])
	else:
		graph[d[1]] = [[d[0]] + d[2:]]

start, goal = map(int, input().split())

inf = 1000000000
unvisited = set([key for key in graph])
distances = [[inf for c in range(hullAmount+1)] for r in range(numVertex+1)]

for i in range(hullAmount+1):
	distances[start][i] = 0 

queue = [start]
# print(unvisited, distances)

while queue:
	vertex = queue.pop(0)

	unvisited.add(vertex)
	for p in graph[vertex]:
		neighbor = p[0]
		time = p[1]
		damage = p[2]

		for i in range(hullAmount-damage+1):
			if distances[vertex][i] + time < distances[neighbor][i+damage]:
				distances[neighbor][i+damage] = distances[vertex][i] + time
			
				if neighbor in unvisited:
					queue.append(neighbor)
					unvisited.remove(neighbor)

if distances[goal][hullAmount-1] == inf:
	print(-1)
else:
	print(distances[goal][hullAmount-1])



# import sys
# raw_input = sys.stdin.readline

# K,N,M = map(int,raw_input().split())

# islands = [[] for x in range(N+1)]

# for i in range(M):
#   a,b,t,h = map(int,raw_input().split())
#   islands[a].append([b,t,h])
#   islands[b].append([a,t,h])

# a,b = map(int,raw_input().split())

# array=[[10000000 for j in range(K+1)]for i in range(N+1)] 

# for i in range(K+1):
#   array[a][i] = 0
  
# checked=[False for i in range(N+1)] 
# queue=[a]                              
# while queue:                         
#   u=queue.pop(0)

#   for v in islands[u]:
#     for i in range(K-v[2]+1):
#       if array[u][i]+v[1]<array[v[0]][i+v[2]]:
#         array[v[0]][i+v[2]]=array[u][i]+v[1]
#         if not checked[v[0]]:
#           queue.append(v[0])
#           checked[v[0]]=True
			
# if array[b][K-1] == 10000000:
#   print (-1)
# else:
#   print (array[b][K-1])
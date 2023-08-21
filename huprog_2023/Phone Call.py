from collections import deque

temp = input().split()
n = int(temp[0])
m = int(temp[1])
graph = {}
for i in range(1,n+1):
    graph[i]=[]

for i in range(m):
    temp = input().split()
    a = int(temp[0])
    b = int(temp[1])
    w = int(temp[2])
    if w != 0:
        w = 1
    graph[a].append((b, w))

queue = []
visited = [False for i in range(n)]
r = 0

visited[0] = True
for i in graph[1]:
    queue.append(i)

while False in visited:
    cur = min(queue, key=lambda x: x[1])
    queue.remove(cur)
    if visited[cur[0]-1]:
        continue
    r += cur[1]
    for i in graph[cur[0]]:
        if not visited[cur[0]-1]:
            queue.append(i)
print(r)
'''
4 4
1 4 1
4 2 1
3 2 0
4 3 0

6 7
1 2 1
1 3 0
2 5 0
3 5 0
5 3 1
5 4 0
5 6 1

4 3
1 2 0
2 4 0
2 3 0

3 3
1 3 0
2 3 0
2 1 0

'''
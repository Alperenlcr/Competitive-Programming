from collections import defaultdict

def dfs(node, parent, level, graph, levels):
    levels[node] = level
    for child in graph[node]:
        if child != parent:
            dfs(child, node, level + 1, graph, levels)

n = int(input())
graph = defaultdict(list)
for i in range(n-1):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)
root = int(input())
levels = [0] * n
dfs(root, None, 0, graph, levels)
min_level = min(levels)
print(min_level)
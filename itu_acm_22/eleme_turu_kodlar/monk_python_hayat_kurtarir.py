temp = input().split()
graph = []
for i in range(int(temp[1])):
    edge = input().split()
    graph.append([int(edge[0]), int(edge[1])])

cycles = []

def main():
    global graph
    global cycles
    for edge in graph:
        for node in edge:
            findNewCycles([node])
    print(len(cycles))
    for cy in cycles:
        path = [str(node) for node in cy]
        s = ",".join(path)
        print(s)

def findNewCycles(path):
    start_node = path[0]
    next_node= None
    sub = []

    #visit each edge and each node of each edge
    for edge in graph:
        node1, node2 = edge
        if start_node in edge:
                if node1 == start_node:
                    next_node = node2
                else:
                    next_node = node1
                if not visited(next_node, path):
                        # neighbor node not on path yet
                        sub = [next_node]
                        sub.extend(path)
                        # explore extended path
                        findNewCycles(sub);
                elif len(path) > 2  and next_node == path[-1]:
                        # cycle found
                        p = rotate_to_smallest(path);
                        inv = invert(p)
                        if isNew(p) and isNew(inv):
                            cycles.append(p)

def invert(path):
    return rotate_to_smallest(path[::-1])

#  rotate cycle path such that it begins with the smallest node
def rotate_to_smallest(path):
    n = path.index(min(path))
    return path[n:]+path[:n]

def isNew(path):
    return not path in cycles

def visited(node, path):
    return node in path

main()

"""
10 13
1 2
1 8
1 6
2 3
2 6
5 0
5 7
6 7
6 5
7 1
8 5
8 0
9 5
"""


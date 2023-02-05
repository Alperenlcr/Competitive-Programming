x = input()
N = int(x.split()[0])
M = int(x.split()[1])
liste = [[0, 0] for i in range(N+M)]
liste2 = [[0, 0] for i in range(M)]

list1 = input().split()
list2 = input().split()

for i in range(M):
    liste[i] = [int(list2[i]), True]

for i in range(N):
    liste[i+M] = [int(list1[i]), False]


liste = sorted(liste)

count = 0
index = 0
for i in liste:
    if i[1]:
        print(index-count, end=" ")
        count += 1
    index += 1
def find_indices(list_to_check, item_to_find):
    indices = []
    for idx, value in enumerate(list_to_check):
        if value == item_to_find:
            indices.append(idx)
    return indices

maxx = 10**9 + 7
temp = input().split()
M = int(temp[0])
N = int(temp[1])
V = int(temp[2])
binary_matrix = []
for i in range(M):
    binary_matrix.append(list(map(int, input().split())))

dp = [[0 for col in range(N)] for row in range(M)]
vents = {}
for i in range(V):
    temp = input().split()
    try:
        vents[temp[2]+" "+temp[3]].append([int(temp[0]), int(temp[1])])
    except KeyError:
        vents[temp[2]+" "+temp[3]] = [[int(temp[0]), int(temp[1])]]



dp[0][0] = 1
j = 0
for i in range(1, M):
    if binary_matrix[i][j] == 1:
        dp[i][j] += dp[i-1][j]
        try:
            values = vents[str(i)+" "+str(j)]
            for value in values:
                dp[i][j] += dp[value[0]][value[1]]
        except KeyError:
            pass


i = 0
for j in range(1, N):
    if binary_matrix[i][j] == 1:
        dp[i][j] += dp[i][j-1]
        try:
            values = vents[str(i)+" "+str(j)]
            for value in values:
                dp[i][j] += dp[value[0]][value[1]]
        except KeyError:
            pass

#print( binary_matrix, went_in, went_out, dp, sep="\n")
for i in range(1, M):
    for j in range(1, N):
        if binary_matrix[i][j] == 1:
            dp[i][j] += dp[i-1][j] + dp[i][j-1]
            try:
                values = vents[str(i)+" "+str(j)]
                for value in values:
                    dp[i][j] += dp[value[0]][value[1]]
            except KeyError:
                pass
#print( binary_matrix , went_in, went_out, dp, sep="\n")
print(dp[M-1][N-1] % maxx)
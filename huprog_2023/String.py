def max_substring(X, Y):
    m = len(X)
    n = len(Y)

    result = 0
    end = 0

    length = [[0 for j in range(m)]for i in range(2)]
    currRow = 0
    for i in range(0, m + 1):
        for j in range(0, n + 1):
            if (i == 0 or j == 0):
                length[currRow][j] = 0
            
            elif (X[i - 1] == Y[j - 1]):
                length[currRow][j] = length[1 - currRow][j - 1] + 1
                
                if (length[currRow][j] > result):
                    result = length[currRow][j]
                    end = i - 1
            else:
                length[currRow][j] = 0

        currRow = 1 - currRow

    if (result == 0):
        return ""
    return X[end - result + 1 : end + 1]


r = []
X = input()
Y = input()
flag2 = True
if len(X) == len(Y):
    X += '&'
    flag2 = False
XR = X[::-1]
if len(Y) > len(X):
    print(-1)
else:
    flag = True
    while flag:
        pu = 0
        cut = max_substring(X, Y)
        cutr = max_substring(XR, Y)
        if len(cut) < len(cutr):
            cut = cutr
            pu += 1
        if cut == "":
            flag = False
        else:
            if pu == 0:
                r.append([X.index(cut)+1, X.index(cut)+len(cut)])
            else:
                r.append([len(X)-XR.index(cut), len(X)-XR.index(cut)-len(cut)+1])
            index = Y.index(cut)
            Y = Y[:index]+'@'+Y[index+len(cut):]
            # print(cut, Y)


    if not flag2:
        X = X[:-1]
        for i in range(len(r)):
            if r[i][0] < r[i][i]:
                r[i][0] -= 1
                r[i][1] -= 1
    if len(list(set(list(Y)))) == 1:
        r2 = []
        print(len(r))
        for i in r:
            temp = 0
            if i[0] > i[1]:
                temp += len(X)-i[1]
            else:
                temp += i[0]
            r2.append([temp]+i)
        r3 = sorted(r2, key=lambda x: x[0])
        for i in r3:
            print(i[1], i[2])
    else:
        print(-1)
from numpy import intp


def isSubsetSum(set, n, sum):
    # Base Cases
    if (sum == 0):
        return True
    if (n == 0):
        return False

    # If last element is greater than
    # sum, then ignore it
    if (set[n - 1] > sum):
        return isSubsetSum(set, n - 1, sum)

    # else, check if sum can be obtained
    # by any of the following
    # (a) including the last element
    # (b) excluding the last element
    return isSubsetSum(
        set, n-1, sum) or isSubsetSum(
        set, n-1, sum-set[n-1])


temp = input().split()
n = int(temp[0])
k = int(temp[1])
cost = 0
dizi = list(map(int, input().split()))

dizi.insert(0, 0)

# if dizi[0] != 1 and dizi[1] != 1: 
#     dizi.insert(0, 1)
#     cost += 1

j = 1
for i in range(1, k+1):
    if j < n and dizi[j] == i:
        # print(i, j)
        j += 1
    elif not isSubsetSum(dizi[:j], j, i):
        # print(i, j, dizi)
        dizi.insert(j, i)
        # print(i, j, dizi)
        j += 1
        cost += 1
        n += 1
print(cost)


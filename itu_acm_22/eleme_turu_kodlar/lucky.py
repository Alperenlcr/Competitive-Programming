
# 2**0 dan 2** 17 e kadar sayilar bunlardan kucuk sayilar ile elde edilemiyorsa 1 ekle
from math import log 

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
dizi = list(map(int, input().split()))
dizi = dizi[:n]
dizi = sorted(dizi)

ustler = [2**i for i in range(int(log(k, 2)+1))]
# print(ustler)
j = 0
count = 0

indexler = []

for j in range(len(ustler)):
    res = list(filter(lambda i: i > ustler[j], dizi))[0]
    if (res == dizi[-1]):
        for k in range(len(ustler)-j):
            indexler.append(dizi.index(res))
        break
    indexler.append(dizi.index(res))
# print(indexler)

for index, ust in zip(indexler, ustler):
    if sum(dizi[:index]) < ust:
    # if dizi[index-1] < ust//2:
        count += 1
        # print(ust)
    # res = next(x for x, val in enumerate(dizi) if val > ustler[j])
# for i in range(n):
#     if ustler[j] > dizi[i]:
#         print(dizi[:i])
#         j += 1
#         # if not isSubsetSum(dizi[:i], i, ustler[j]):
#         #     count += 1
#         #     j += 1

print(count)
# dizi = dizi[:n]
# dizi.append(0)
# dizi.append(k+1)
# dizi = sorted(dizi)

# count = 0

# for i in range(n+1):
#     for ust in ustler:
#         if ust > dizi[i] and ust < dizi[i+1]:
#             print(dizi[i], " - ", ust, " - ", dizi[i+1])
#             temp1 = ust + dizi[i]
#             if not temp1 in dizi and ust + dizi[i+1] <= k:
#                 #print(ust)
#                 count += 1
# print(count)


# # 1 6 16 50 75
# # 1 2 4 6 14 16 44 50 75

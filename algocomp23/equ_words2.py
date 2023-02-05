def keyer(word):
    return int("".join(sorted(list(map(str, map(word.count, list(set(word))))))))


def binarySearch(arr, l, r, x):
    # Check base case
    if r >= l:

        mid = l + (r - l) // 2
 
        # If element is present at the middle itself
        if arr[mid][1] == x:
            return mid

        # If element is smaller than mid, then it
        # can only be present in left subarray
        elif arr[mid][1] > x:
            return binarySearch(arr, l, mid-1, x)

        # Else the element can only be present
        # in right subarray
        else:
            return binarySearch(arr, mid + 1, r, x)

    else:
        # Element is not present in the array
        return -1
 

temp = input().split()
M = int(temp[0])
N = int(temp[1])
keys = []
words_M = []
res = []
for i in range(M):
    words_M.append(input())
for i in range(N):
    temp = input()
    keys.append((i, keyer(temp)))
    res.append([])

keys = sorted(keys, key = lambda x: x[1])
#print(keys)
for i in range(M):
    search_key = keyer(words_M[i])
    index = binarySearch(keys, 0, len(keys)-1, search_key)
    if index != -1:
        res[keys[index][0]].append(i)

for r in res:
    if r != []:
        print(*r)

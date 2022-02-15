def BinarySearch(arr, low, high, x):
     
    # Check base case
    if high >= low:
 
        mid = (high + low) // 2
 
        # If element is present at the middle itself
        if arr[mid][0] == x:
            return mid

        # If element is smaller than mid, then it can only
        # be present in left subarray
        elif arr[mid][0] > x:
            return BinarySearch(arr, low, mid - 1, x)
 
        # Else the element can only be present in right subarray
        else:
            return BinarySearch(arr, mid + 1, high, x)
 
    else:
        # Element is not present in the array
        return -1


def BinarySearch2(arr, low, high, x):
     
    # Check base case
    if high >= low:
 
        mid = (high + low) // 2
 
        # If element is present at the middle itself
        if arr[mid][1] == x:
            return mid
 
        # If element is smaller than mid, then it can only
        # be present in left subarray
        elif arr[mid][1] > x:
            return BinarySearch2(arr, low, mid - 1, x)
 
        # Else the element can only be present in right subarray
        else:
            return BinarySearch2(arr, mid + 1, high, x)
 
    else:
        # Element is not present in the array
        return -1


l = int(input())
d = []
d2 = []

for i in range(l):
    temp = input().split()
    d.append([temp[0], temp[1]])
    d2.append([temp[0], temp[1]])

    #d[temp[0]] = temp[1]

# baslangic bul
baslangic = ""

d = sorted(d)
d2 = sorted(d2, key = lambda x: x[1])

for kv in d:
    if BinarySearch2(d2, 0, l-1, kv[0]) == -1:
        print(kv[0], end=" ")
        baslangic = kv[1]
        break

i=0
count = 1
print(baslangic, end=" ")   

while count < l:
    i = BinarySearch(d, 0, l-1, baslangic)
    baslangic = d[i][1]
    count += 1
    print(baslangic, end=" ")

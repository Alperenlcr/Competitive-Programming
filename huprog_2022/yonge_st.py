def findLen(A, n, k, ch):
    maxlen = 1
    cnt = 0
    l = 0
    r = 0
    rr = [1,1]
    diff = 0
    # traverse the whole string
    while r < n:

        # if character is not same as ch
        # increase count
        if A[r] != ch:
            cnt += 1

        # While count > k traverse the string
        # again until count becomes less than k
        # and decrease the count when characters
        # are not same
        while cnt > k:
            if A[l] != ch:
                cnt -= 1
            l += 1

        # length of substring will be rightIndex -
        # leftIndex + 1. Compare this with the
        # maximum length and return maximum length
        maxlen = max(maxlen, r - l + 1)
        if r - l > diff:
            rr = [l, r]
            diff = r-l
        r += 1

    return rr

# function which returns
# maximum length of substring
def answer(A, n, k):
    r = [[1,1], 1]
    maxlen = 0
    B = set(A)
    for i in B:
        temp = findLen(A, n, k, i)
        diff = temp[1] - temp[0]
        if diff > maxlen:
            r = [temp, i]
            maxlen = diff
    
    return r


row1 = input().split()
n = int(row1[0])
k = int(row1[2])
B = list(map(int, input().split()))
r = answer(B, n, k)
count = 0
index = 0
arr = B[r[0][0] : r[0][1]+1]
while arr[index] != r[1]:
    count += 1
    index += 1
index = len(arr)-1
while arr[index] != r[1]:
    count += 1
    index -= 1

if r[0][1] - r[0][0] - count == 0:
    print(1)
else:
    print(r[0][1] - r[0][0] - count)
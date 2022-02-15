"""
N = int(input())
string = input()
A = list(map(int,string.split()))
A.sort()
x = A[0] + A[-1]
z = N // 2
y = A[z] + A[z-1]
print(x-y)
"""
A = [1,2,3,4,5]
print(A[0])
print(A[-1])
print(A[:-1])
print(A[4])

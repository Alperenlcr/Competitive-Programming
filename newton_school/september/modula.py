X, P, K = map(int, input().split())
oz_A = [(i*X)%P for i in range(1,P)]
i = 1
while K > P:
    oz_A.remove(i)
    i+=1
print(oz_A(K))
# 1 2 3 4 5 6 
# 2 3 4 5 6
# 3 4 5 6
# 4 5 6 
# 5 6
# 6
# 
# 2 4 6 1 3 5
# 3 6 2 5 1 4
# 4 1 5 2 6 3
# 11
# 2 4 6 8 10 1 3 5 7 9
# 30 / 11 = 2
# K 11      oz_A[K]
# K-= 11 oz_A.pop(min(oz_A)) 
# 
#
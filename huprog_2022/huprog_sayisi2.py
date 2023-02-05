list = list(map(int, input().split()))

A = list[0]
T = list[1]


def two_six_count(D):

    s = str(D)
    return s.count("2") + s.count("6")


    

def solve(A,T):
    origin = [two_six_count(x) for x in range(A,A+T)]

    temp = [two_six_count(x) for x in range(A+1, A+1+T)]
    count = A+1
    while True:
        if temp == origin:
            return count
        count += 1
        temp.pop(0)
        temp.append(two_six_count(count+T-1))



print(solve(A,T))

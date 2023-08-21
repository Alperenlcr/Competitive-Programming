n = int(input())
m = int(input())
SoC = list(map(int, input().split()))
IoC = list(map(int, input().split()))
SoB = list(map(int, input().split()))

SoC.append(100000)
IoC.append(100000)
castles = sorted(zip(SoC, IoC))
shots = sorted(SoB)

i = 0
maxx = 0
summ = 0
for shot in shots:
    while castles[i][0]<=shot:
        if maxx < castles[i][1]:
            maxx = castles[i][1]
        i += 1
    summ += maxx

print(summ)

"""
5
4
6 8 2 11 4
30 40 10 5 20
1 5 6 15

"""
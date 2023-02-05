t = int(input())
dizi1 = list(map(int, input().split()))
dizi2 = list(map(int, input().split()))
sum = 0
for j in range(t):
    d1 = dizi1[j] + dizi2[j] - (dizi1[j] * dizi2[j])
    d2 = dizi1[j]
    d3 = dizi2[j]
    sum += max([d1, d2, d3, 0])
print(sum)
def remove_return_index(dizi:list, value:int):
    i = 0
    for ele in dizi:
        if ele == value:
            dizi.pop(i)
            return i
        i += 1


n = int(input())
dizi = [int(item) for item in input().split()]
# dizi = list(map(int, input().split()))
cost = 0

# for i in range(n, 1, -1):
i = n
while i != 1:
    t1 = remove_return_index(dizi, i)
    # t1 = dizi.index(i)
    t2 = i-1
    if t1 != t2:
        cost += (t2-t1)*i - sum(dizi[t1:t2]) % (10**9 + 7)
        # dizi.remove(i)
    i -= 1

print(cost)
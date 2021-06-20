"""
def remove(array):
    remove = set()
    for i in array:
        for j in array:
            if j % i == 0 and j != i:
                remove.add(j)
    return set(array).difference(remove)


def asal_carpan_liste(sayi):
    i = 2
    liste = []
    carpan = []

    while i < sayi:

        if sayi % i == 0:
            liste.append(i)
        i += 1
    del i
    for i in liste:
        bitir = True
        for a in liste:
            if (bitir):
                if (i == a):
                    carpan.append(i)
                elif (i % a == 0):
                    bitir = False

    return carpan


from itertools import combinations
import sys
sys.setrecursionlimit(2000)


def solve(full, count=0):
    if count == 1000:
        full.sort()
        return full
    comb = combinations(full, 2)
    for item in comb:
        position = abs(item[0] - item[1])
        if position not in full:
            full.append(position)
            if count % 2 == 1:
                full.sort()
            else:
                full.sort()
                full.reverse()
            return solve(full, count + 1)
    full.insert(0, 0)
    full.sort()
    return full


baslangic = int(input())
liste=list(map(int, input().split()))

if baslangic < 10000:
    count = 0
    for i in range(baslangic):
        count += 1
        comb = combinations(liste, 2)
        for item in comb:
            position = abs(item[0] - item[1])
            if position not in liste:
                liste.append(position)
                liste.sort()
                break
    if count % 2 == 0:
        print("Bilge")
    else:
        print("Burak")
else:
    liste.sort()
    maxd = liste[-1]
    last = solve(liste)

    # basinda 0 varsa say
    if last[0] == 0:
        if (len(last)-1 - baslangic) % 2 == 0:
            print("Bilge")
        else:
            print("Burak")
    # yoksa
    else:
        asiller = list(remove(last[:]))
        asiller.sort()
        total = 0
        for i in asiller:
            if maxd // i == maxd / i:
                total -= 1
            total += maxd // i
            if total > maxd:
                total = maxd
                break
        if (total - baslangic) % 2 == 0:
            print("Bilge")
        else:
            print("Burak")
"""
"""
dolu = [15, 12, 10]
dolu.sort()
dolu.reverse()
count = 0
broke = 15
while broke:
    try:
        dolu.append(dolu[count] - dolu[count+1])
        dolu = set(dolu)
        dolu = list(dolu)
        dolu.sort()
        dolu.reverse()
    except IndexError:
        broke -= 1
        count = 0
    count += 1
print(dolu)
print(count)
"""
"""
from itertools import combinations
import sys
sys.setrecursionlimit(10**6)


def solve(full, count=0):
    comb = combinations(full, 2)
    for item in comb:
        position = abs(item[0] - item[1])
        if position == 1:
            return "Bilge" if max(full) % 2 == 0 else "Burak"
        if position not in full:
            return solve(full, count + 1)
    if count % 2 == 0:
        return "Bilge"
    return "Burak"

baslangic = int(input())
liste=list(map(int, input().split()))
print(solve(liste))
"""
"""
print("a")
boy = int(input())
tiplist = []
mesafelist = []
arr = input().split()
for i in range(0, 2*(boy-1), 2):
    tiplist.append(arr[i])
    mesafelist.append(int(arr[i+1]))

dongu = int(input())
couples1 = []
couples2 = []

for i in range(dongu):
    temp = list(map(int, input().split()))
    if temp[1] < temp[0]:
        tempe = temp[1]
        temp[1] = temp[0]
        temp[0] = tempe
    couples1.append(temp[0])
    couples2.append(temp[1])

harcananbenzin = []
for i, j in zip(tiplist, mesafelist):
    if i == 'b':
        harcananbenzin.append(j * (5.8 / 100))
    elif i == 'o':
        harcananbenzin.append(j * (7.2 / 100))
    elif i == 'h':
        harcananbenzin.append(j * (8.6 / 100))

for first, last in zip(couples1, couples2):
    counter = 0
    tank = 50
    for i in range(first - 1, last - 1):
        if harcananbenzin[i] > 50:
            counter = -1
            break
        elif harcananbenzin[i] <= tank:
            tank -= harcananbenzin[i]
        else:
            counter += 1
            tank = 50 - harcananbenzin[i]
    print(counter)
"""
"""
boy = int(input())
arr = input().split()
tek = True
harcanan_benzin = []
for i in range(0, 2*(boy-1)):
    if tek:
        tip = input("%c")
        tek = False
    else:
        mesafe = input("%f")
        tek = True
        if tip == 'b':
            harcanan_benzin.append(mesafe * (5.8 / 100))
        elif tip == 'o':
            harcanan_benzin.append(mesafe * (7.2 / 100))
        elif tip == 'h':
            harcanan_benzin.append(mesafe * (8.6 / 100))

    mesafelist.append(int(arr[i+1]))

"""
"""
def solve():
    a = [1, 3, 2, 5, 2, 5, 4, 3, 4, 1]
    for i in range(len(a) - 1):
        if a[i] != 0:
            print(a)
            print(a[:i:-1])
            print(a[:i:-1].index(a[i]))
            print(len(a)-i-a[:i:-1].index(a[i])-2)
            a[len(a)-(a[:i:-1].index(a[i]))-1] = 0
            a[i] = 0
solve()
"""
from itertools import combinations
sozluk = {}
string = input()
kume = set(string)
for i in kume:
    sozluk[i] = string.count(i)
# print(sozluk)
toplam = sum(sozluk.values())
denge = toplam / 2
# print(toplam)
x = []
min = float(toplam)
# print(sozluk.values())
# print(len(sozluk.values()))
alt_sinir = int(len(sozluk.values())/4)
ust_sinir = int(len(sozluk.values())*3/4)
if alt_sinir < 50:
    alt_sinir = 0
if ust_sinir < 50:
    ust_sinir = len(sozluk.values())
for i in range(alt_sinir, ust_sinir):
    # print(i)
    tuple_list = list(combinations(sozluk.values(), i))
    # print(tuple_list)
    for j in tuple_list:
        kesirli = j
        comp = float(sum(kesirli))
        #print(comp,"<<<<<<<<<", min, "and", comp, ">>>>>>>>>>>>>>>>>",denge)
        if (comp < min and comp >= denge):
            # print("girdim")
            min = float(sum(kesirli))
            x = list(kesirli)
# print(x)
print(sum(x)*(toplam-sum(x)))
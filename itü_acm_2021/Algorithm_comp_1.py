"""
def solve(string):
    number = list(string.split())
    if len(set(number)) == 1:
        return len(number)
    calc = 0
    tek = set()
    for i in number:
        if number.count(i) % 2 == 0:
            calc += 1
        if number.count(i) % 2 != 0 and number.count(i) > 2:
            tek.add(i)
            calc += 1
    cevap = calc - len(tek)
    if cevap % 2 == 0:
        return cevap + 1
    return cevap


n = input()
string = input()
print(solve(string))
"""
# 1 5 2 4 8 3 2 1 4 6 5 3 5
# 11
# 15243834251

# 1 4 3 4 2 5 5 5
# 45354
# 5 5 5 5 5
"""
def solve(string):
    number = list(map(int, string.split()))
    number = [x for x in number if number.count(x) != 1]
    kume = set(number)
    for i in kume:
        if number.count(i) % 2 == 1:
            number.pop(number.index(i, number.count(i) // 2 + 1))
    # buraya geldiginde cift sayida terimlerden olusan dizin var
    uzaklik = []
    for i in range(len(number) - 1):
        if number[i] != 0:
            ekle = len(number) - i - number[:i:-1].index(number[i]) - 2
            son = len(number) - (number[:i:-1].index(number[i])) - 1
            number[son] = 0
            number[i] = 0
            if ekle % 2 == 0 and 0 not in number[i+1:son]:
                uzaklik.append(len(number) - i - number[:i:-1].index(number[i]) - 2)

    return len(set(uzaklik)) * 2 + 1


n = input()
string = input()
print(solve(string))
"""
# 1 1 11 2 2 11 12 3 3 4 4 12

# 1 2 3 4 5 1 2 3 5 4
# 1 4 2 5 1 4 5 3 4 1 2 5 4 1 2 3 5 4 5
# 1 4 2 5 1 4 5 3 4 1 2 5 4 1 2 3 5 4 5
# 1 4 2 5 1 4 5 3 1 4 1 2 3 5 4 5
# 1 4 5 1 3 4 1 2 5 4 1 2 3 5 4 5

"""
  calc = 0
    tek = set()
    for i in number:
        if number.count(i) % 2 == 0:
            calc += 1
        if number.count(i) % 2 != 0 and number.count(i) > 2:
            tek.add(i)
            calc += 1
    cevap = calc - len(tek)
    if cevap % 2 == 0:
        return cevap + 1
    return cevap
"""

"""
ilk_kale = int(input())
ilk_fetih = list(map(int, input().split()))
liste_uzunlugu = max(*ilk_fetih)
sayi_dogrusu = [0] * liste_uzunlugu

for i in ilk_fetih:
    sayi_dogrusu[i-1] = 1

name = 0
broke = True

while broke:
    broke = False
    for i in reversed(range(liste_uzunlugu)):
        if sayi_dogrusu[i] == 1:
            for j in reversed(range(i)):
                if sayi_dogrusu[j] == 1 and sayi_dogrusu[i - j - 1] != 1:
                    sayi_dogrusu[i - j - 1] = 1
                    name += 1
                    broke = True

if name % 2 == 1:
    print("burak")
else:
    print("bilge")
"""
"""
# 3 5 15 1 1 1 1 1
n = input()
sutun = list(map(int, input().split()))
toplam = sum(sutun)

for x in range(2, toplam+1):
    if toplam % x == 0:
        print(x)
        break
"""

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
sys.setrecursionlimit(10000)



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

baslangic = 2
liste=[3, 4645]
liste.sort()
maxd = liste[-1]
last = solve(liste)
print(last)

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
    print(asiller)
    total = 0
    for i in asiller:
        if maxd // i == maxd / i:
            total -= 1
        total += maxd // i
        if total >= maxd:
            total = maxd
            break
    print(total)
    if (total - baslangic) % 2 == 0:
        print("Bilge")
    else:
        print("Burak")


"""
"""
dicti = {1: 180}
for i in range(3, 1000):
    aci = ((180-(360/i))/(i-2))
    if aci % 1 == 0:
        dicti[i] = int(aci)
dongu = int(input())
for i in range(dongu):
    sorulan = int(input())
    if sorulan > 180 or sorulan < 1:
        print(-1)
        break
    for key, value in dicti.items():
        if sorulan % value == 0:
            print(key)
            break
"""
# verilen aci varsa cevap keyi yoksa aciyi bolen en buyuk valuenin keyi
"""
until = 31623
asallar = [n for n in range(2, until) if all(n % m != 0 for m in range(2, n-1))]
print(len(asallar))
asallar = [n for n in range(2, until) if all(n % m != 0 for m in range(2, n-1))]
print(asallar)
total = 0
asallar.insert(0, 1)
for i in asallar:
    if i in last:
        total += maxd//i
        print(i)
    if total > maxd:
        total = maxd
        break
print(total)
"""


"""
until = 1000
degerler = list(map(asal_carpan_liste, last[:10]))
print(degerler)
asiller = []
for i in range(len(degerler)):
    for j in degerler[i]:
        if j not in asiller:
            asiller.append(j)
print("*", asiller)
"""
sozluk = {}
string = "asdhcvbaısvdascasdqwcasfvsvewqwefpop"
ilk = string[0]
son = string[-1]
if ilk == son:
    pass
else:
    kume = set(string)
    for i in kume:
        sozluk[i] = string.count(i)
    # print(sozluk)
    yc = sozluk[ilk]
    xc = sozluk[son]
    toplam = sum(sozluk.values())
    denge = toplam / 2
    # print(toplam)
    x = []
    min = float(toplam)
    from itertools import combinations
    # print(sozluk.values())
    # print(len(sozluk.values()))
    for i in range(int(len(sozluk.values())/4), int(len(sozluk.values())*3/4)):
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












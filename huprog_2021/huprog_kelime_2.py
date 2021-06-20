def comb(a, b):
    ust = 1
    for i in range(b):
        ust *= a
        a -= 1
    alt = 1
    while b > 0:
        alt *= b
        b -= 1
    return int(ust/alt)


# grup yapisi [suanki harf tekrari, baslangic harf tekrari, ekleme olursa yeni carpan, suanki carpan]
def gruplari_olusturma(kelime):
    gruplar = []
    eski = kelime[0]
    harf_sayisi = len(kelime)
    i = 0
    while i < harf_sayisi:
        yeni_grup = [0, 0, 1, 1]
        while i <= harf_sayisi:
            if i != harf_sayisi and eski == kelime[i]:
                yeni_grup[0] += 1
                yeni_grup[1] += 1
                if i != harf_sayisi:
                    eski = kelime[i]
                i += 1
            else:
                yeni_grup[2] = comb(yeni_grup[0]+1, yeni_grup[1])
                yeni_grup[3] = 1
                gruplar.append(yeni_grup)
                if i != harf_sayisi:
                    eski = kelime[i]
                break
    return gruplar


def solution(gruplar, n, carpim, harf_eklenecek_grup_indexi=1, deneme=1):
    i = 0
    for grup in gruplar:
        temp = 1
        temp = (carpim/grup[3]) * grup[2]
        if temp > deneme:
            deneme = temp
            harf_eklenecek_grup_indexi = i
        i += 1
    carpim = deneme
    gruplar[harf_eklenecek_grup_indexi][0] += 1
    gruplar[harf_eklenecek_grup_indexi][3] = gruplar[harf_eklenecek_grup_indexi][2]
    gruplar[harf_eklenecek_grup_indexi][2] = comb(gruplar[harf_eklenecek_grup_indexi][0] + 1, gruplar[harf_eklenecek_grup_indexi][1])

    if n >= carpim:
        solution(gruplar, n, carpim)
    else:
        print(sum(grup[0] for grup in gruplar))


kelime = input()
n = int(input())

gruplar = gruplari_olusturma(kelime)

if n == 1:
    print(len(kelime))
elif n == 2:
    print(len(kelime) + 1)
else:
    solution(gruplar, n, 1)

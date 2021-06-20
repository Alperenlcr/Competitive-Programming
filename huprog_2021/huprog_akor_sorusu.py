def yuz_islemleri(standart, karsilastiracak, akor_sayisi):
    net = 0
    for i in range(akor_sayisi):
        if standart[i] + 50 < karsilastiracak[i]:
            net -= 1
        if standart[i] - 50 > karsilastiracak[i]:
            net += 1
    for i in range(akor_sayisi):
        karsilastiracak[i] += 100 * net


def yirmi_elli_islemleri(standart, karsilastiracak, akor_sayisi, sure, sonuc):
    cost = 0
    for i in range(akor_sayisi):
        fark = abs(standart[i] - karsilastiracak[i])
        cost += fark // 50
        fark %= 50
        cost += fark // 21
    if cost <= sure:
        sonuc += 500
    return sonuc


uclu = list(map(int, input().split()))
kisi = uclu[0]
akor_sayisi = uclu[1]
sure0 = uclu[2]
sure = sure0
sonuc = 0
sonuc_eski = 0

standart = list(map(int, input().split()))

for i in range(kisi):
    karsilastiracak = list(map(int, input().split()))
    yuz_islemleri(standart, karsilastiracak, akor_sayisi)
    sonuc = yirmi_elli_islemleri(standart, karsilastiracak, akor_sayisi, sure, sonuc)
    if sonuc_eski != sonuc:
        sure += sure0
    sonuc_eski = sonuc

print(sonuc)
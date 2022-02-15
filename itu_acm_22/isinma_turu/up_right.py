string = input()
harfler = list(set(string))
harfler.sort()
fhs = len(harfler)   #farkli_harf_sayisi

max_alan = 0

for i in range(1, fhs**2 - 1):     # 16

    yukseklik = 0
    toplam = 0

    binary = bin(i).replace('0b','')
    x = binary[::-1] #this reverses an array
    while len(x) < fhs:
        x += '0'
    binary = x[::-1]

    if binary[harfler.index(string[0])] == '0':
        continue

    for j in string:        # 3*10^5
        if binary[harfler.index(j)] == '0':     # yatay
            print("yan")
            toplam += yukseklik
        else:       # dikey
            print("dik")
            yukseklik += 1
    print(binary, i, string, toplam, yukseklik)
    if max_alan < toplam:
        max_alan = toplam

print(max_alan)

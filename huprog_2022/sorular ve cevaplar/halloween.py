n = int(input())
s = input()
liste = list(map(int, s.split()))
toplam = sum(liste)
toplam += int(input())

if toplam % n == 0:
    if toplam / n < max(liste):
        print(0)
    else:
        print(1)
else:
    print(0)

def sqr_take(number):
    root = number**0.5
    if root % 1 >= 0.5:
        root += 1
    if int(root)**2 >= number:
        return -root
    else:
        return root


counter = 2
kelime = input()
n = int(input())
uzunluk = len(kelime)
if uzunluk == 1:
    print(n+1)
    exit(1)

dizi = [-2 for x in range(uzunluk)]

donut = int(sqr_take(n))
if donut < 0:
    dizi[0] = -donut
    dizi[1] = -donut
else:
    dizi[0] = donut
    dizi[1] = donut+1

while -2 in dizi:
    donut = int(sqr_take(max(dizi)))
    if donut == 1:
        break

    index = dizi.index(max(dizi))
    if donut < 0:
        dizi[index] = -donut
        dizi[counter] = -donut
    else:
        dizi[index] = donut
        dizi[counter] = donut + 1
    counter += 1

sum = 0
for i in dizi:
    if i != -2:
        sum += i - 1
print(dizi)
print(sum+uzunluk)

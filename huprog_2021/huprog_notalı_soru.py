def sayilara_donustur(satir_gruplu):
    sayilar_dizisi = []

    for i in satir_gruplu:
        dizi = []
        sum = i[0]
        for y in i[1:]:
            sum += y
            index = 0
            for k in notalar:
                if sum in k:
                    dizi.append(index+1)
                    sum = ""
                index += 1
        sayilar_dizisi.append(dizi)
    return sayilar_dizisi


def solution(A, B):
    max = 0
    counter = 0
    for a, b in zip(A, B):
        if len(a) < len(b):
            sinir = len(a)
        else:
            sinir = len(b)

        for i in range(sinir):
            if a[i] == b[i]:
                counter += 1
            else:
                if max < counter:
                    max = counter
                counter = 0
        if len(a) != len(b):
            if max < counter:
                max = counter
            counter = 0
    print(max)


sayi = int(input())
birinci_satir = input()
ikinci_satir = input()

notalar = [["do", "#si"], ["#do", "bre"], ["re"], ["#re", "bmi"],
           ["mi", "bfa"], ["fa", "#mi"], ["#fa", "bsol"], ["sol"],
           ["#sol", "bla"], ["la"], ["#la", "bsi"], ["si", "bdo"]
           ]

if sayi == 1:
    if birinci_satir == ikinci_satir:
        print(1)
    else:
        print(0)
else:
    A = sayilara_donustur(birinci_satir.split())
    B = sayilara_donustur(ikinci_satir.split())

    solution(A, B)
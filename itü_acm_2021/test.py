"""
imp = []
for i in range(10):
    tasks = list(map(int, input().split()))
    task = set(tasks)
    for j in task:
        if tasks.count(j) > 2:
            imp.append(i+1)
print(*imp)
"""
"""
Movies = {}
x, y = input().rsplit(" ", 1)
print(x, y, sep="***")
Movies[x] = y
print(Movies)
"""
"""
Movies = {"Pulp Fiction" : 9, "Goodfellas" : 8}
while True:
    operation = input()
    if operation == '0':
        for movie,score in Movies.items():
            print(movie, score)
        break
    elif operation == '1':
        l = input().rsplit(" ", 1)
        Movies[l[0][0]] = int(l[0][1])  
    elif operation == '2':
        movie = input()
        if movie not in Movies.keys():
            print("You haven't added this movie")
        else:
            print(Movies[movie])

"""
"""
string = "          everybody will die one day"

def fact(num):
    if num == 1:
        return 1
    return num * fact(num-1)

def count_char(word:str):
    return len(word)

l = list(map(count_char, string.split()))
print(l)
wanted = 1
k = set(l)
for i in k:
    wanted *= fact(l.count(i))
print(wanted)
print(fact(len(l)))
print(wanted/fact(len(l)))
"""
"""
def taban(yuzde, para):
    return para - (para * yuzde / 100)

def tavan(yuzde, para):
    return para + (para * yuzde / 100)


cesit, para = input().split()
para = float(para)
if cesit == "Z":
    tavan = tavan(20, para)
    taban = taban(20, para)
elif cesit == "N":
    tavan = tavan(15, para)
    taban = taban(15, para)
elif cesit == "T":
    tavan = tavan(10, para)
    taban = taban(10, para)
    
if para < 20:
    print("{:.2f} {:.2f}".format(tavan, taban))
elif para < 50:
    print("{:.2f} {:.2f}".format(tavan, taban))
elif para < 100:
    print("{:.1f}5 {:.1f}5".format(tavan, taban))
else:
    print("{:.1f} {:.1f}".format(tavan, taban))
"""
"""
# 0 2 3 1
# 1 0 2 0
# 0 2 0 1
# 3 1 2 0
N = int(input())
mtr = []
puanlar = []
for i in range(N):
    satir = input()
    l = map(int, satir.split())
    mtr.append(list(l))
    puanlar.append(0)

for i in range(N):
    for k in range(N):
        if mtr[i][k] != 0:
            puanlar[i] += 1
for k in range(N):
    for i in range(N):
        if mtr[i][k] != 0:
            puanlar[k] += N + 1 - mtr[i][k]
print(puanlar.sort)

print(puanlar)
print(mtr)
"""

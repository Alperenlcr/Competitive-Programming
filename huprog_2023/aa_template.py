temp = input().split()
n = int(temp[0])
m = int(temp[1])
questions = list(map(int, input().split()))

dic = {}
for q in questions:
    try:
        if type(dic[q]) == int:
            dic[q] += 1
    except KeyError:
            dic[q] = 0
    if len(dic) == n:
        print("Y", end="")
        for key in dic:
            dic[key] -= 1
            if dic[key] == 0:
                 dic.pop(key)
    else:
        print("N", end="")


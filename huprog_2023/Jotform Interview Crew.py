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
            dic[q] = 1
    if len(dic) == n:
        print("Y", end="")
        temp = list(dic.keys())
        for key in temp:
            if dic[key] == 1:
                 dic.pop(key)
            else:
                dic[key] -= 1
    else:
        print("N", end="")

"""

3 11
2 3 1 2 2 2 3 2 2 3 1

4 11 
2 3 4 3 2 1 4 1 2 2 3

"""
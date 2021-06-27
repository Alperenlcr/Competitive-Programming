def solution(x, f):
    y = f
    while y != 1 and x%y != 0:
        y -= 1
    if y == 1:
        return (x, f, True)
    else:
        x += y
        f -= y
        return (x, f, False)


string = input()
l = string.split()
a = int(l[0])
b = int(l[1])
if a>=b-1 or a*2<=b:
    print("No")
else:
    f = b-a
    while f != 0:
        bo = solution(a, f)
        a = bo[0]
        f = bo[1]
        if bo[2]:
            break
    if f == 0:
        print("Yes")
    else:
        print("No")




"""
def solution(x, f):
    y = f
    i = 0
    asal = [2,3,5,7,11,13,17,19,21,23,29]
    while y != 1 and x%y != 0:
        y -= 1
        if i<11 and y > x//asal[i]:
            y = x//asal[i]
            i += 1
    if y == 1:
        return (x, f, True)
    else:
        x += y
        f -= y
        return (x, f, False)
"""
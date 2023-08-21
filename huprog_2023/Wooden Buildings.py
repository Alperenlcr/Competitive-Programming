from math import prod

temp = input().split()
A = int(temp[0])
B = int(temp[1])
C = int(temp[2])

a = list(reversed(sorted(list(map(int, input().split())))))
b = list(reversed(sorted(list(map(int, input().split())))))
c = list(reversed(sorted(list(map(int, input().split())))))

r = 0
mulA = prod(a)
mulB = prod(b)
mulC = prod(c)
while len(a) != 0 and len(b) != 0 and len(c) != 0:
    if mulA > mulB and mulC > mulB:
        t1 = a.pop(0)
        t2 = c.pop(0)
        r += t1 * t2
        mulA /= t1
        mulC /= t2
    elif mulA > mulB and mulB > mulC:
        t1 = a.pop(0)
        t2 = b.pop(0)
        r += t1 * t2
        mulA /= t1
        mulB /= t2
    else:
        t1 = b.pop(0)
        t2 = c.pop(0)
        r += t1 * t2
        mulB /= t1
        mulC /= t2

if len(a) == 0:
    t = min(len(b), len(c))
    for i in range(t):
        r += b[i]*c[i]
elif len(b) == 0:
    t = min(len(a), len(c))
    for i in range(t):
        r += a[i]*c[i]
else:
    t = min(len(a), len(b))
    for i in range(t):
        r += a[i]*b[i]

print(r)
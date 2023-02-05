n = int(input())
string = input()
z = []
e = []
r = []
o = []
count = 0
for i in string:
    if i == 'z':
        z.append(count)
    elif i == 'e':
        e.append(count)
    elif i == 'r':
        r.append(count)
    elif i == 'o':
        o.append(count)
    count += 1

z_c = []
e_c = []
r_c = []
#o_c = [1 for i in range(len(o))]
for i in r:
    # find first number index bigger than i
    if max(o) < i:
        r_c.append(0)
        continue
    c = 0
    for j in range(len(o)):
        if i < o[j]:
            c = j
            break

    r_c.append(len(r)-c)


for i in e:
    # find first number index bigger than i
    if max(r) < i:
        e_c.append(0)
        continue
    c = 0
    for j in range(len(r)):
        if i < r[j]:
            c = j
            break

    e_c.append(sum(r_c[j:]))

for i in z:
    # find first number index bigger than i
    if max(e) < i:
        z_c.append(0)
        continue
    c = 0
    for j in range(len(e)):
        if i < e[j]:
            c = j
            break

    z_c.append(sum(e_c[j:]))

modd = 10**9 + 7

r = 0
for i in z_c:
    r += i
    r %= modd

print(r)

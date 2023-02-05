def toplam(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    return (n*(n+1))/2


N = int(input())
temp = input().split()
x = int(temp[0])
y = int(temp[1])
dir = int(input())

if dir == 1:    # yukari
    h = x+1
    result = h**2
    if y < h:
        result -= toplam(h-y-1)
    if N-1 < y+h-1:
        result -= toplam((y+h-1)-(N-1))
    print(int(result))

elif dir == 3:  #asagi
    x = N-1-x           # tek farkli
    h = x+1
    result = h**2
    if y < h:
        result -= toplam(h-y-1)
    if N-1 < y+h-1:
        result -= toplam((y+h-1)-(N-1))
    print(int(result))

elif dir == 0:  #sola
    h = y+1
    result = h**2
    if x < h:
        result -= toplam(h-x-1)
    if N-1 < x+h-1:
        result -= toplam((y+h-1)-(N-1))
    print(int(result))

elif dir == 2:  #saga
    y = N-1-y           # tek farkli
    h = y+1
    result = h**2
    if x < h:
        result -= toplam(h-x-1)
    if N-1 < x+h-1:
        result -= toplam((y+h-1)-(N-1))
    print(int(result))
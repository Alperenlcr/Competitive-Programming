t = input()
array = list(map(int, input().split()))
array = sorted(array)
#print(array, len(array))
l = int(len(array)/2)
minn = array[0:l]
maxx = array[l:]
print(sum(maxx)-sum(minn))

from bisect import bisect_left


x = input()
list1 = list(map(int, input().split()))
list2 = list(map(int, input().split()))
list1 = sorted(list1)
list2 = sorted(list2)

for i in list2:
    print(bisect_left(list1, i), end=" ")

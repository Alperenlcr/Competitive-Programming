import bisect

def insert_pair(pairs, new_pair):
    pos = bisect.bisect_left(pairs, new_pair)
    pairs.insert(pos, new_pair)

def dig(coders_id_based, n):
    i = n-1
    id = coders_id_based[i][0]
    while coders_id_based[i][0] == id:
        i -= 1
    i += 1
    a, b = coders_id_based[i][0], coders_id_based[i][1]
    coders_id_based.pop(i)
    return a, b

temp = input().split()
n = int(temp[0])
m = int(temp[1])
middle_food_id = int(temp[2])
temp = list(map(int, input().split()))
coders_id_based = sorted([[temp[i], i+1] for i in range(n)], key = lambda x: x[0])
print(coders_id_based)
for i in range(m):
    temp = input().split()
    type = int(temp[0])
    new_food_id = int(temp[1])

    if type == 1:
        index = coders_id_based[0][1]
        removed = coders_id_based[0][0]
        coders_id_based.pop(0)
        insert_pair(coders_id_based, [middle_food_id, index])
        middle_food_id = new_food_id
        print(removed, index)
    else:
        print(middle_food_id)
        middle_food_id, index = dig(coders_id_based, n)
        insert_pair(coders_id_based, [new_food_id, index])


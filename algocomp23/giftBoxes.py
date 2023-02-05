# temp = input().split()
# n = int(temp[0])
# x = int(temp[1])
# y = int(temp[2])
# boxes = []
# for i in range(n):
#     temp = input().split()
#     if x > int(temp[0]) and y > int(temp[1]):
#         boxes.append([temp[0], temp[1]])

pair_pool = [[4, 4],[5, 6],[6, 5],[8, 6],[9, 9]]
starting_pair = [3, 3]

# filter the pairs that are greater than starting pair
valid_pairs = [pair for pair in pair_pool if pair[0] > starting_pair[0] and pair[1] > starting_pair[1]]

# sort the valid pairs based on their first and second elements
valid_pairs = sorted(valid_pairs, key=lambda pair: (pair[0], pair[1]))



max_count = len(valid_pairs)

print(valid_pairs) # Output: [[4, 4], [5, 6], [8, 6], [9, 9]]
print(max_count) # Output: 4

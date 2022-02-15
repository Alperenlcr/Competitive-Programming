T = int(input())
for i in range(T):
    N = int(input())
    largest_subset = [x for x in range((N//2)+1, N+1)]
    x = (N//2)
    while x > 0:
        if x*2 not in largest_subset:
            largest_subset.append(x)
        x -= 1
    print(len(largest_subset))
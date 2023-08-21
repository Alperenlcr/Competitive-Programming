def solve(s):
    left = len(s)//3
    right = 2*left
    if len(s)%3 == 2:
        right += 1
    # print(len(s[:left]), s[:left])
    # print(len(s[left:right]), s[left:right])
    # print(len(s[right:]), s[right:])
    if s[left:right][0] == '1' and s[left:right][-1] == '3':
        count_1 = 0
        while s[left:right][count_1] == '1':
            count_1 += 1
        count_2 = 1
        while s[left:right][-count_2] == '3':
            count_2 += 1
        count_2 -= 1
        print(min(count_1+left, count_2+len(s[right:])))
    elif s[left:right][0] == '3' and s[left:right][-1] == '3':
        count_3 = 1
        while s[:left][-count_3] == '3':
            count_3 += 1
        count_3 -= 1
        if count_3 % 2 == 1:
            print((count_3//2)+1+right-left)
        else:
            print((count_3//2)+len(s[right:]))
    elif s[left:right][0] == '1' and s[left:right][-1] == '1':
        count_1 = 0
        while s[right:][count_1] == '1':
            count_1 += 1
        if count_1 % 2 == 1:
            print((count_1//2)+1+left)
        else:
            print((count_1//2)+right-left)
    else:
        print(len(s[right:]))

q = int(input())
for k in range(q): 
    abc = list(map(int, input().split()))
    solve(abc[0]*'1'+abc[1]*'2'+abc[2]*'3')
    

"""
5
6 3 7
4 8 4
13 10 13
2 5 30
13 22 7

5
3 5 7
4 8 4
13 10 13
1000 1000 1000
13 22 7

"""
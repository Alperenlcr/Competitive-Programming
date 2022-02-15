pal = input()
lenn = len(pal)
odd = False
if lenn % 2 == 1:
    loop = int((lenn-1)/2)
    odd = True
else:
    loop = int(lenn/2)

count = 0
for i in range(loop):
    if pal[i] != pal[lenn-i-1]:
        count += 1
if odd and count == 0:
    print("25")
elif count == 1:
    print("2")
else:
    print("0")
# asdsda        asa     assa    asdggdsc
# palindrome olabilir   0
# palindrome a donusturulemeyebilir   0
# palindrome a donusturuleyebilir   2
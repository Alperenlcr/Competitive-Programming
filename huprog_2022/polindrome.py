
tc = int(input())
for i in range(tc):
    row = input().split() 
    n = int(row[0])
    k = int(row[1])
    N = int(n/k)
    string = input()
    result = 0
    strings = []
    if True or N % 2 == 0:
        for j in range(k):
            s = ""
            for m in range(N):
                s += string[m*k+j]
            strings.append(s)
        sekans = ""
        for s in strings:
            alp = [s.count("A"), s.count("B"), s.count("C"), s.count("D"), s.count("E"), s.count("F"), s.count("G")]
            sekans += chr(alp.index(max(alp))+ord("A"))
            result += N - max(alp)
        print(result)
    else:
        print(0)
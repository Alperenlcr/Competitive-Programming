def birle(satir, sutun, matrix,N,M):
    if satir != 0:
        for i in range(M):
            matrix[i][satir] = 1
    else:
        for i in range(N):
            matrix[sutun][i] = 1


string = input()
N,M,K = string.split()
N = int(N)
M = int(M)
K = int(K)
matrix = [[0 for i in range(M)] for j in range(N)]
matrix2 = [[0 for i in range(M)] for j in range(N)]
for i in range(K):
    string = input()
    x,y,tip = string.split()
    x = int(x)-1
    y = int(y)-1
    if tip == 'C':
        birle(x,0,matrix,N,M)
        birle(0,y,matrix2,N,M)
    else:
        birle(0,y,matrix,N,M)
        birle(x,0,matrix2,N,M)
satir=0
sutun=0
count = 0
sinir = N*M*2
M=M-1
N=N-1
while not(satir == N and sutun == M) and count<sinir:
    if count % 2 == 0:
        m = matrix
    else:
        m = matrix2
    saga_olan_uzaklik = M-sutun
    asagi_olan_uzaklik = N-satir
    if saga_olan_uzaklik >= asagi_olan_uzaklik and m[satir][sutun+1] == 0:
        sutun += 1
    elif asagi_olan_uzaklik >= saga_olan_uzaklik and m[satir+1][sutun] == 0:
        satir += 1
    elif m[satir][sutun+1] == 0:
        sutun += 1
    elif m[satir+1][sutun] == 0:
        satir += 1
    else:
        if count % 2 == 1:
            m = matrix
        else:
            m = matrix2
        if saga_olan_uzaklik >= asagi_olan_uzaklik and m[satir][sutun+1] == 0:
            sutun += 1
        elif asagi_olan_uzaklik >= saga_olan_uzaklik and m[satir+1][sutun] == 0:
            satir += 1
        else:
            count=sinir+1
    count += 1
if count<sinir:
    print(count)
else:
    print(-1)
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve(int t, vector<deque<int>> satir, deque<int> kutu, int matrix[302][302], int coordinates[9000][2], int N, int M)
{
    int ly,ky,ry,kx;
    unsigned int count, result = 0;
    bool var = true;
    int index = 0;
    kx = coordinates[t-1][0]+1;
    ky = coordinates[t-1][1]+1;
    // ly bulmak icin sola dogru ilerle 1 gorunce sutun sayisini esitle
    ly = ky-1;
    kutu.push_front(ky);
    satir.push_back(kutu);
    while (matrix[kx][ly] != 1)
    {
        kutu.push_front(ly);
        satir.push_back(kutu);
        ly --;
    }
    kutu.clear();
    for (auto k : satir)
    {
        // ry bulmak icin saga dogru ilerle 1 gorunce sutun sayisini esitle
        ry = ky+1;
        while (matrix[kx][ry] != 1)
        {
            k.push_front(ry);
            
            count = 0;
            for (int i = kx; i < N+1; i++)
            {
                var = true;
                for (auto sutun : k)
                {
                    if (matrix[i][sutun] == 1)
                    {
                        var = false;
                        break;
                    }
                }
                if (var)
                {
                    count ++;
                }
            }
            result += count;
            // *
            int temp = count;
            count = 0;
            for (int i = kx-1; i > 0; i--)
            {
                var = true;
                for (auto sutun : k)
                {
                    if (matrix[i][sutun] == 1)
                    {
                        var = false;
                        break;
                    }
                }
                if (var)
                {
                    count += temp;
                }
            }
            result += count;
            index ++;    
            ry ++;
        }
    }
    for (auto k : satir)
    {
        count = 0;
        for (int i = kx; i < N+1; i++)
        {
            var = true;
            for (auto sutun : k)
            {
                if (matrix[i][sutun] == 1)
                {
                    var = false;
                    break;
                }
            }
            if (var)
            {
                count ++;
            }
        }
        result += count;
        // *
        int temp = count;
        count = 0;
        for (int i = kx-1; i > 0; i--)
        {
            var = true;
            for (auto sutun : k)
            {
                if (matrix[i][sutun] == 1)
                {
                    var = false;
                    break;
                }
            }
            if (var)
            {
                count += temp;
            }
        }
        result += count;
        index ++;
    }
    cout << result << endl;
}

int main()
{
    int coordinates[9000][2], N, M;
    int matrix[302][302] = {0};
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int temp, tc, satir, sutun;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> temp;
            coordinates[temp-1][0] = i;
            coordinates[temp-1][1] = j;
        }
//  *****************************************************************
//          INIT        PADDIND
//  *****************************************************************
    tc = N*M;
    // int matrix[N+2][M+2] = {0};
    satir = 0;
    sutun = 0;
    for ( sutun = 0; sutun < M+2; sutun++)
        matrix[satir][sutun] = 1;
    satir = N+1;
    sutun = 0;
    for ( sutun = 0; sutun < M+2; sutun++)
        matrix[satir][sutun] = 1;
    satir = 0;
    sutun = 0;
    for ( satir = 0; satir < N+2; satir++)
        matrix[satir][sutun] = 1;
    satir = 0;
    sutun = M+1;
    for ( satir = 0; satir < N+2; satir++)
        matrix[satir][sutun] = 1;

//  *****************************************************************
//  *****************************************************************

    vector<deque<int>> satir2;
    deque<int> kutu;
    for (int t = 1; t <= tc; t++)
    {
        solve(t, satir2, kutu, matrix, coordinates, N , M);
        matrix[coordinates[t-1][0]+1][coordinates[t-1][1]+1] = 1;
        satir2.clear();
        kutu.clear();
    }

    return 0;
}
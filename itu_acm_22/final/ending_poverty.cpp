#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



int sayilarM[300][300];
int coordinates[9000][2];
int binaryM[300][300];
int tc, N, M;

void solve(int a, deque<int> d)
{

    for (auto x : d)
        cout << x << " ";
}

int** binary_create(int sayi)
{
    int temp[300][300] = {0};
    for (int i = sayi-1; i >= 0; i--)
    {
        if (coordinates[sayi-1][0] == coordinates[i][0])   // ayni satir
        {
            if (coordinates[i][1] < coordinates[sayi-1][1]) //sol
            {
                for (int j = 0; j <= coordinates[i][1]; j++)
                {
                    for (int k = 0; k < N; k++)
                    {
                        temp[k][j] = 1;
                    }
                }
            }
            else
            {
                for (int j = coordinates[i][1]; j < M; j++)
                {
                    for (int k = 0; k < N; k++)
                    {
                        temp[j][k] = 1;
                    }
                }
            }
        }
        else if (coordinates[sayi-1][1] == coordinates[i][1])   // ayni sutun
        {
            if (coordinates[i][0] < coordinates[sayi-1][0])
            {
                for (int j = 0; j <= coordinates[i][1]; j++)
                {
                    for (int k = 0; k < M; k++)
                    {
                        temp[j][k] = 1;
                    }
                }
            }
            else
            {
                for (int j = coordinates[i][1]; j < N; j++)
                {
                    for (int k = 0; k < M; k++)
                    {
                        temp[j][k] = 1;
                    }
                }
            }
        }
        else if (coordinates[sayi-1][0] < coordinates[i][0])   // alt
        {
            if (coordinates[sayi-1][1] > coordinates[i][1])   // sol
            {
                // coordinates[i][0] - N
                // 0 - coordinates[i][1]
                for (int j = coordinates[i][0]; j < N; j++)
                {
                    for (int k = 0; k <= coordinates[i][1]; k++)
                    {
                        temp[]
                    }
                }
            }
            else    //sag
            {

            }
        }
        else if (coordinates[sayi-1][0] > coordinates[i][0])   // ust
        {
            if (coordinates[sayi-1][1] > coordinates[i][1])   // sol
            {
                
            }
            else    //sag
            {

            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> sayilarM[i][j];
            coordinates[i*M + j][0] = i;
            coordinates[i*M + j][1] = j;
        }


    tc = N*M;
    for (int t = 1; t <= tc; t++)
    {
        binaryM = binary_create(t);
        solve(coordinates, binaryM);
    }

    return 0;
}
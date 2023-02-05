#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;


int solve(short int** binary_matrix, int** vents, int M, int N, int V)
{
    ll int** dp;
    int k,i,j,k2;
    dp = (ll int**) malloc(M*sizeof(ll int*));
    for ( i = 0; i < M; ++i)
        dp[i] = (ll int*) calloc(N, sizeof(ll int));
 // dp olusturma
    dp[0][0] = 1;
    j = 0;
    for ( i = 1; i < M; i++ )
    {
        if (binary_matrix[i][j] == 1)
        {
            dp[i][j] += dp[i-1][j];
            k = i*1000+j;
            k2=0;
            while (vents[k][k2] != 0)
            {
                dp[i][j] += dp[(int)(vents[k][k2]-1)/1000][(vents[k][k2]-1)%1000];
                k2 ++;
            }
        }
    }

    i = 0;
    for ( j = 1; j < N; j++ )
    {
        if (binary_matrix[i][j] == 1)
        {
            dp[i][j] += dp[i][j-1];
            k = i*1000+j;
            k2=0;
            while (vents[k][k2] != 0)
            {
                dp[i][j] += dp[(int)(vents[k][k2]-1)/1000][(vents[k][k2]-1)%1000];
                k2 ++;
            }
        }
    }

    for ( i = 1; i < M; i++)
    {
        for ( j = 1; j < N; j++)
        {
            if (binary_matrix[i][j] == 1)
            {
                dp[i][j] += dp[i-1][j] + dp[i][j-1];
                k = i*1000+j;
                k2=0;
                while (vents[k][k2] != 0)
                {
                    dp[i][j] += dp[(int)(vents[k][k2]-1)/1000][(vents[k][k2]-1)%1000];
                    k2 ++;
                }
            }
        }
    }


//    for ( i = 0; i < M; i++)
//    {
//        for ( j = 0; j < N; j++)
//        {
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }

    return dp[M-1][N-1] % MOD;
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

// take input
    int M, N, V, i, j, k;
    int t1, t2, t3, t4;
    cin >> M >> N >> V;

    short int** binary_matrix = new short int*[M];
    for ( i = 0; i < M; ++i)
        binary_matrix[i] = new short int[N];
    for ( i = 0; i < M; i++)
        for ( j = 0; j < N; j++)
            cin >> binary_matrix[i][j];

    int** vents = (int**) malloc(1000000*sizeof(int*));
    for ( i = 0; i < 10000000; i++)
        vents[i] = (int*) calloc(1000, sizeof(int));
    
    for ( i = 0; i < V; i++)
    {
        cin >> t1 >> t2 >> t3 >> t4;
        k = t3*1000+t4;
        j=0;
        while (vents[k][j] != 0)
            j ++;
        vents[k][j] = t1*1000+t2+1;
    }

// solve
    cout << solve(binary_matrix, vents, M, N, V);

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int solve(int n, int x, int y, int t)
{
    if (n == 1)
        return x;
    else if (n == 2)
        return y;
    else if ((n*1.0/t) > 1)
        return solve(n-1, x, y, t)%MOD + solve(n-2, x, y, t)%MOD + solve(n-t, x, y, t)%MOD;
    else
        return solve(n-1, x, y, t) + solve(n-2, x, y, t);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    deque<int> d;
    int t,x,y,n;
    cin >> t >> x >> y >> n;
    cout << solve(n, x, y, t);

    return 0;
}
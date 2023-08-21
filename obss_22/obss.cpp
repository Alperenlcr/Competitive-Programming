#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve(int a, deque<int> d)
{

    for (auto x : d)
        cout << x << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    deque<int> d;
    int tc, a;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        cin >> a;
        solve(a, d);
    }

    return 0;
}
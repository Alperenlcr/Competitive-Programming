#include <bits/stdc++.h>

using namespace std;

void solve(int a, deque<int> d)
{

    for (auto x : d)
        cout << x << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    int tc, a;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        cin >> a;
        solve(a, d);
    }

    return 0;
}
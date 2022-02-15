#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int gcd_recursive(int a, int b)
{
    if (b)
        return gcd_recursive(b, a % b);
    else
        return a;
}
void solve(int a) {
    int gcd = gcd_recursive(a, 100-a);
    cout << (100/gcd) << endl;
    //cout << a << " - " << 100-a << " - " << gcd << " - " << (float)(100.0/(float)gcd) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc = 100, a;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        cin >> a;
        // cout << "Case #" << t << ": ";
        solve(a);
    }
    return 0;
}
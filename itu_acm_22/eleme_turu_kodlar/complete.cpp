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
void solve(vector<int> v, int max)
{
    for (int i = 1; i <= max; i++)
    {
        if (v[i-1] != i)    // bu eklenecek
        {
            // elimizdekiler ile oluyor mu
            v.insert(v.begin() + 2, { 30, 40, 50, 60 });
        }
    }
    
    //cout << a << " - " << 100-a << " - " << gcd << " - " << (float)(100.0/(float)gcd) << endl;

}

/*
olmayan en kucuk elemani bul
bunu kendisinden kucuk sayilar ile toplayarak elde edebilir muyuz diye bak
eger elde edemiyorsak cost bir arttir ve diziye ekle devam et
*/

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> v;
    int tc, max, temp;
    cin >> tc >> max;
    for (int t = 1; t <= tc; t++)
    {
        cin >> temp;
        v.push_back(temp);
        // cout << "Case #" << t << ": ";
    }

    if (!is_sorted(v.begin(), v.end()))
        sort(v.begin(), v.end());
    
    solve(v, max);
    return 0;
}
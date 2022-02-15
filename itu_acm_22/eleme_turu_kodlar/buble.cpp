#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long int
const ll MOD = 1e9 + 7;

// ll cost_bul(vector<int> arr, int x)
// {
//     ll cost = 0;
//     for (int i = 0; i < arr.size(); i++)
//         cost += arr[i]-x;
//     return cost; 
// }

void solve(vector<int> d, int n)
{
    int i = 1, sayi;
    ll cost=0;
    while (i <= n)
    {
        sayi = d[i];
        if (sayi < i)
        {
            // cost += cost_bul(vector <int> (d.begin()+sayi, d.begin()+i), sayi);     // ilki dahil ikincisi degil
            cost += accumulate(d.begin()+sayi, d.begin()+i, 0) - (i-sayi)*sayi;
            d.insert(d.begin()+sayi, sayi);
            d.erase(d.begin()+i+1);
            i = sayi+1;
        }
        else
            i ++;
    }
    cout << cost%MOD;
}

// if (sayi > i)
// {
//     cost += cost_bul(vector <int> (d.begin()+i+1, d.begin()+sayi+1), sayi);
//     d.erase(d.begin()+i);
//     d.insert(d.begin()+sayi, sayi);
// }
// else
    // i --;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> dizi;
    dizi.push_back(0);
    int n, a;

    n=10000;
    for (int i = 0; i < n; i++)
    {
        dizi.push_back(n-i);
    }
    

    // cin >> n;
    // for (int t = 1; t <= n; t++)
    // {
    //     cin >> a;
    //     dizi.push_back(a);
    // }
    solve(dizi, n);
    return 0;
}

// dizinin ilk elemanina 0 koy
// index = 1
// while index <= n:
// 	dizi[index] < index ise:
// 		sayi = dizi[index]
// 		cost += cost_bul(dizi[sayi : index], sayi) 	// ilki dahil ikincisi degil
// 		dizi.insert(dizi.begin()+sayi, sayi)
// 		dizi.delete(dizi.begin()+index+1)
// 		index = sayi+1
// 	else:
// 		index ++
	
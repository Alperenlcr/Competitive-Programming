#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long int
const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // vector<unsigned int> dizi;
    int* dizi;
    unsigned int n, a, i, t1, t2;
    unsigned int cost = 0;
    // n=100000;
    // for (unsigned int i = 0; i < n; i++)
    // {
    //     dizi[i] = n-i;
    //     // dizi.push_back(n-i);
    // }

    cin >> n;
    dizi = (int*) malloc(n*sizeof(int));
    for (unsigned int t = 0; t < n; t++)
    {
        cin >> dizi[t];
        // cin >> a;
        // dizi.push_back(a);
    }

    i = n;
    while (i != 1)
    {
        unsigned int k = 0;
        for (; k<i; k++)
        {
            if (dizi[k] == i)
            {
                copy(dizi + k+1, // copy everything starting here
                dizi + i, // and ending here, not including it,
                dizi + k);
                // dizi.erase(dizi.begin()+k);
                // for (int z = 0; z < i; z++)
                // {
                //     cout << dizi[z] << " ";
                // }
                // cout << endl;
                
                break;
            }
        }
        t1 = k;
        t2 = i-1;
        if ( t1 != t2 )
        {
            unsigned int sum = 0;
            for (unsigned int j = t1; j < t2; j++)
                sum += dizi[j];
            cost += ((t2-t1)*i - sum) % MOD;
        }
        i -= 1;
    }
    cout << cost;
    return 0;
}

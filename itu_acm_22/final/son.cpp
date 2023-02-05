#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MODULE 998244353

ll cost(int N,int x,int y,vector<int> array)
{
    ll total_cost = 0;
    sort(array.begin(), array.end());
    for (int i = 1; i < N+1; i++)
        total_cost += ((long long)((long long)array[i-1]*(long long)pow(i,x))/y) % MODULE;
        total_cost %= MODULE;
    return total_cost;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> dizi;
    int N,x,y,Q,pos,val,temp;
    ll total_cost;

    cin >> N >> x >> y;
    for (int t = 0; t < N; t++)
    {
        cin >> temp;
        dizi.push_back(temp);
    }
    cin >> Q;
    for (int k = 0; k < Q; k++)
    {
        cin >> pos >> val;
        dizi[pos-1] = val;
        cout << cost(N,x,y,dizi) << endl;
    }

    return 0;
}
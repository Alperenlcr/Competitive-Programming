#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e9;


pair<int, int> hedef, baslangic;
int prime;
int stop;

pair<int, int> f_op(pair<int, int> input, int p)
{
    pair<int, int> pa;
    int a = input.first;
    int b = input.second;
    pa.first = (a-b+p) % p ;
    pa.second = (2*b) % p ;

    return pa;
}

pair<int, int> s_op(pair<int, int> input, int p)
{
    pair<int, int> pa;
    int a = input.first;
    int b = input.second;
    pa.first = (2*a) % p ;
    pa.second = (b-a+p) % p ;

    return pa;
}

bool is_exits(vector<pair<int, int>> ikililer)
{
    int a, b;
    a = ikililer.back().first;
    b = ikililer.back().second;
    for(auto it = ikililer.begin(); it!=ikililer.end()-1; it++ )
        if(it->first == a && it->second == b)
            return true;
    return false;
}


int solve(vector<pair<int, int>> ikililer, int count)
{
    // ikililer.begin(), ikililer.end()-1   icinde ikililer.end() varsa return MAX
    if (count == stop || is_exits(ikililer))
        return MAX;
    if (ikililer.back() == hedef)
    {
        stop = count;
        return count;
    }

    ikililer.push_back(f_op(ikililer.back(), prime));
    int a = solve(ikililer, count+1);
    ikililer.pop_back();
    ikililer.push_back(s_op(ikililer.back(), prime));
    int b = solve(ikililer, count+1);
    ikililer.pop_back();
    
    return min(a, b);

}


int main()
{
    int a,b,c,d;
    int q;
    cin >> prime >> q;
    // vector<int> sil;
    for (int i = 0; i < q; i++)
    {
        stop = MAX;
        vector<pair<int, int>> ikililer;
        cin >> a >> b >> c >> d;
        baslangic = make_pair(a, b);
        hedef = make_pair(c, d);
        ikililer.push_back(baslangic);
        
        a = solve(ikililer, 0);
        if ( a == MAX )
            cout << -1 << endl;
        else
            cout << a << endl;
        // sil.push_back(a);
    }
    // cout << endl;
    // for (int i = 0; i < sil.size(); i++)
    //     cout << sil[i] << endl;

	return 0;
}

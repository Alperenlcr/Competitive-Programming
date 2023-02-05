#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define txt_num 0
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

//  ************************************************
    // read
    char files[6][100] = {"00-example.txt", "01-the-cloud-abyss.txt", "02-iot-island-of-terror.txt", "03-etheryum.txt", "04-the-desert-of-autonomous-machines.txt", "05-androids-armageddon.txt"};
    char file[100];
    strcpy(file, files[txt_num]);
    ifstream fr;
    fr.open(file);

    vector <queue <int>> Na;
    vector <int> Sc, Tr, Sr, N;
    ll Si, Smax, T, D, temp1, temp2, temp3, temp4;
    fr >> Si >> Smax >> T >> D;
    for (ll i = 0; i < D; i++)
    {
        fr >> temp1 >> temp2 >> temp3 >> temp4;
        Sc.push_back(temp1);
        Tr.push_back(temp2);
        Sr.push_back(temp3);
        N.push_back(temp4);
    }
    
//  ************************************************


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
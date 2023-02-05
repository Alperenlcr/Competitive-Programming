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


int numberOfPaths(int m, int n)
{
	// We have to calculate m+n-2 C n-1 here
	// which will be (m+n-2)! / (n-1)! (m-1)!
	int path = 1;
	for (int i = n; i < (m + n - 1); i++) {
		path *= i;
		path /= (i - n + 1);
	}
	return path;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector <pair<int, int>> walls;
    vector <pair< pair<int, int>, pair<int, int> >> wents;
    deque<int> d;
    int M, N, V, i, j, temp;
    int t1, t2, t3, t4;
    cin >> M >> N >> V;

    for ( i = 1; i <= M; i++)
    {
        for ( j = 1; j <= N; j++)
        {
            cin >> temp;
            if (temp == 0)
                walls.push_back(make_pair(i, j));
        }
    }
    for ( i = 0; i < V; i++)
    {
        cin >> t1 >> t2 >> t3 >> t4;
        wents.push_back(make_pair(make_pair(t1, t2), make_pair(t3, t4)));
    }

    
    cout << numberOfPaths(3, 3);
    return 0;
}

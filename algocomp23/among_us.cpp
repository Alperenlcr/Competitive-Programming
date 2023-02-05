#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
vector<int> v[1000000];

void add_edge(int a, int b, int fre[])
{
    // there is path from a to b.
    v[a].push_back(b);
    fre[b]++;
}

vector<int> topological_sorting(int fre[], int n)
{
    queue<int> q;
 
    // insert all vertices which
    // don't have any parent.
    for (int i = 0; i < n; i++)
        if (!fre[i])
            q.push(i);
 
    vector<int> l;
 
    // using kahn's algorithm
    // for topological sorting
    while (!q.empty()) {
        int u = q.front();
        q.pop();
 
        // insert front element of queue to vector
        l.push_back(u);
 
        // go through all it's childs
        for (int i = 0; i < v[u].size(); i++) {
            fre[v[u][i]]--;
 
            // whenever the frequency is zero then add
            // this vertex to queue.
            if (!fre[v[u][i]])
                q.push(v[u][i]);
        }
    }
    return l;
}

int numberofPaths(int source, int destination, int n, int fre[])
{
 
// make topological sorting
    vector<int> s = topological_sorting(fre, n);
 
    // to store required answer.
    int dp[n] = { 0 };
 
    // answer from destination
    // to destination is 1.
    dp[destination] = 1;
 
    // traverse in reverse order
    for (int i = s.size() - 1; i >= 0; i--) {
        for (int j = 0; j < v[s[i]].size(); j++) {
            dp[s[i]] += dp[v[s[i]][j]];
        }
    }
 
    return dp;
}

void solve(int a, deque<int> d)
{

    for (auto x : d)
        cout << x << " ";
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

    // for ( i = 1; i <= M; i++)
    // {
    //     for ( j = 1; j <= N; j++)
    //     {
    //         cin >> temp;
    //         if (temp == 0)
    //             walls.push_back(make_pair(i, j));
    //     }
    // }
    short int** matrix = new short int*[M];
    for (int i = 0; i < M; ++i)
        matrix[i] = new short int[N];
    for ( i = 0; i < M; i++)
    {
        for ( j = 0; j < N; j++)
        {
            cin >> matrix[i][j];
        }
    }
    


    // here vertices are numbered from 0 to n-1.
    int source = 0, destination = M*N-1;
 
    // to count number of vertex which don't
    // have any parents.
    int fre[M*N] = { 0 };
 
    // to add all edges of graph
    add_edge(0, 1, fre);
    add_edge(0, 2, fre);
    add_edge(0, 3, fre);
    add_edge(0, 4, fre);
    add_edge(2, 3, fre);
    add_edge(3, 4, fre);
 
    for ( i = 0; i < V; i++)
    {
        cin >> t1 >> t2 >> t3 >> t4;
        //wents.push_back(make_pair(make_pair(t1, t2), make_pair(t3, t4)));
        add_edge(t1*M+t2, t3*M+t4, fre);
    }
    for ( i = 0; i < M; i++)
    {
        for ( j = 0; j < N; j++)
        {
            if (matrix[i][j] == 1)
            {
                if (i+1<M && matrix[i+1][j] == 1)
                {
                    add_edge(i*M+j, (i+1)*M+j, fre);
                }
                if (j+1<N && matrix[i][j+1] == 1)
                {
                    add_edge(i*M+j, i*M+j+1, fre);
                }
            }
        }
    }
    // Function that returns the number of paths
    cout << numberofPaths(source, destination, M*N, fre);
    
    return 0;
}

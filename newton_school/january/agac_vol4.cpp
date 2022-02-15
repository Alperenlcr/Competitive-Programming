#include <bits/stdc++.h>
using namespace std;

// Returns factorial of n
int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

// function to determine level of each node starting
// from x using BFS
void countLevels(vector<int> graph[], int V, int x, int* level)
{
	// array to store level of each node
	bool marked[V] = {false};

	// create a queue
	queue<int> que;

	// enqueue element x
	que.push(x);

	// initialize level of source node to 0
	level[x] = 0;

	// marked it as visited
	marked[x] = true;

	// do until queue is empty
	while (!que.empty()) {

		// get the first element of queue
		x = que.front();

		// dequeue element
		que.pop();

		// traverse neighbors of node x
		for (int i = 0; i < graph[x].size(); i++) {
			// b is neighbor of node x
			int b = graph[x][i];

			// if b is not marked already
			if (!marked[b]) {

				// enqueue b in queue
				que.push(b);

				// level of b is level of x + 1
				level[b] = level[x] + 1;

				// mark b
				marked[b] = true;
			}
		}
	}

	// display all nodes and their levels
    // cout << "Nodes" << " " << "Level" << endl;
	// for (int i = 0; i < V; i++)
    //     cout << " " << i << " --> " << level[i] << endl;
}

// function for finding minimum no. of edge
// using BFS
int minEdgeBFS(vector <int> edges[], int u, int v, int n)
{
    // visited[n] for keeping track of visited
    // node in BFS
    vector<bool> visited(n, 0);
 
    // Initialize distances as 0
    vector<int> distance(n, 0);
 
    // queue to do BFS.
    queue <int> Q;
    distance[u] = 0;
 
    Q.push(u);
    visited[u] = true;
    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();
 
        for (int i=0; i<edges[x].size(); i++)
        {
            if (visited[edges[x][i]])
                continue;
 
            // update distance for i
            distance[edges[x][i]] = distance[x] + 1;
            Q.push(edges[x][i]);
            visited[edges[x][i]] = 1;
        }
    }
    return distance[v];
}

unsigned long long solution(vector<int> matrix_satiri, unsigned int N, unsigned int K, vector<int> graph[])
{
/*
vector<vector<int>> mv daha acalim
her satir icin bastan dolduracaz
matrixin satirindaki dizide bulunan degerler(0 haric) ile mv nin satirina erisip matrixin sutun degerini pushla
mv olustuktan sonra satir satir donup sonuc u arttiricaz
    mv nin satiri icin
        once eleman sayisi K dan buyuk mu diye kontrol
        buyukse devam
        elemanlardan olabilecek butun K elemanli farkli alt diziler(unordered) icin degerlendirecez
        alt dizinin ikililerinin birbirleri ile uzakliklarina matrixten bakicaz eger mv nin satir indexinin iki katina esit ise hepsi, sonucu bir artiricaz
matrixteki her satir icin yapicaz
*/
    unsigned long long sonuc = 0;
    int i, j, k, l, m, n, x;
// vector<vector<int>> mv daha acalim
    vector<vector<int>> mv;

/*
i --> matrix satir sayaci
j --> matrix sutun sayaci
k --> mv satir sayaci
l --> mv sutun sayaci
*/
// her satir icin mv yi bastan dolduracaz

    for ( k = 0; k < N; k++)
        mv.push_back(vector<int> ());

    for ( j = 0; j < N; j++)
// matrixin satirindaki dizide bulunan degerler(0 haric) ile mv nin satirina erisip matrixin sutun degerini pushla
        if (matrix_satiri[j] != 0)
            mv[matrix_satiri[j]].push_back(j);
    for ( k = 0; k < N; k++)
        mv[k].push_back(-1);

//  **********  mv yazdirma ************
//    for ( k = 0; k < N; k++)
//    {
//        if (mv[k].size() < K)
//            continue; 
//        for ( l = 0; l < mv[k].size(); l++)
//        {
//            cout << mv[k][l];
//            cout << " ";
//        }
//        cout << "  ---  ";
//    }
//  ****************************************
// mv olustuktan sonra satir satir donup sonuc u arttiricaz
    for ( k = 0; k < N; k++)
    {
// mv nin satiri icin
// once eleman sayisi K dan buyuk mu diye kontrol
// buyukse devam
        if (mv[k].size()-1 < K)
            continue;   
// elemanlardan olabilecek butun K elemanli farkli alt diziler(unordered) icin degerlendirecez

    // alt dizinin ikililerinin birbirleri ile uzakliklarina matrixten bakicaz eger mv nin satir indexinin iki katina esit ise hepsi, *sonucu bir artiricaz
        // ikili bakacagiz
        m = 0;
        x = 0;
        while (mv[k][m] != -1)
        {
            n = m+1;
            while (mv[k][n] != -1)
            {
                if (minEdgeBFS(graph, mv[k][m], mv[k][n], N) != 2*k)
                    mv[k].erase(mv[k].begin()+n);
                //else
                    //x ++;
                n ++;
            }
            m++ ;
        }
        x += mv[k].size()-1;
        if (x >= K)
            sonuc += nCr(x, K);
    }
    mv.clear();
// matrixteki her satir icin yapicaz
    

//  **********  matrix yazdirma ************
    // for ( i = 0; i < N; i++)
    // {
    //     for ( j = 0; j < N; j++)
    //     {
    //         cout << matrix[i][j];
    //         cout << " ";
    //     }
    //     cout << endl;
    // }
//  ****************************************
    return sonuc%998244353;
}

/*
her node un baska node lar ile olan level uzakligini bul matrix e dok
matrix i solutiona gonder ve cevabı bul
*/

// Driver Code
int main()
{
	// adjacency graph for tree
    unsigned long long sonuc = 0;
    unsigned int N, K, a, b, i, j;
    cin >> N >> K;
	vector<int> graph[N];
    vector<int> matrix_satiri;
    for ( i = 0; i < N-1; i++)
    {
        cin >> a >> b;
        // a---b yi agaca ekle
	    graph[a-1].push_back(b-1);
	    graph[b-1].push_back(a-1);
    }
    // agac hazir 

    for ( i = 0; i < N; i++)
    {
        int level_count[N] = {-1};
    	countLevels(graph, N, i, level_count);
        vector<int> v(level_count, level_count + N);
        sonuc += solution(v, N, K, graph);
    }
    // matrix hazir

    cout << sonuc;
   // cout << sonuc;
	return 0;
}


/*

7 2
1 2
1 3
2 4
2 5
3 6
3 7

*/
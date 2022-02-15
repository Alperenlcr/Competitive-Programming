// C++ program to print all paths
// from a source to destination.
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> different_paths;
vector<vector<int>> result_paths;

// A directed graph using
// adjacency list representation
class Graph {
	int V; // No. of vertices in graph
	list<int>* adj; // Pointer to an array containing adjacency lists

	// A recursive function used by printAllPaths()
	void printAllPathsUtil(int, int, bool[], int[], int&);

public:
	Graph(int V); // Constructor
	void addEdge(int u, int v);
	void printAllPaths(int s, int d);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v); // Add v to u’s list.
}

// Prints all paths from 's' to 'd'
void Graph::printAllPaths(int s, int d)
{
	// Mark all the vertices as not visited
	bool* visited = new bool[V];

	// Create an array to store paths
	int* path = new int[V];
	int path_index = 0; // Initialize path[] as empty

	// Initialize all vertices as not visited
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper function to print all paths
	printAllPathsUtil(s, d, visited, path, path_index);
}

// A recursive function to print all paths from 'u' to 'd'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and path_index is current
// index in path[]
void Graph::printAllPathsUtil(int u, int d, bool visited[],
							int path[], int& path_index)
{
	// Mark the current node and store it in path[]
	visited[u] = true;
	path[path_index] = u;
	path_index++;

	// If current vertex is same as destination, then print
	// current path[]
    if (u == d) {
        for (int i = 0; i < path_index; i++)
            cout << path[i] << " ";
        cout << endl;
    }
	// if (u == d) {
    //     vector<int> path_v;
    //     int size = sizeof(path) / sizeof(path[0]);
    //     for (int j = 0; j < size; j++)
    //     {
    //         cout << path[j] << " ";
    //     }
    //     cout << endl;
	// 	for (int i = 0; i < path_index; i++)
    //     {
    //         path_v.push_back(path[i]);
    //     }
    //     different_paths.push_back(path_v);
	// }
	else // If current vertex is not destination
	{
		// Recur for all the vertices adjacent to current vertex
		list<int>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
			if (!visited[*i])
				printAllPathsUtil(*i, d, visited, path, path_index);
	}

	// Remove current vertex from path[] and mark it as unvisited
	path_index--;
	visited[u] = false;
}

void solution(vector<int> dizi)
{
    sort(dizi.begin(), dizi.end());
    // eger ki resultta ayni dizi farkli sirayla yok ise resulta ekle
    if (result_paths.size() == 0)       // ilk ekleme
    {
        result_paths.push_back(dizi);
        return;
    }

    bool eklenecek = true;
    // aynisi farkli sirada var mi diye bak yoksa ekle
    int i=0;
    while (i < result_paths.size() && eklenecek)
        (result_paths[i] == dizi)?  eklenecek = false : i ++;       // result_paths in i. dizisi ile dizi ayni mi
    
    if (eklenecek)
        result_paths.push_back(dizi);
}

// Driver program
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	// Create a graph given in the above diagram
    int N, t, a, b;
    cin >> N >> t;
	Graph g(N);
    vector<vector<int>> komsuluk;
    for (int i = 0; i < t; i++)
        komsuluk.push_back(vector<int> ());
    
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;
        komsuluk[a-1].push_back(b-1);
        g.addEdge(a-1, b-1);
        //g.addEdge(b-1, a-1);
    }
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < komsuluk[i].size(); j++)
        {
            // i komsuluk[i][j]
            // bir node dan baslayip kendine geri donen farkli yollari bulmamiz lazim
            g.printAllPaths(i, komsuluk[i][j]);

            for (int j = 0; j < different_paths.size(); j++)
            {
                // eger ki resultta ayni dizi farkli sirayla yok ise resulta ekle
                solution(different_paths[j]);
            }
            
            // buldugumuz yollardan cevap olacak olanlara eklememiz lazim
            different_paths.clear();
        }   
    }
    for (int i = 0; i < N; i++)
    {

    }

    cout << result_paths.size();
	return 0;
}
/*    

4 5
1 2
1 3
1 4
2 3
2 4



4 6
1 2
1 3
1 4
2 4
2 3
3 4

*/
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

void solution2(unsigned long long *sonuc, int subset[], int K, int uzaklik, vector<vector<int>> matrix)
{
    int l, i, j;
    bool arttir = true;
// alt dizinin ikililerinin birbirleri ile uzakliklarina matrixten bakicaz eger mv nin satir indexinin iki katina esit ise hepsi, *sonucu bir artiricaz

    // ikili bakacagiz
    for ( i = 0; i < K; i++)
        for ( j = i+1; j < K; j++)
        {
            if (matrix[subset[i]][subset[j]] != 2*uzaklik)
                arttir = false;
        }
    if (arttir)
        (*sonuc) ++;
    
// ************ comb ile gelen subset **********
    // for ( l = 0; l < K; l++)
    // {
    //     cout << subset[l]+1;
    //     cout << " ";
    // }
    // cout << "  ---  ";
    // cout << endl;
// *******************************************
}

/* arr[]  ---> Input Array
   n      ---> Size of input array
   r      ---> Size of a combination to be printed
   index  ---> Current index in data[]
   data[] ---> Temporary array to store current combination
   i      ---> index of current element in arr[]     */
void combinationUtil(vector<int> arr, int n, int r, int index,
                     int data[], int i, unsigned long long *sonuc, int uzaklik, vector<vector<int>> matrix)
{
    // Current combination is ready, print it
    // if (index == r) {
    //     for (int j = 0; j < r; j++)
    //         cout <<" "<< data[j];
    //     cout <<"\n";
    //     return;
    // }
    if (index == r)
    {
        solution2(sonuc, data, r, uzaklik, matrix);
        return;
    }

    // When no more elements are there to put in data[]
    if (i >= n)
        return;
  
    // current is included, put next at next location
    data[index] = arr[i];
    combinationUtil(arr, n, r, index + 1, data, i + 1, sonuc, uzaklik, matrix);
  
    // current is excluded, replace it with next
    // (Note that i+1 is passed, but index is not
    // changed)
    combinationUtil(arr, n, r, index, data, i + 1, sonuc, uzaklik, matrix);
}

// The main function that prints all combinations of
// size r in arr[] of size n. This function mainly
// uses combinationUtil()
void findCombination(vector<int> arr, int n, int r, unsigned long long *sonuc, int uzaklik, vector<vector<int>> matrix)
{
//!    stack<vector<int>> subsets;

    // A temporary array to store all combination
    // one by one
    int data[r];
  
    // Print all combination using temporary array 'data[]'
    combinationUtil(arr, n, r, 0, data, 0, sonuc, uzaklik, matrix);
}

unsigned long long solution(vector<vector<int>> matrix, unsigned int N, unsigned int K)
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
    int i, j, k, l;
// vector<vector<int>> mv daha acalim
    vector<vector<int>> mv;

/*
i --> matrix satir sayaci
j --> matrix sutun sayaci
k --> mv satir sayaci
l --> mv sutun sayaci
*/
// her satir icin mv yi bastan dolduracaz
    for ( i = 0; i < N; i++)
    {
        for ( k = 0; k < N; k++)
            mv.push_back(vector<int> ());

        for ( j = 0; j < N; j++)
// matrixin satirindaki dizide bulunan degerler(0 haric) ile mv nin satirina erisip matrixin sutun degerini pushla
            if (matrix[i][j] != 0)
                mv[matrix[i][j]].push_back(j);

//  **********  mv yazdirma ************
    // for ( k = 0; k < N; k++)
    // {
    //     for ( l = 0; l < mv[k].size(); l++)
    //     {
    //         cout << mv[k][l];
    //         cout << " ";
    //     }
    //     cout << "  ---  ";
    // }
//  ****************************************
// mv olustuktan sonra satir satir donup sonuc u arttiricaz
        for ( k = 0; k < N; k++)
        {
// mv nin satiri icin
    // once eleman sayisi K dan buyuk mu diye kontrol
    // buyukse devam
            if (mv[k].size() < K)
                continue;   
    // elemanlardan olabilecek butun K elemanli farkli alt diziler(unordered) icin degerlendirecez
            findCombination(mv[k], mv[k].size(), K, &sonuc, k, matrix);   // kendi icinde solution2 ye gonderiyor subsets i
        }
        mv.clear();
    // matrixteki her satir icin yapicaz
    }

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
    unsigned int N, K, a, b, i, j;
    cin >> N >> K;
	vector<int> graph[N];
    vector<vector<int>> matrix;
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
        matrix.push_back(v);
    }
    // matrix hazir

    cout << solution(matrix, N, K);
   // cout << sonuc;
	return 0;
}

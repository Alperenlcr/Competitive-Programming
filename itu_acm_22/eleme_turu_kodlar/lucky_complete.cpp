// Returns true if there exists a subset
// with given sum in arr[]
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isSubsetSum(vector<int> arr, int n, int sum)
{

	// The value of subset[i%2][j] will be true
	// if there exists a subset of sum j in
	// arr[0, 1, ...., i-1]
	bool subset[2][sum + 1];

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {

			// A subset with sum 0 is always possible
			if (j == 0)
				subset[i % 2][j] = true;

			// If there exists no element no sum
			// is possible
			else if (i == 0)
				subset[i % 2][j] = false;
			else if (arr[i - 1] <= j)
				subset[i % 2][j] = subset[(i + 1) % 2]
			[j - arr[i - 1]] || subset[(i + 1) % 2][j];
			else
				subset[i % 2][j] = subset[(i + 1) % 2][j];
		}
	}

	return subset[n % 2][sum];
}

// Driver code
int main()
{
    int cost = 0;
    int n, max, temp;
    cin >> n >> max;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    arr.push_back(123456);
    if (!is_sorted(arr.begin(), arr.end()))
        sort(arr.begin(), arr.end());
    sort(arr.begin(), arr.end());
    int j = 0;
    if (arr[0] != 1)
    {
        arr.insert(arr.begin(), 1);
        cost ++;
        n ++;
    }
    
    for (int i = 1; i <= max; i++)
    {
        if (arr[j] == i)
        {
            if (arr[j+1] != 123456)
                j ++;
        }
        else if ((arr[j]*(arr[j]+1))/2 < i)
        {
            cost ++;
            arr.insert(arr.begin()+j, i);
            n ++;
            j ++;
        }
        else if (isSubsetSum(vector <int> (arr.begin(), arr.begin()+j), n, i) == false)
        {
            cost ++;
            arr.insert(arr.begin()+j, i);
            n ++;
            j ++;
        }
    }
    cout << cost;
	return 0;
}


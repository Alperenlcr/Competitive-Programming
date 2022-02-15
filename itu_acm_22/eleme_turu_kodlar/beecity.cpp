// C++ program of the above approach

#include <bits/stdc++.h>
using namespace std;

// Dp array to memoized
// the value recursive call
int dp[1000][1000];

// Function to find the minimum increment
// or decrement needed to make the array
// sorted
int minimumIncDec(int arr[], int N,
				int maxE, int minE)
{
	// If only one element is present,
	// then arr[] is sorted
	if (N == 0) {
		return 0;
	}

	// If dp[N][maxE] is precalculated,
	// then return the result
	if (dp[N][maxE])
		return dp[N][maxE];

	int ans = INT_MAX;

	// Iterate from minE to maxE which
	// placed at previous index
	for (int k = minE; k <= maxE; k++) {

		// Update the answer according to
		// recurrence relation
		int x = minimumIncDec(arr, N - 1, k, minE);
		ans = min(ans, x + abs(arr[N - 1] - k));
	}

	// Memoized the value
	// for dp[N][maxE]
	dp[N][maxE] = ans;

	// Return the final result

	return dp[N][maxE];
}

// Driver Code
int main()
{
	int arr[] = { 3,1,4,2};
	int N = sizeof(arr) / sizeof(arr[0]);

	// Find the minimum and maximum
	// element from the arr[]
	int minE = *min_element(arr, arr + N);
	int maxE = *max_element(arr, arr + N);

	// Function Call
	cout << minimumIncDec(
		arr, N, maxE, minE);

	//return dp[N][maxE] + ekstra(arr);
    
	return 0;
}

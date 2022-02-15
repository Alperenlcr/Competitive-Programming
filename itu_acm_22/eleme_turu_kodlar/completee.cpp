// CPP program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Returns true if there is a subset
// of set[] with sum equal to given sum
bool isSubsetSum(vector<int> set, int n, int sum)
{
   
    // Base Cases
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
 
    // If last element is greater than sum,
    // then ignore it
    if (set[n - 1] > sum)
        return isSubsetSum(set, n - 1, sum);
 
    /* else, check if sum can be obtained by any
of the following:
      (a) including the last element
      (b) excluding the last element   */
    return isSubsetSum(set, n - 1, sum)
           || isSubsetSum(set, n - 1, sum - set[n - 1]);
}
 
// Driver Code
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
    if (!is_sorted(arr.begin(), arr.end()))
        sort(arr.begin(), arr.end());

    arr.push_back(123456);
    
    
    if (arr[0] != 1)
    {
        arr.insert(arr.begin(), 1);
        cost ++;
        n ++;
    }
    if (arr[1] != 2)
    {
        arr.insert(arr.begin()+1, 2);
        cost ++;
        n ++;
    }
    int j=2;
    if (arr.size() == 3)
        j = 1;
    // arr da 1 ve 2 kesin var ve son eleman 123456
    // j de arr daki 2 den buyuk olan ama 123456 olmayan degeri gosteriyor
    for (int i = 3; i <= max; i++)
    {
        if (arr[j] == i)        // zaten varsa j yi arttir
        {
            if (arr[j+1] != 123456)
                j ++;
        }
        else if ((arr[j]*(arr[j]+1))/2 < i)     // dizide olan i den kucuk en buyuk deger yeterli degilse
        {
            cost ++;
            arr.insert(arr.begin()+j+1, i);
            n ++;
            j ++;
            // cout << i << " yi koydun\n";
        }
        else if (isSubsetSum(vector <int> (arr.begin(), arr.begin()+j+1), n, i) == 0)     // dizide olan i den kucuk degerler ile i yi elde etmeye calis
        {
            cost ++;
            arr.insert(arr.begin()+j, i);
            n ++;
            j ++;
            // cout << i << " yi koydun\n";
        }
    }
    cout << cost;
	return 0;
}

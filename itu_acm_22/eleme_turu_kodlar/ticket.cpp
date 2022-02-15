// C++ program to demonstrate sorting in
// vector of pair according to 1st element
// of pair
#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector< pair <string, string> > vect, int l, int r, string x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
  
        // If the element is present at the middle
        // itself
        if (vect[mid].first == x)
            return mid;
  
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (vect[mid].first > x)
            return binarySearch(vect, l, mid - 1, x);
  
        // Else the element can only be present
        // in right subarray
        return binarySearch(vect, mid + 1, r, x);
    }
  
    // We reach here when element is not
    // present in array
    return -1;
}

int main()
{
	// Declaring vector of pairs
	vector< pair <string, string> > vect;

	// Initializing 1st and 2nd element of
	// pairs with array values

	int n;
    string a,b;
    cin >> n;
	// Entering values in vector of pairs
	for (int i=0; i<n; i++)
    {
        cin >> a >> b;
		vect.push_back( make_pair(a, b) );
    }

	// Using simple sort() function to sort
	sort(vect.begin(), vect.end());

    // vector<string> seconds;
    // for (int i=0; i<n; i++)
    //     seconds.push_back(vect[i].second);
	
	// sort(seconds.begin(), seconds.end());

    bool cik = true;
    // int i = 0;
    string baslangic;
    // while (cik)
    // {
    //     if ( !binary_search(seconds.begin(), seconds.end(), vect[i].first) )
    //     {
    //         cik = false;
    //         baslangic = vect[i].first;
    //     }
    //     i ++;
    // }
    int f=0, s=0;
    while (cik)
    {
        s = 0;
        while (vect[f].first != vect[s].second && s != n)
            s ++;
        
        if (s == n)
        {
            baslangic = vect[f].first;
            cik = false;
        }
        f ++;
    }
    
    int index;
    while ( true )
    {
        cout << baslangic << " ";
        index = binarySearch(vect, 0, n-1, baslangic);
        if (index == -1)
            break;
        baslangic = vect[index].second;
    }
    return 0;
}

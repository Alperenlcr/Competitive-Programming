#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long int


void solve(vector<int> dizi, int sinir, int n)
{
    ll sum = 0;
    int j = 0, count = 0;
    while (j != n)
    {
        if (sum+1 < dizi[j])
        {
            cout << sum+1 << " ";
            sum += sum+1;
            count ++;
        }
        else
        {
            sum += dizi[j];
            j ++;
        }    
    }
    while (sum < sinir)
    {
        cout << sum+1 << " ";
        sum += sum+1;
        count ++;
    }
    cout << count;
}

int main()
{
    vector<int> dizi;
    int n, sinir,a;
    cin >> n >> sinir;
    // cout << " n: " << n << " sinir :" << sinir << " ";
    for (int t = 0; t < n; t++)
    {
        cin >> a;
        // cout << a << " ";
        dizi.push_back(a);
    }
    sort(dizi.begin(), dizi.end());
    solve(dizi, sinir, n);
    return 0;
}

    // vector<int>::iterator ip;
    // // Sorting the array
    // std::sort(dizi.begin(), dizi.end());
    // // Now v becomes 1 1 2 2 3 3 3 3 7 7 8 10
  
    // // Using std::unique
    // ip = std::unique(dizi.begin(), dizi.begin() + n);
    // // Now v becomes {1 2 3 7 8 10 * * * * * *}
    // // * means undefined
  
    // // Resizing the vector so as to remove the undefined terms
    // dizi.resize(std::distance(dizi.begin(), ip));


// 5
// 1 2 4 5 13

// 1 6 16 50 75
// 1 2 4 6 14 16 44 50 75
// count = sirali ikililerin arasindaki 2 nin ustlerinin sayisi 
// (eger o ust ile ikilinin buyuk olaninin toplami sinirdan buyuk ise veya
// toplam zaten dizide var ise count arttirma)

/*

12 2527
1 2 3 4 5 6 7 8 9 10 11 12

15 16
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 

15
1 12 2

4 12
1 3 5 1 5

3 12
1 3 5

5 90
9 8 7 9 8


20 1000000
3 9 15 111 1111 3 9 15 111 1111 3 3 3 3 3 3 3 3 3 3
*/

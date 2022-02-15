#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;


int main()
{
    unsigned int Q, N, K, i, j=0;
    cin >> Q;
    for ( i = 0; i < Q; i++)
    {
        // N < K ise -1
        cin >> N >> K;
        if (N<K)
            cout << "-1";
        // K 1 ise
        else if (K == 1)
            for ( j = 0; j < N; j++)
                cout << "a";
        // K 2 ise
        else if (K == 2)
        {
            for ( j = 1; j < N; j+=2)
                cout << "ab";
            if (N % 2 == 1)
                cout << "a";
        }
        else
        {
        // N-(K-2) tane harf yazdir   a ve b ile
            int temp = N-(K-2);
            for ( j = 1; j < temp; j+=2)
                cout << "ab";
            if (temp % 2 == 1)
                cout << "a";
        // (K-2) tane harf yazdir c den itibaren
            for ( j = 0; j < K-2; j++)
                cout << (char)('c'+j);
        }
		cout << "\n";
    }
    return 0;
}
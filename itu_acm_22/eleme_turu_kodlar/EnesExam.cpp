#include <bits/stdc++.h>
using namespace std;


int modpow(int x, int n, int m) {
    if (n == 0) return 1%m;

    long long u = modpow(x,n/2,m);
    u = (u*u)%m;

    if (n%2 == 1) u = (u*x)%m;

    return u;
}







int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a,b;
    cin >> a >> b ;
    int x = modpow(a,b,(pow(10,9)+7));
    if (x == 0) x = 9;
    
    
    
    cout << x << endl;
    
}
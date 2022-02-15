#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

long long n;
long long ans;
priority_queue<int> q;

inline int read() {
	int n;
    cin>>n;
    return n;
}

int main() {
    n = read();
    for(int i = 1; i <= n; i++) {
        int num = read();
        num-=i,q.push(num);
        if(num < q.top()) {
            ans += q.top() - num;
            q.pop();
            q.push(num);
        }
    }
    printf("%lld\n", ans);
}

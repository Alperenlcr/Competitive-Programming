
#include<bits/stdc++.h>
using namespace std;

long long n,sum;
priority_queue<long long>q;
int main()
{
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		x-=i;
		q.push(x);
		long long tp=q.top();
		if(x<tp)
		{
			sum+=tp-x;
			q.pop();
			q.push(x);
		}
	}
	cout<<sum;
	return 0;
}
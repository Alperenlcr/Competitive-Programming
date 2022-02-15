#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;


int main()
{
    int N, temp;
    scanf("%d", &N);
    vector<int> a;
    for (int i = 0; i < N; i++)
    {
        cin>>temp;
        a.push_back(temp);
    }
    sort(a.begin(),a.end());
    int max=0, min=99999999;
    for (int i = 0; i < N/2; i++)
    {
        temp = a.front() + a.back();
        a.pop_back();
        a.erase(a.begin());
        if (temp > max)
            max = temp;
        else if (temp < min)
            min = temp;
    }
    cout<<max-min;
	return 0;
}

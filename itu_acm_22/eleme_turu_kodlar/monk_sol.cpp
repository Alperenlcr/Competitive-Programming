#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define MAX 19

ll dp[1<<MAX][MAX];
int vis[1<<MAX][MAX],n,m;
int g[MAX][MAX];

ll dfs(int st,int cur,int u)
{
    if(vis[st][u]) return dp[st][u];
    vis[st][u]=1;
    ll &ans=dp[st][u];
    ans=0;
    for(int v=cur;v<n;v++)
        if(g[u][v])
        {
            if(v==cur && st!=((1<<v)|(1<<u))) ans++;
            else if(v!=cur && ((st&(1<<v))==0)) ans+=dfs(st^(1<<v),cur,v);
        }
    return ans;
}

int main()
{
    cin >> n >> m;
    while(m--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        u--;v--;
        g[u][v]=g[v][u]=1;
    }
    ll ans=0;
    for(int i=0;i<n;i++) ans+=dfs((1<<i),i,i);
    cout<<ans/2;
    return 0;
}
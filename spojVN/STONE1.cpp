#include <bits/stdc++.h>
using namespace std;
#define md 5*int(1e6)+5
int f[md],u,m,n;
vector<int> adj[md];
int b[md];
inline void dfs(int u)
{
    if (adj[u].size()==0)
    {
        f[u]=1;
        return;
    }
    for(int i=0;i<adj[u].size();i++)
        dfs(adj[u][i]);
    int r=0,sum=0,Max=0;
    for(int i=0;i<adj[u].size();i++)
        b[++r]=f[adj[u][i]];
    sort(b+1,b+1+r);
    for(int i=r;i>=1;i--)
        if (b[i]>Max)
        {
            sum+=b[i]-Max;
            Max=b[i]-1;
        }
        else Max--;
    f[u]=sum;
}
main()
{
    //freopen("test.inp","r",stdin);
    scanf("%d",&n);
    while (scanf("%d%d",&u,&m)!=EOF)
    {
        for(int i=1;i<=m;i++)
        {
            int v;
            scanf("%d",&v);
            adj[u].push_back(v);
        }
    }
    dfs(1);
    printf("%d",f[1]);
}

#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
vector<ii> adj[100001];
int r,n,m,w;
int dd[100001];
bool visited[1000001];
void dfs(int s)
{
    for(int i=0;i<adj[s].size();i++)
    {
        int u=adj[s][i].first;
        int v=adj[s][i].second;
        if (!visited[v])
        {
            visited[v]=true;
            dfs(u);
        }
    }
    r++;
    dd[r]=s;
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&w);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(ii(v,i));
        adj[v].push_back(ii(u,i));
    }
    dfs(1);
    printf("%d\n",r-1);
    for(int i=r;i>=1;i--)
        printf("%d ",dd[i]);
}

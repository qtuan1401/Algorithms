#include <bits/stdc++.h>

using namespace std;
list<int> *adj;
bool visited[100000];
int trace[100000];
int a[2005][2005],n,q;
void Dfs(int u)
{
    visited[u]=false;
    list<int>:: iterator i;
    for(i=adj[u].begin();i!=adj[u].end();i++)
        if (visited[*i])
        {
            trace[*i]=u;
            Dfs(*i);
        }
}
void dfs(int v)
{
   // bool *visited=new bool[n+1];
    for(int i=1;i<=n;i++)
        visited[i]=true;
    Dfs(v);
}
main()
{
    ios::sync_with_stdio(false);
    cin >> n >> q;
    adj=new list<int>[n+1];
    int u,v,k;
    for(int i=1;i<n;i++)
    {
        cin >> u >> v >> k;
        a[u][v]=a[v][u]=k;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    while (q--)
    {
        cin >> u >> v;
        dfs(u);
        int res=0;
        while (v!=u)
        {
            res+=a[v][trace[v]];
            v=trace[v];
        }
        cout << res << "\n";
    }
}

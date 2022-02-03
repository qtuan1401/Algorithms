#include <bits/stdc++.h>

using namespace std;
vector<int> adj[100001];
int i,u,v,k,n,d=0;
unsigned long long int res;
bool visited[100001];
long long int c[10000][10000];
int dfs(int v)
{
    int Count=1;
    vector<int>:: iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++)
        if (!visited[*i])
        {
            visited[*i]=true;
            int t=dfs(*i);
            res=res+c[*i][v]*t*(n-t);
            Count+=t;
        }
    return Count;
}
main()
{
    cin >> n;
    for(int i=1;i<n;i++)
    {
        cin >> u >> v >> k;
        adj[u].push_back(v);
        adj[v].push_back(u);
        c[u][v]=k;
        c[v][u]=k;
    }
    visited[0]=true;
    dfs(0);
    cout << res;
}

#include <bits/stdc++.h>

using namespace std;
vector<int> adj[10005];
int n,k,res;
inline int dfs(int u)
{
    int Count=1,v;
    vector<int>::iterator i;
    for(i=adj[u].begin();i!=adj[u].end();i++)
    {
        v=*i;
        Count+=dfs(v);
    }
    if  (Count>=k)
    {
        res++;
        Count=0;
    }
    return Count;
}
main()
{
    ios::sync_with_stdio(false);
    cin >> k >> n;
    int v;
    for(int i=2;i<=n;i++)
    {
        cin >> v;
        adj[v].push_back(i);
    }
    dfs(1);
    cout << res;
}

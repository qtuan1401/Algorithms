#include <bits/stdc++.h>

using namespace std;
vector<int> adj[10001];
int f[10001][3],n;
bool visited[10001],check;
void dfs(int v)
{
   // f[v][2]=1;
    vector<int> :: iterator i;
    bool check=false;
    visited[v]=true;
    int Min=32767;
    f[v][2]=1;
    f[v][1]=f[v][0]=0;
    for(i=adj[v].begin();i!=adj[v].end();i++)
        if (!visited[*i])
        {
           // visited[*i]=true;
            dfs(*i);
            f[v][2]+=min(f[*i][0],min(f[*i][1],f[*i][2]));
            f[v][0]+=f[*i][1];
            if (f[*i][2]<=f[*i][1]) check=true;
            Min=min(f[*i][2]-f[*i][1],Min);
            f[v][1]+=min(f[*i][1],f[*i][2]);

        }
        visited[v]=false;
        if (!check) f[v][1]+=Min;
}
main()
{
    ios::sync_with_stdio(false);
    while(true)
    {
        cin >> n;
        if (!n)
            break;
        else
        {
            for(int i=1;i<=1000;i++) adj[i].clear();
            for(int i=0;i<=n;i++)
                f[i][0]=f[i][1]=f[i][2]=32767;
            for(int i=1;i<=n;i++)
                visited[i]=false;
            for(int i=1;i<n;i++)
            {
                int u,v;
                cin >> u >> v;
           //     f[u][2]=f[v][2]=1;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            dfs(1);
            cout << min(f[1][1],f[1][2]) << "\n";
        }
    }
}


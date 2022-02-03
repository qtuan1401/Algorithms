#include <bits/stdc++.h>

using namespace std;
bool visited[10001];
vector<int> adj[10001];
int n,m,s;
int d[10001],res;
bool dd[10000][10000];
void bfs(int s)
{
    for(int i=0;i<=n+1;i++)
        visited[i]=false;
    queue<int> Queue;
    Queue.push(s);
   // visited[s]=true;
    vector<int>:: iterator i;
    for(int i=1;i<=n+1;i++) d[i]=30000;
    d[s]=0;
    while (!Queue.empty())
    {
        int s=Queue.front();
        Queue.pop();
        for(i=adj[s].begin();i!=adj[s].end();i++)
            {
              //cout << s << " " << *i << " " << d[s] << " " << d[*i] << endl;
                if (d[*i]>d[s]+1)
                {
                    d[*i]=d[s]+1;
                    Queue.push(*i);
                    if (visited[s])
                    {
                        if (!visited[*i])
                        {
                            //cout << *i << endl;
                            visited[*i]=true;
                            res++;
                        }
                    }
                }
                else if (d[*i]==d[s]+1)
                {
                    if (!visited[*i])
                    {
                        //cout << *i << endl;
                        visited[*i]=true;
                        res++;
                    }
                }
            }
    }
    cout << res;
}
main()
{
    //freopen("stable.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m >> s;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        if (!dd[u][v]) adj[u].push_back(v);
        dd[u][v]=true;
    }
    bfs(s);
    //cout << res;
}

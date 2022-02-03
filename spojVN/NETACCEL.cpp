#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<double,int> fi;
typedef pair<double,ii> fii;
#define INF double(1e15+5)
#define md int(1e5)+5
double f[md][25];
int n,m,k;
vector<fi> adj[md];
bool vis[md][25];
inline void dijkstra(int s)
{
    priority_queue<fii, vector<fii>, greater<fii> > heap;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
            f[i][j]=INF;
    for(int i=0;i<=k;i++)
    {
        f[s][i]=0;
        heap.push(fii(0,ii(s,i)));
    }
    while (!heap.empty())
    {
        fii val=heap.top();
        heap.pop();
        double du=val.first;
        int u=val.second.first;
        int c=val.second.second;
        vis[u][c]=true;
        if (u==n && c==k)
            break;
        if (du!=f[u][c])
            continue;
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i].second;
            double uv=adj[u][i].first;
            int sl=1;
            for(int j=c;j<=k;j++)
            {
           //     cout << j<< " "<<u << " "<<v << " "<<f[u][c] << " "<<uv/sl <<endl;
                if (!vis[v][j] && f[v][j]>(f[u][c]+(uv/sl)))
                {
                    f[v][j]=f[u][c]+(uv/sl);
                    heap.push(fii(f[v][j],ii(v,j)));
                }
                sl*=2;
            }
        }
    }
}
main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        double w;
        int u,v;
        scanf("%d%d%lf",&u,&v,&w);
        adj[u].push_back(fi(w,v));
        adj[v].push_back(fi(w,u));
    }
    dijkstra(1);
    printf("%.2lf",f[n][k]);
}
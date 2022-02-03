#include <bits/stdc++.h>
using namespace std;
#define md int(1e6)+5
#define INF int(1e9)
typedef pair<int,int> ii;
vector<ii> adj[md];
int res[md],d[md],d1[md],n,m;
long long f[md],f1[md];
inline void dijkstra(int s)
{
    priority_queue<ii, vector<ii>, greater<ii> > heap;
    for(int i=1;i<=n;i++)
        d[i]=INF;
    for(int i=1;i<=n;i++)
        f[i]=0;
    heap.push(ii(0,s));
    f[s]=1;
    d[s]=0;
    while (!heap.empty())
    {
        ii val=heap.top();
        heap.pop();
        int du=val.first;
        int u=val.second;
        if (d[u]!=du)
            continue;
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i].second;
            int uv=adj[u][i].first;
            if (d[v]>du+uv)
            {
                d[v]=du+uv;
                f[v]=f[u];
                heap.push(ii(d[v],v));
            }
            else if (d[v]==du+uv)
                f[v]+=f[u];
        }
    }
}
main()
{
    //freopen("test.inp","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        adj[u].push_back(ii(w,v));
        adj[v].push_back(ii(w,u));
    }
    dijkstra(1);
    for(int i=1;i<=n;i++)
        f1[i]=f[i],d1[i]=d[i];
    dijkstra(n);
    int r=0;
    for(int i=1;i<=n;i++)
        if ((d1[i]+d[i]>d1[n]) || (f1[i]*f[i]!=f1[n]))
            res[++r]=i;
    printf("%d\n",r);
    for(int i=1;i<=r;i++)
        printf("%d\n",res[i]);
}

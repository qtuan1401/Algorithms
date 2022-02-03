#include <bits/stdc++.h>
using namespace std;
#define md 100005
#define INF 5*int(1e9)
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
int ds[md],dt[md],n,m,s,t,k,q;
vector<ii> adjt[md],adjs[md];
inline void dijkstra(int s,int *d,vector<ii> *adj)
{
    priority_queue<ii, vector<ii>, greater<ii> > heap;
    for(int i=1;i<=n;i++)
        d[i]=INF;
    d[s]=0;
    heap.push(ii(0,s));
    while (!heap.empty())
    {
        ii val=heap.top();
        heap.pop();
        int u=val.second;
        int w=val.first;
        if (w!=d[u])
            continue;
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i].second;
            int wv=adj[u][i].first;
            if (d[v]>w+wv)
            {
                d[v]=w+wv;
                heap.push(ii(d[v],v));
            }
        }
    }
}
main()
{
    scanf("%d",&q);
    while (q--)
    {
        scanf("%d%d%d%d%d",&n,&m,&k,&s,&t);
        for(int i=1;i<=n;i++)
            adjs[i].clear(),adjt[i].clear();
        for(int i=1;i<=m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            adjs[u].push_back(ii(w,v));
            adjt[v].push_back(ii(w,u));
        }
        dijkstra(s,ds,adjs);
        dijkstra(t,dt,adjt);
        int res=min(ds[t],dt[s]);
        for(int i=1;i<=k;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            res=min(res,min(ds[u]+w+dt[v],ds[v]+w+dt[u]));
        }
       // dijkstra(s);
        if (res==INF)
            printf("-1\n");
        else printf("%d\n",res);
    }
}

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<long long,ii> iii;
#define md int(1e5)+5
#define INF (long long)(1e15)
int n,k,j,m,s,t;
long long f[md][6];
vector< pair<long long,int> > adj[md];
inline void dijkstra(int s)
{
    priority_queue<iii, vector<iii>, greater<iii> > heap;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
            f[i][j]=INF;
   // for(int i=0;i<=k;i++)
        f[s][0]=0;
    heap.push(iii(0,ii(s,0)));
    while (!heap.empty())
    {
        iii val=heap.top();
        heap.pop();
        long long w=val.first;
        int u=val.second.first;
        int x=val.second.second;
        if (u==t)
            break;
        if (w!=f[u][x])
            continue;
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i].second;
            long long uw=adj[u][i].first;
            if (x<k)
            {
                if (f[v][x+1]>f[u][x])
                {
                    f[v][x+1]=f[u][x];
                    heap.push(iii(f[v][x+1],ii(v,x+1)));
                }
            }
                if (f[v][x]>f[u][x]+uw)
                {
                    f[v][x]=f[u][x]+uw;
                    heap.push(iii(f[v][x],ii(v,x)));
 
            }
        }
    }
}
main()
{
    scanf("%d%d%d%d%d",&n,&m,&k,&s,&t);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        adj[u].push_back(ii(w,v));
        adj[v].push_back(ii(w,u));
    }
    dijkstra(s);
    long long res=INF;
    for(int i=0;i<=k;i++)
        res=min(res,f[t][i]);
    printf("%lld",res);
}
#include <bits/stdc++.h>
using namespace std;
#define md 50005
#define INF (long long)(1e15)
long long d[md],f[md];
int n,m;
typedef pair<long long,int> lli;
typedef pair<int,int> ii;
vector<lli> adj[md];
inline void dijkstra(int s)
{
    for(int i=1;i<=n;i++)
        d[i]=INF;
    priority_queue<lli, vector<lli>, greater<lli> > heap;
    heap.push(lli(0,s));
    d[s]=0;
    f[s]=1;
    while (!heap.empty())
    {
        lli val=heap.top();
        heap.pop();
        long long du=val.first;
        int u=val.second;
        //cout << u << " ";
        if (du!=d[u])
            continue;
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i].second;
          //  cout << v << " ";
            long long uv=adj[u][i].first;
            if (d[v]>du+uv)
            {
                d[v]=du+uv;
                f[v]=f[u];
                //cout << f[u] << " " <<f[v] <<endl;
                heap.push(lli(d[v],v));
            }
            else if (d[v]==du+uv)
            {
                f[v]+=f[u];
            }
        }
        //cout <<endl;
    }
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int k,u,v,w;
        scanf("%d%d%d%lld",&k,&u,&v,&w);
        adj[u].push_back(ii(w,v));
        if (k==2)
        {
            adj[v].push_back(ii(w,u));
            //cout << v << " "<<u<<endl;
        }
    }
   // for(int i=1;i<=n;i++)
     //   adj[i].push_back(ii(0,i));
    dijkstra(1);
    printf("%lld %lld",d[n],f[n]);
}

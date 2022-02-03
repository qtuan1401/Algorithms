#include <bits/stdc++.h>

using namespace std;
#define maxn 5e6+1
bool Free[505];
int cost[505],d[505],a[505][505],b[505][505],Pow[505],n,m;
int dijkstra(int w)
{
    for(int i=1;i<=n;i++)
    {
        d[i]=maxn;
        Free[i]=true;
        cost[i]=-1;
    }
    d[1]=0;
    cost[1]=w;
    int u=0;
    while(true)
    {
        int Min=maxn;
        for(int i=1;i<=n;i++)
            if (Free[i] && Min>d[i])
            {
                Min=d[i];
                u=i;
            }
        if (Min==maxn || u==n) break;
        Free[u]=false;
        for(int i=1;i<=n;i++)
            if (a[u][i]!=maxn && cost[u]-b[u][i]>=0)
            {
                if (d[i]<d[u]+a[u][i]) continue;
                if (d[i]>d[u]+a[u][i])
                {
                    d[i]=d[u]+a[u][i];
                    cost[i]=cost[u]-b[u][i];
                }
                else cost[i]=max(cost[i],cost[u]-b[u][i]);
                if (Pow[i]) cost[i]=w;
            }
    }
    return d[n];
}
void bs(int l,int r,int k)
{
    while (l<=r)
    {
        int Mid=(l+r)>>1;
        if (dijkstra(Mid)==k) r=Mid-1;
        else l=Mid+1;
    }
    cout << l;
}
main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> Pow[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            a[i][j]=a[j][i]=maxn;
        }
    int u,v,t,c,m;
    cin >> m;
    for(int i=1;i<=m;i++)
    {
        cin >> u >> v >> t >> c;
        a[u][v]=a[v][u]=t;
        b[u][v]=b[v][u]=c;
    }
    int Min=dijkstra(maxn);
    bs(0,maxn,Min);
}


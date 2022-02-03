#include <bits/stdc++.h>
using namespace std;
#define md 5000005
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
long long res;
int lab[md],w,n,m,c[md];
iii graph[md];
inline int root(int x)
{
    while (lab[x]>0)
        x=lab[x];
    return x;
}
inline void Union(int i,int j)
{
    int tmp=lab[i]+lab[j];
    if (lab[i]<lab[j])
    {
        lab[j]=i;
        lab[i]=tmp;
    }
    else
    {
        lab[i]=j;
        lab[j]=tmp;
    }
}
inline void kruskal()
{
    for(int i=1;i<=n;i++)
        lab[i]=-1;
    for(int i=1;i<=m;i++)
    {
        int u=graph[i].second.first;
        int v=graph[i].second.second;
        u=root(u);
        v=root(v);
        if (u!=v)
        {
            int k=u;
            res+=graph[i].first;
            Union(u,v);
        }
    }
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        graph[i]=iii(2*w+c[u]+c[v],ii(u,v));
    }
    sort(graph+1,graph+1+m);
    kruskal();
    int Min=100000;
    for(int i=1;i<=n;i++)
        Min=min(Min,c[i]);
    printf("%lld",res+Min);
}

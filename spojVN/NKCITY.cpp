#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<long long,ii> iii;
#define md 10005
iii graph[md];
int n,m,lab[md];
long long res;
inline int root(int x)
{
    while (lab[x]>0)
        x=lab[x];
    return x;
}
inline void Union(int i,int j)
{
    res=0;
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
    res=0;
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
            Union(u,v);
            res=max(res,graph[i].first);
        }
    }
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%lld",&u,&v,&w);
        graph[i]=iii(w,ii(u,v));
    }
    sort(graph+1,graph+1+m);
    kruskal();
    printf("%lld",res);
}
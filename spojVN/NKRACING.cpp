#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
#define md 100005
iii graph[md];
int lab[md],n,m;
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
    long long sum=0,s=0;
    for(int i=1;i<=n;i++)
        lab[i]=-1;
    for(int i=m;i>=1;i--)
    {
        sum+=graph[i].first;
        int u=graph[i].second.first;
        int v=graph[i].second.second;
        u=root(u);
        v=root(v);
        if (u!=v)
        {
            Union(u,v);
            s+=graph[i].first;
        }
    }
    printf("%lld",sum-s);
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        graph[i]=iii(w,ii(u,v));
    }
    sort(graph+1,graph+1+m);
    kruskal();
}

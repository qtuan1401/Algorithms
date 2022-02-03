#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
#define md 10010
int id[md],lab[md];
vector< iii > graph;
int n,m;
long long int s;
int root(int i)
{
    while (lab[i]>0) i=lab[i];
    return i;
}
void Union(int i,int j)
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
void kruskal()
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
            Union(u,v);
            s+=graph[i].first;
        }
    }
}
main()
{
    //freopen("test.inp","r",stdin);
    scanf("%d%d",&n,&m);
    graph.resize(m+1);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        graph[i]=iii(w,ii(u,v));
    }
    sort(graph.begin(),graph.end());
    kruskal();
    printf("%lld",s);
}
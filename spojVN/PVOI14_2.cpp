#include <bits/stdc++.h>
using namespace std;
#define md 5*1000000+5
int a[1001][1001];
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
vector< ii > adj[md];
int n,r;
int s=0;
int Max=0;
int deltaX[2]={0,1};
int deltaY[2]={1,0};
int Rank[md];
int root(int i)
{
    while (Rank[i]>0) i=Rank[i];
    return i;
}
int Union(int i,int j)
{
    int tmp=Rank[i]+Rank[j];
    if (Rank[i]<Rank[j])
    {
        Rank[j]=i;
        Rank[i]=tmp;
    }
    else
    {
        Rank[i]=j;
        Rank[j]=tmp;
    }
    return -tmp;
}
void kruskal()
{
    for(int i=0;i<=Max;i++)
    {

        for(int j=0;j<adj[i].size();j++)
        {
            Rank[adj[i][j].first]=-1;
            Rank[adj[i][j].second]=-1;
        }
        for(int j=0;j<adj[i].size();j++)
        {
            int u=adj[i][j].first;
            int v=adj[i][j].second;
            u=root(u);
            v=root(v);
            if (u!=v)
                s=max(s,Union(u,v));
        }
    }
}
int get(int i,int j)
{
    return (i-1)*n+j;
}
main()
{
    //  freopen("test.inp","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
                Max=max(Max,a[i][j]);
            }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            {
                if (i<n) adj[abs(a[i+1][j]-a[i][j])].push_back(ii(get(i,j),get(i+1,j)));
                if (j<n) adj[abs(a[i][j+1]-a[i][j])].push_back(ii(get(i,j),get(i,j+1)));
            }
    memset(Rank,-1,sizeof(Rank));
    kruskal();
    printf("%d",s);
}

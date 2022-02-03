#include <bits/stdc++.h>
using namespace std;
struct node
{
    int x,ts;
    node(int a=0,int b=0)
    {
        x=a;
        ts=b;
    }
};
vector<node> adj[100001];
bool visited[100001];
int par[100001],ts[100001],k[100001],f[100001][18],d[100001][18],c[100001][18],n,q;
inline void prepare(int u)
{
    visited[u]=true;
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i].x;
        if (!visited[v])
        {
            int t=adj[u][i].ts;
            par[v]=u;
            d[v][1]=u;
            f[v][1]=c[v][1]=t;
            k[v]=k[u]+1;
            ts[v]=t;
            for(int i=2;i<=17;i++)
                if (d[v][i-1]!=0 && d[d[v][i-1]][i-1])
                {
                    f[v][i]=max(f[v][i-1],f[d[v][i-1]][i-1]);
                    c[v][i]=min(c[v][i-1],c[d[v][i-1]][i-1]);
                    d[v][i]=d[d[v][i-1]][i-1];
                }
            prepare(v);
        }
    }
}
inline void lca(int x,int y)
{
    int Min=(1<<31)-1;
    int Max=-(1<<31);
    int j;
    if (k[y]>k[x])
    {
        j=x;
        x=y;
        y=j;
    }
    while (k[x]>k[y])
    {
        for(int i=17;i>=1;i--)
            if (d[x][i]!=0 && k[d[x][i]]>=k[y])
            {
                j=i;
                break;
            }
        Max=max(Max,f[x][j]);
        Min=min(Min,c[x][j]);
        x=d[x][j];
    }
    while (x!=y)
    {
        j=1;
        for(int i=17;i>=1;i--)
            if (d[x][i]!=0 && d[x][i]!=d[y][i])
            {
                j=i;
                break;
            }
        Max=max(Max,max(f[x][j],f[y][j]));
        Min=min(Min,min(c[x][j],c[y][j]));
        x=d[x][j];
        y=d[y][j];
    }
    printf("%d %d\n",Min,Max);
}
main()
{
    //freopen("test.inp","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int u,v,j;
        scanf("%d%d%d",&u,&v,&j);
        adj[u].push_back(node(v,j));
        adj[v].push_back(node(u,j));
        for(int i=1;i<=17;i++)
            f[i][j]=-(1<<31);
    }
    prepare(1);
    scanf("%d",&q);
    while (q--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        lca(u,v);
    }
}

#include <bits/stdc++.h>
using namespace std;
#define md int(1e5+5)
int low[md],num[md],cnt,n,m,edge,verticle;
bool check[md];
vector<int> adj[md];
inline void bv(int u,int s)
{
    int child=0;
    low[u]=num[u]=++cnt;
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if (v!=s)
        {
            if (num[v])
                low[u]=min(num[v],low[u]);
            else
            {
                bv(v,u);
                child++;
                low[u]=min(low[u],low[v]);
                if (low[v]>=num[v])
                    edge++;
                if (u==s)
                {
                    if (child>=2)
                        check[u]=true;
                }
                else
                {
                    if (low[v]>=num[u])
                        check[u]=true;
                }
            }
        }
    }
}
main()
{
    //freopen("test.inp","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        if (!num[i])
            bv(i,i);
    for(int i=1;i<=n;i++)
        if (check[i])
            verticle++;
    printf("%d %d",verticle,edge);
}

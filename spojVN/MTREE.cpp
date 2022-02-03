#include <bits/stdc++.h>
using namespace std;
#define md int(1e5)+5
typedef pair<int,int> ii;
const long long mod=(long long)(1e9+7);
const long long Div=(long long)(5e8)+4;
long long weight[md],pre[md],par[md];
int n,m;
vector<ii> adj[md];
bool vis[md];
inline void dfs(int u)
{
    vis[u]=true;
    long long sum=0,val=0;
    //cout << u <<endl;
    //cout << u <<endl;
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i].first;
        int w=adj[u][i].second;
        if (!vis[v])
        {
            dfs(v);
            long long tmp=((pre[v]+1)*w)%mod;
            sum=(sum+((tmp*tmp)%mod))%mod;
            val=(val+tmp)%mod;
            weight[u]+=weight[v];
        }
    }
    long long t=(((val*val)%mod-sum+mod)%mod*Div)%mod;
    weight[u]=(weight[u]+t)%mod;
    weight[u]=(weight[u]+val)%mod;
    //cout << u << " "<<val << " "<<sum << " "<< pre[u] << " "<<weight[u] <<endl;
    pre[u]=val;
}
int main()
{
    //freopen("test.inp","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
    {
        int w,u,v;
        scanf("%d%d%d",&u,&v,&w);
        adj[u].push_back(ii(v,w));
        adj[v].push_back(ii(u,w));
    }
    vis[1]=true;
    dfs(1);
    printf("%lld",weight[1]);
    return 0;
}

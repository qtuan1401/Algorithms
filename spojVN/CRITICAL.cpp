#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
#define Forr(i,a,b) for(int i=(a);i<(b);i++)
#define For(i,b) for(int i=1;i<=(b);i++)
#define md int(2e5+5)
using namespace std;
int res[md],low[md],num[md],cnt[md],c[md],child[md],r,Cnt=0,n,m;
bool check[md],vis[md];
double ans;
vector<int> adj[md];
inline void dfs(int u)
{
    vis[u]=true;
    c[r]++;
   // cout << u <<endl;
    Forr(i,0,adj[u].size())
    {
        int v=adj[u][i];
        if (!vis[v])
            dfs(v);
    }
}
inline void solve(int u,int s)
{
    num[u]=low[u]=++Cnt;
    child[u]=0;
    int tmp=0;
    cnt[u]=1;
    res[u]=0;
    Forr(i,0,adj[u].size())
    {
        int v=adj[u][i];
        if (v!=s)
        {
            if (num[v])
                low[u]=min(low[u],num[v]);
            else
            {
                solve(v,u);
                low[u]=min(low[v],low[u]);
                child[u]++;
                cnt[u]+=cnt[v];
                if (low[v]>=num[u])
                {
                    check[u]=true;
                    res[u]+=(tmp*cnt[v]);
                    tmp+=cnt[v];
                }
            }
        }
    }
    res[u]+=tmp*(c[r]-tmp-1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("test.inp","r",stdin);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(2);
    cin >> n >> m;
    For(i,m)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    For(i,n)
        if (!vis[i])
        {
            r++;
            dfs(i);
        }
    r=0;
    For(i,n)
        if (!num[i])
        {
            r++;
            solve(i,i);
            if (child[i]<2)
                check[i]=false;
        }
    For(i,n)
        if (check[i])
            ans+=res[i];
    cout << ans/n;
}

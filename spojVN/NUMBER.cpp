#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,a) for(int i=1;i<=(a);i++)
#define md int(1e6+5)
typedef pair<int,int> ii;
int dd[md],res;
ii a[md];
int n,m,low[md],num[md],r,cnt,deg[md],t;
vector<int> adj[md];
stack<int> st;
bool check[md];
const int oo = int(1e9);
inline void tarjan(int u)
{
    num[u]=low[u]=++cnt;
    st.push(u);
    FORR(i,0,adj[u].size())
    {
        int v=adj[u][i];
        if (num[v])
            low[u]=min(low[u],num[v]);
        else
        {
            tarjan(v);
            low[u]=min(low[v],low[u]);
        }
    }
    if (num[u]==low[u])
    {
        r++;
        int v;
        do
        {
            v=st.top();
            st.pop();
            dd[v]=r;
            low[v]=num[v]=oo;
        } while (u!=v);
    }
}
main()
{
   // freopen("test.inp","r",stdin);
    scanf("%d%d%d",&n,&m,&t);
    rep(i,m)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        a[i]=ii(u,v);
        adj[u].push_back(v);
    }
    rep(i,n)
        if (!num[i])
            tarjan(i);
    rep(i,m)
    {
        int u=a[i].first;
        int v=a[i].second;
        if (dd[u]!=dd[v])
            deg[dd[u]]++;
    }
    deg[dd[t]]=-1;
    rep(i,r)
        if (!deg[i])
            res++;
    printf("%d",res);
}

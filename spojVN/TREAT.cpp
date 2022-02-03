#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=(n);i++)
#define FORR(i,a,b) for(int i=(a);i<(b);i++)
#define md int(1e5+5)
#define INF int(1e9)
vector<int> adj[md];
int low[md],num[md],n,m,cnt=0,res,root[md],dis[md],r,f[md];
stack<int> st;
queue<int> q;
int a[md];
inline void tarjan(int u)
{
    low[u]=num[u]=++cnt;
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
        int v,ans=0;
        r++;
       // cout << u <<endl;
        do
        {
            v=st.top();
            st.pop();
    //        cout << v << " ";
            root[v]=r;
            num[v]=low[v]=INF;
            ans++;
           // a[ans]=v;
        } while (u!=v);
        dis[r]=ans;
  //      cout << endl <<endl;;
        //rep(i,1,ans)
          //  dis[i]=ans;
    }
}
inline int calc(int u)
{
//    cout << u <<endl;
    if (!f[u])
    {
        if (dis[root[u]]>1 || (dis[root[u]]==1 && adj[u][0]==u))
            f[u]=dis[root[u]];
        else
            f[u]=calc(adj[u][0])+1;
    }
    return f[u];
}
main()
{
   // freopen("test.inp","r",stdin);
    scanf("%d",&n);
    rep(i,n)
    {
        int v;
        scanf("%d",&v);
    //    cout << i << " "<<v <<endl;
        adj[i].push_back(v);
    }
    //cout << adj[1][0] <<endl;
    rep(i,n)
        if (!num[i])
            tarjan(i);
    //cout << root[3] <<endl;
    rep(i,n)
        printf("%d\n",calc(i));
}

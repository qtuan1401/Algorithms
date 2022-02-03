#include <bits/stdc++.h>
#define REP(i,n) for(int i=1;i<=(n);i++)
#define FORP(i,u) for(int i=0;i<adj[u].size();i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define md int(1e5+5)
using namespace std;
typedef pair<int,int> ii;
stack<ii> st;
int low[md],num[md],cnt,res,n,m;
vector<int> adj[md];
inline void visit(int u,int s)
{
    num[u]=low[u]=++cnt;
    FORP(i,u)
    {
        int v=adj[u][i];
        if (v!=s)
        {
            if (num[v])
                low[u]=min(low[u],num[v]);
            else
            {
                st.push(ii(u,v));
                visit(v,u);
                low[u]=min(low[u],low[v]);
                if (low[v]>=num[u])
                {
                    int ans=0,p,q;
                    do
                    {
                        ii cur=st.top();
                        st.pop();
                        p=cur.first;
                        q=cur.second;
                      //  cout << q <<" ";
                        ans++;
                    } while (u!=p || v!=q);
                    ans++;
                    //cout << p <<endl;
                    res=max(res,ans);
                }
            }
        }
    }
}
main()
{
   // freopen("test.inp","r",stdin);
    scanf("%d%d",&n,&m);
    REP(i,m)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    REP(i,n)
        if (!num[i])
            visit(i,i);
    printf("%d",max(res,1));
}

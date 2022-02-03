#include <bits/stdc++.h>
#define task "test"
#define fi task".inp"
#define fo task".out"
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
#define forl(i,a,b) for(int i=(a);i>=(b);i--)
#define maxN int(1e4)
#define INF int(1e9)+1
#define Memset(a,value) memset(a,value,sizeof(a))
#define Forr(i,a) for(vector<int>:: iterator i=(a).begin();i!=(a).end();i++)
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
#define max_heap(type) priority_queue<type>
#define min_heap(type) p0riority_queue<type,vector<type>,greater<type> >
vector<int> adj[maxN];
int a[maxN],v[maxN],c[maxN],n,m,s[maxN];
bool visited[maxN];
int dp[maxN][maxN],g[maxN][maxN];
inline void dfs(int u)
{
    int r=0;
    s[u]=c[u];
    int st[maxN];
    visited[u]=true;
    Forr(i,adj[u])
        if (!visited[*i])
        {
            dfs(*i);
            r++;
            st[r]=*i;
            s[u]+=s[*i];
        }
    //cout << s[u] << " "<< c[u] <<" ";
    int sum=0;
    forr(i,1,r)
        {
        forr(j,0,min(s[u]-c[u],m))
            g[i][j]=0;
        }
    forr(i,1,r)
    {

        sum+=s[st[i]];
        forr(j,0,min(sum,m))
            forr(t,0,min(s[st[i]],j))
                g[i][j]=max(g[i][j],g[i-1][j-t]+dp[st[i]][t]);
    }
    forr(i,0,min(s[u]-c[u],m))
        dp[u][i+c[u]]=g[r][i]+v[u];//cout << dp[u][i+c[u]]<< " " ;
    //cout << endl;
}
main()
{
   //freopen(fi,"r",stdin);
  //  freopen(fo,"w",stdout);
    scanf("%d%d",&n,&m);
    forr(i,2,n)
        scanf("%d",&v[i]);
    forr(i,2,n)
        scanf("%d",&c[i]);
    forr(i,1,n-1)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int res=0;
    dfs(1);
    forr(i,0,m)
        res=max(res,dp[1][i]);
    printf("%d",res);
}


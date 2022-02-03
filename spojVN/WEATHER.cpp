#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
#define Forr(i,a,b) for(int i=(a);i<(b);i++)
typedef pair<int,int> ii;
#define md int(5e3)+5
ii res[md];
vector<int> adj[md];
int n,m;
int par[md],low[md],num[md],cnt,r;
long long ans;
bool vis[md];
inline void brigde(int u)
{
	low[u]=num[u]=++cnt;
	Forr(i,0,adj[u].size())
	{
		int v=adj[u][i];
		if (par[u]!=v)
		{
			if (num[v])
				low[u]=min(low[u],num[v]);
			else
			{
				par[v]=u;
				brigde(v);
				low[u]=min(low[v],low[u]);
				if (low[v]>=num[v])
					res[++r]=ii(u,v);
			}
		}
	}
}
inline void dfs(int u,int s)
{
	vis[u]=true;
	Forr(i,0,adj[u].size())
	{
		int v=adj[u][i];
		if (v!=s && !vis[v])
			dfs(v,s);
	}
}
main()
{
    //freopen("test.inp","r",stdin);
	scanf("%d%d",&n,&m);
	forr(i,1,m)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	forr(i,1,n)
		if (!num[i]) brigde(i);
	forr(i,1,r)
	{
		forr(i,1,n)
			vis[i]=false;
		dfs(res[i].second,res[i].first);
		int cnt=0;
		forr(i,1,n)
			if (vis[i])
				cnt++;
		ans+=(cnt*(n-cnt));
	}
	printf("%lld",ans);
}

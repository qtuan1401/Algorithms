#include <bits/stdc++.h>
using namespace std;
#define md int(1e6)+1
vector<int> adj[md];
int f[md][4],n,s,ans[md];
int vis[md];
inline void dfs(int u)
{
//	vis[u]=true;
	f[u][1]=1;
	f[u][2]=2;
	f[u][3]=3;
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if (vis[u]!=v) 
		{
			vis[v]=u;
			dfs(v);
			f[u][1]+=min(f[v][2],f[v][3]);
			f[u][2]+=min(f[v][1],f[v][3]);
			f[u][3]+=min(f[v][1],f[v][2]);
		}
	}
}
inline void trc(int u,int c)
{
	ans[u]=c;
//	vis[u]=true;
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if (vis[u]!=v)
		{
			if (c==1)
			{
				if (f[v][2]<f[v][3])
					trc(v,2);
				else 
					trc(v,3);
			}
			else if (c==2)
			{
				if (f[v][1]<f[v][3])
					trc(v,1);
				else trc(v,3);
			}
			else
			{
				if (f[v][1]<f[v][2])
					trc(v,1);
				else trc(v,2);
			}
		}
	}
}
main()
{
	//freopen("test.inp","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	int res=min(f[1][1],min(f[1][2],f[1][3]));
	printf("%d\n",res);
	if (res==f[1][1])
		trc(1,1);
	else if (res==f[1][2])
		trc(1,2);
	else trc(1,3);
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
}

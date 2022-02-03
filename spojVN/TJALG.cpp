#include <bits/stdc++.h>
using namespace std;
#define md int(1e5)+5
int low[md],num[md],n,m,res,cnt;
vector<int> adj[md];
stack<int> st;
bool vis[md];
inline void tarjan(int u)
{
	low[u]=num[u]=++cnt;
	st.push(u);
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if (!vis[v])
		{
			if (num[v]!=0)
				low[u]=min(low[u],num[v]);
			else
			{
				tarjan(v);
				low[u]=min(low[u],low[v]);
			}
		}
	}
	if (low[u]==num[u])
	{
		int v;
		res++;
		do
		{
			v=st.top();
			st.pop();
			vis[v]=true;
		} while(u!=v);
	}
}
main()
{
	//freopen("test.inp","r",stdin);
	//freopen("test.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
	}	
	for(int i=1;i<=n;i++)
		if (!num[i])
			tarjan(i);
	printf("%d",res);
}
#include <bits/stdc++.h>
using namespace std;
#define md 10005
vector< int > adj[md];
bool vis[md];
int n, cnt, Rank[md], num[md];
char s[md];
void dfs(int u) {
	vis[u] = true;
	//cout << u << endl;
	for(int i=0;i<adj[u].size();i++) {
		int v = adj[u][i];
	//	cout << v << endl;
		if (!vis[v])
			dfs(v);
	}
	//cout << cnt << " " << u << endl;
	Rank[cnt] = u;
	cnt--;
}
int main() {
	//freopen("test.inp", "r", stdin);
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
			scanf("%s", s);
			for(int j=0;j<n;j++)
				if (s[j] == '1') {
					//cout << i << " " << j + 1 << endl; 
					adj[i].push_back(j + 1);
				}
	}
	cnt = n;
	for(int i=1;i<=n;i++) 
		if (!vis[i]) 
			dfs(i);
	for(int i=1;i<=n;i++)
		cout << Rank[i] << " ";
}
#include <bits/stdc++.h>

using namespace std;

const int M = 1e5 + 10;
const int md = 1e4 + 10;

queue< int > q;

vector< int > adj[M];
bool vis[md];
vector< int > path;
int par[md], _rank[md], inPath[md];
int n, m, s, t, now, cnt, res;

void findpath(int s) {
	q.push(s);
	vis[s] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i=0;i<adj[u].size();i++) {
			int v = adj[u][i];
			if (!vis[v]) {
				vis[v] = true;
				q.push(v);
				par[v] = u;
			}
		}
	}
	for(int v = t; v != s; v = par[v]) 
		path.push_back(v);
	path.push_back(s);
	reverse(path.begin(), path.end());
	memset(vis, false, sizeof vis);
	for(int i=0;i<path.size();i++) {
		_rank[path[i]] = ++cnt;
		inPath[path[i]] = true;

	}
}

void bfs(int s) {
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i=0;i<adj[u].size();i++) {
			int v = adj[u][i];
			if (!vis[v]) {
				vis[v] = true;
				if (inPath[v]) 
					now = max(now, _rank[v]);
				else 
					q.push(v);
			}
		}
	}
}

int main() {
	//freopen("test.inp", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> n >> m >> s >> t;
	for(int i=1;i<=m;i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	findpath(s);
	for(int i=0;i<path.size();i++) {
		int v = path[i];
		//cout << v <<" ";
		if (v != s && v != t && now <= _rank[v])
			res++;
		bfs(v);
	}
	cout << res;
	return 0;
}
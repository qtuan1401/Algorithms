// codeforces 570d

#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > II;

const int MAXN = 5e5 + 10;
const int MAXC = 30;

int sz[MAXN], cnt[MAXN][MAXC], depth[MAXN];
vector < int > adj[MAXN], vec[MAXN];
vector < II > query[MAXN];
int n, m;
string ans[MAXN], s;

void dfs(int u) {
	sz[u] = 1;
	for(auto v : adj[u]) {
		depth[v] = depth[u] + 1;
		dfs(v);
		sz[u] += sz[v];
	}
}

void modify(int u, int val) {
	cnt[depth[u]][s[u] - 'a'] += val;
}

void sack(int u, int keep) {
	int mxSize = -1, bigChild = -1;
	for(auto v : adj[u]) {
		if (mxSize < sz[v]) {
			mxSize = sz[v];
			bigChild = v;
		}
	}
	
	for(auto v : adj[u]) {
		if (v == bigChild) 
			continue;
		sack(v, 0);
	}
	
	if (bigChild != -1) {
		sack(bigChild, 1);
		swap(vec[u], vec[bigChild]);
	}
	
	vec[u].push_back(u);
	modify(u, 1);
	
	for(auto v : adj[u]) {
		if (v == bigChild)
			continue;
		for(auto x : vec[v]) {
			modify(x, 1);
			vec[u].push_back(x);
		}
	}
	
	if (query[u].size() > 0) {
		for(auto cur : query[u]) {
			int depth = cur.first, id = cur.second;
			int cnt1 = 0;
			for(int i = 0; i < 26; i++)
				cnt1 += (cnt[depth][i] & 1);
			if (cnt1 <= 1)
				ans[id] = "Yes";
			else ans[id] = "No";
		}
	}
	
	if (keep == 0) {
		for(auto v : vec[u]) {
			modify(v, -1);
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 2; i <= n; i++) {
		int u;
		cin >> u;
		adj[u].push_back(i);
	}
	cin >> s;
	s = "#" + s;
	for(int i = 1; i <= m; i++) {
		int v, h;
		cin >> v >> h;
		query[v].push_back(II(h, i));
	}
	depth[1] = 1;
	dfs(1);
	sack(1, 1);
	for(int i = 1; i <= m; i++)
		cout << ans[i] << '\n';
	return 0;
}
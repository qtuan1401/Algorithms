#include <bits/stdc++.h>

using namespace std;

const int md = 2e5 + 10;
const int oo = 1e9 + 10;

int n, m, k, res;
vector< int > adj[md];
int dist[md], match[md];

queue< int > q;

bool bfs() {
	for(int i=1;i<=n;i++) 
		if (!match[i]) {
			dist[i] = 0;
			q.push(i);
		} else dist[i] = oo;
	dist[0] = oo;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for(vector<int>::iterator it=adj[u].begin();it!=adj[u].end();it++) {
			if (dist[match[*it]] == oo) {
				dist[match[*it]] = dist[u] + 1;
				q.push(match[*it]);
			}
		}
	}
	return dist[0] != oo;
}

bool dfs(int u) {
	if (u) {
		for(vector<int>::iterator it=adj[u].begin();it!=adj[u].end();it++) {
			if (dist[match[*it]] == dist[u] + 1 && dfs(match[*it])) {
				match[*it] = u;
				match[u] = *it;
				return true;
			}
		}
		dist[u] = oo;
		return false;
	}
	return true;
}

void hopcroft_krap() {
	while (bfs()) 
		for(int i=1;i<=n;i++)
			if (!match[i] && dfs(i)) 
				res++;
}

int main() {
	//freopen("test.inp", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> n >> m >> k;
	for(int i=1;i<=k;i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v + n);
		adj[v + n].push_back(u);
	}
	hopcroft_krap();
	cout << res;
	return 0;
}
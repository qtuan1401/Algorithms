#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 10;

int d[MAXN], p[MAXN];
vector < int > adj[MAXN], radj[MAXN];
int n, m, k, mn, mx;

void bfs(int u) {
	queue < int > q;
	q.push(u);
	d[u] = 0;
	while (q.size()) {
		int u = q.front(); q.pop();
		for(int i = 0; i < radj[u].size(); i++) {
			int v = radj[u][i];
			if (d[v] != -1)
				continue;
			d[v] = d[u] + 1;
			q.push(v);
		}
	}
}

int main() {
//	freopen("test.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		radj[v].push_back(u);
	}
	
	cin >> k;
	for(int i = 0; i < k; i++)
		cin >> p[i];

	for(int i = 1; i <= n; i++)
		d[i] = -1;
	bfs(p[k - 1]);
	/*for(int i = 1; i <= n; i++)
		cout << d[i] << " ";	
	cout << endl;*/
	for(int i = 1; i < k; i++) {
		int pre = p[i - 1], u = p[i];
		//cout << pre << " " << u << " " << i << endl;
		bool diff = false, onWay = false;
		for(int j = 0; j < adj[pre].size(); j++) {
			int v = adj[pre][j];
			//cout << v << " ";
			if (v == u && d[pre] == d[u] + 1)
				onWay = true;
			else if (d[pre] == d[v] + 1)
				diff = true;
		}
		//cout << endl;
		//cout << onWay << " " << diff << endl;
		mn += (!onWay);
		mx += (diff);
	}
	cout << mn << " " << mx;
	return 0;
}
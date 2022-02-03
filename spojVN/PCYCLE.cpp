#include <bits/stdc++.h>

using namespace std;

struct node {
	int x, d, f;
	node(int a = 0, int b = 0, int c = 1) {
		x = a;
		d = b;
		f = c;
	}
};
const int md = 2e2 + 10;

vector< node > adj[md];
int n, m, tt;
int d[md], f[md * md], sum, dem;
bool c[md * md];
bool ok = false;

void euler(int x) {
	if (dem == m && x == 1) {
		ok = true;
		return ;
	}
	for(int i=0;i<=adj[x].size()-1;i++) {
		if (c[adj[x][i].f]) {
			tt++;
			f[tt] = adj[x][i].x;
			c[adj[x][i].f] = false;
			dem++;
			sum += adj[x][i].d;
			if (sum >= 0) 
				euler(adj[x][i].x);
			if (ok)
				return ;
			tt--;
			dem--;
			sum -= adj[x][i].d;
			c[adj[x][i].f] = true;
		}
	}
}

bool cmp(node a, node b) {
	return (a.d > b.d);
}

int main() {
//	freopen("test.inp", "r", stdin);
	cin >> n >> m;
	memset(c, true, sizeof(c));
	for(int i=1;i<=m;i++) {
		int u, v, d;
		cin >> u >> v >> d;
		adj[u].push_back(node(v, d, i));
		adj[v].push_back(node(u, d, i));
	}
	for(int i=1;i<=n;i++) 
		sort(adj[i].begin(), adj[i].end(), cmp);
	tt = 1;
	f[1] = 1;
	euler(1);	
	if (!ok)
		cout << "-1\n";
	else {
		for(int i=1;i<=tt;i++)
			cout << f[i] << " ";
	}
}

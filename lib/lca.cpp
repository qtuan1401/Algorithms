// codeforces 1304e

#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 10;
int par[MAXN], st[MAXN][25], depth[MAXN];
vector < int > adj[MAXN];
int n, q;

void buildTree(int u) {
	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == par[u])
            continue;
        par[v] = u;
        depth[v] = depth[u] + 1;
        buildTree(v);
	}
}
 
void prepare() {
	for(int i = 1; i <= n; i++)
		st[i][0] = par[i];
	for(int k = 1; k <= 20; k++)
		for(int i = 1; i <= n; i++)
			st[i][k] = st[st[i][k - 1]][k - 1];
}
 
int lca(int u, int v) {
    if (depth[u] > depth[v])
        return lca(v, u);
	for(int i = 20; i >= 0; i--)
		if (depth[v] - (1 << i) >= depth[u])
			v = st[v][i];
	if (u == v)
		return u;
	for(int i = 20; i >= 0; i--) 
		if (st[u][i] != st[v][i]) {
			u = st[u][i];
			v = st[v][i];
		}
	return par[u];
}

int calc(int x, int y) {
    int z = lca(x, y);
    //cout << x << " " << y << " " << z << endl;
    return depth[x] + depth[y] - depth[z] * 2;
}

bool check(int a, int b, int x, int y, int k, int len) {
    //cout << a << " " << b << " " << x <<" " << y << endl;
    int lenAX = calc(a, x);
    int lenBY = calc(b, y);
    int lenXY = len;
    int sum = lenAX + lenBY + lenXY;
    //cout << sum << " " << lenAX << " " << lenBY << " " << lenXY << endl;
    if (sum <= k && (k - sum) % 2 == 0)
        return true;
    return false;
}

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    buildTree(1);
    prepare();

    cin >> q;
    while (q--) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        //cout << x << " " << y << " " << a << " " << b << " " << k << endl;
        if (check(a, b, x, y, k, 1) || check(a, b, y, x, k, 1) || check(a, b, a, b, k, calc(a, b)))
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
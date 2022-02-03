#include <bits/stdc++.h>

using namespace std;

const int md = 2e5 + 10;

bool vis[md];
int n;
long long sum, res;
vector < int > adj[md];

void dfs(int u) {
	//cout << u - n << endl;
	vis[u] = true;
	for(auto v: adj[u]) {
		int a = abs(u - n);
		int b = abs(v - n);
		if (a < b)
			swap(a, b);
		sum += a / b;
	//	cout << a << " " << b << endl;
		if (vis[v])
			continue;
		dfs(v);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 2; i <= n; i++) {
		for(int j = i * 2; j <= n; j += i) {
			for(int ii = -1; ii <= 1; ii += 2)
				for(int jj = -1; jj <= 1; jj += 2) {
					//cout << i * ii << " " << j * jj << endl;
					adj[i * ii + n].push_back(j * jj + n);
					adj[j * jj + n].push_back(i * ii + n);
				}
		}
	}
	//cout << endl;
	for(int i = 0; i <= 2 * n; i++) {
		if (!vis[i]) {
			//cout << i - n << endl;
			sum = 0;
			dfs(i);
			res = max(res, sum);
		}
	}
	cout << res / 2;
	return 0;
}
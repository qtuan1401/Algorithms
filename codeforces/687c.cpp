#include <bits/stdc++.h>

using namespace std;

const int MXN = 505;

bool f[2][MXN][MXN];

int main() {
    ios_base::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	f[0][0][0] = 1;
	for(int i = 1; i <= n; i++) {
		int id = i & 1;
        int x;
        cin >> x;
		for(int j = 0; j <= k; j++)
			for(int s = 0; s <= j; s++) {
				f[id][j][s] = f[id ^ 1][j][s];
				if (j >= x) {
				    f[id][j][s] |= f[id ^ 1][j - x][s];
				    if (s >= x)
    					f[id][j][s] |= f[id ^ 1][j - x][s - x];
				}
			}
	}
	vector < int > ans;
	for(int i = 0; i <= k; i++)
		if (f[n % 2][k][i])
			ans.push_back(i);
	cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}
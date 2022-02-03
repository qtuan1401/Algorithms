#include <bits/stdc++.h>

using namespace std;

const int MXN = 2e5 + 10;

int a[MXN], sum[MXN];
int n, k, q;
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k >> q;
	for(int i = 0; i < n; i++) {
		int u, v;
        cin >> u >> v;
		a[u]++;
		a[v + 1]--;
	}
    for(int i = 1; i <= 200000; i++)
		a[i] += a[i - 1];
	for(int i = 1; i <= 200000; i++)
		sum[i] = sum[i - 1] + (a[i] >= k);
	while (q--) {
		int u, v;
		cin >> u >> v;
        cout << sum[v] - sum[u - 1] << '\n';
	}
	return 0;
}
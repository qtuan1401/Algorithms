#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
    vector < int > ans(n);
	for(int i = 0; i < m; i++) {
        int b;
		cin >> b;
		for(int j = b - 1; j < n && ans[j] == 0; j++)
			ans[j] = b;
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
}
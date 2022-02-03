#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
	while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        k = min(k, m - 1);
        vector < int > a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
		int ans = 0;
		for(int i = 0; i <= k; i++) {
			int res = 1e9;
			for(int j = i + 1; j <= m - k + i; j++){
				int l = j - 1, r = j + n - m - 1; 
		    	res = min(res, max(a[l], a[r]));		
			}
            ans = max(ans, res);
		}
        cout << ans << '\n';
	}
}
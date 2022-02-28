#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < int > a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector < long long > sum(2, 0);
        int cnt = 0, cnt1 = 0;
        for (int i = 1; i < n - 1; i++) {
            sum[a[i] % 2] += a[i];
            cnt += a[i] % 2;
			cnt1 += a[i] > 1;
        }

		// cout << cnt << " " << cnt1 << endl;
        if (sum[0] > 0 || (cnt1 >= 1 && cnt > 1))
			cout << sum[0] / 2 + (sum[1] + cnt) / 2 << '\n';
		else cout << "-1\n";
    }
    return 0;
}
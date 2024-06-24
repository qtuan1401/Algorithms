#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        vector < int > a(n);
        vector < long long > d(n + 1, 0), cnt(n + 1, 0), sum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        long long ans = n * (n - 1) / 2;
        for (int i = n; i >= 1; i--) {
            if (cnt[i] == 0) continue;
            long long tot = 0;
            for (int j = i + i; j <= n; j += i) {
                if (cnt[j] == 0) continue;
                sum[i] += cnt[j];
                d[i] += cnt[i] * cnt[j];
            }
            // cout << i << endl;
            // cout << d[i] << "*" << sum[i] << endl;

            sum[i] = sum[i] * (sum[i] - 1) / 2;
            sum[i] += cnt[i] * (cnt[i] - 1) / 2;
            for (int j = i + i; j <= n; j += i)
                sum[i] -= sum[j];
            sum[i] += d[i];
            ans -= sum[i];
            cout << i << " " << sum[i] << endl;
            // cout << i << " " << tot << endl;
            // cout << ans << endl;
        }

        cout << ans << '\n';
    }
    return 0;
}
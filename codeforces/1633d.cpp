#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;

    vector < int > dp(1e3 + 1, 1e9);
    dp[1] = 0;
    for (int i = 1; i < 1000; i++) {
        for (int j = 1; j <= i; j++) {
            int nxt = i + i / j;
            if (nxt > 1e3) continue;
            dp[nxt] = min(dp[nxt], dp[i] + 1);
        }
    }

    while (T--) {
        int n, k;
        cin >> n >> k;
        vector < int > a(n), b(n), c(n);
        for (int i = 0; i < n; i++)
            a[i] = 1;
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i < n; i++)
            cin >> c[i];

        vector < int > cnt(n);
        for (int i = 0; i < n; i++) 
            cnt[i] = dp[b[i]];

        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += cnt[i];

        if (sum <= k) {
            long long ans = 0;
            for (int i = 0; i < n; i++)
                ans += c[i];
            cout << ans << '\n';
            continue;
        }

        vector < vector < long long > > f(n + 1, vector < long long > (k + 1, 0));

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (i == 0) f[i][j] = 0;
                else if (j - cnt[i - 1] >= 0) {
                    // cout << i << " " << j << " " << cnt[i - 1] << " " << c[i - 1] << " " << f[i - 1][j - cnt[i - 1]] << " " << f[i - 1][j] << endl;
                    f[i][j] = max(f[i - 1][j], f[i - 1][j - cnt[i - 1]] + c[i - 1]);
                } else f[i][j] = f[i - 1][j];
            }
        }

        // for (int i = 0; i <= n; i++) {
        //     for (int j = 0; j <= k; j++)
        //         cout << f[i][j] << " ";
        //     cout << endl;
        // }
        cout << f[n][k] << '\n';
    }
    return 0;
}
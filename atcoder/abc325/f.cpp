#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n;
        cin >> n;
        vector < long long > d(n);
        for (int i = 0; i < n; i++) cin >> d[i];

        vector < long long > l(2), c(2), k(2);
        for (int i = 0; i < 2; i++) cin >> l[i] >> c[i] >> k[i];

        vector < vector < long long > > f(n + 1, vector < long long > (k[0] + 1, INF));
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j1 = 0; j1 <= k[0]; j1++) {
                if (f[i - 1][j1] == INF) continue;
                for (int j2 = j1; j2 <= k[0]; j2++) {
                    long long cost = f[i - 1][j1];

                    long long num = (cost - c[0] * j1) / c[1];

                    long long remain = max(0ll, d[i - 1] - l[0] * (j2 - j1));
                    long long add = remain / l[1] + ((remain % l[1]) > 0);
                    // if (i == 3 && j2 == k[0]) cout << "*" << j1 << " " << remain << " " << add << " " << f[i - 1][j1] << endl;
                    if (add + num > k[1]) continue;
                    f[i][j2] = min(f[i][j2], f[i - 1][j1] + c[0] * (j2 - j1) + c[1] * add);
                    // if (i == 2) cout << i << " " << j1 << " " << j2 << " " << add << " " << f[i][j2] << endl;
                }
            }
        }

        // for (int i = 1; i <= n; i++) {
        //     for (int j = 0; j <= k[0]; j++) {
        //         cout << f[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        long long ans = INF;
        for (int i = 0; i <= k[0]; i++) ans = min(ans, f[n][i]);

        if (ans == INF) cout << "-1\n";
        else cout << ans << '\n';
    }
    return 0;
}
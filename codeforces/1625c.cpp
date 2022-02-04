#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 10;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, l, k1;
    cin >> n >> l >> k1;
    vector < int > a(n + 1), d(n + 1);
    // d[0] = 0;
    for (int i = 0; i < n; i++)
        cin >> d[i];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector < vector < int > > f(n + 1, vector < int > (k1 + 1, INF));
    d[n] = l;
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        f[i][0] = f[i - 1][0] + a[i - 1] * (d[i] - d[i - 1]);
        for (int k = 1; k <= min(i, k1); k++) {
            int sum = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (i - j - 1 > k) break;
                sum += d[j + 1] - d[j];
                f[i][k] = min(f[i][k], f[j][k - (i - j - 1)] + a[j] * sum);
            }
        }
    }

    int ans = INF;
    for (int i = 0; i <= k1; i++) {
        ans = min(ans, f[n][i]);
        // cout << f[n][i] << endl;
    }
    cout << ans << '\n';
    return 0;
}
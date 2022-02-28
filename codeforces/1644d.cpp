#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, k, q;
        cin >> n >> m >> k >> q;
        vector < int > x(q), y(q);
        for (int i = 0; i < q; i++)
            cin >> x[i] >> y[i];
        set < int > sx, sy;
        int ans = 1;
        for (int i = q - 1; i >= 0; i--) {
            bool ok = false;
            if (!sx.count(x[i])) {
                sx.insert(x[i]);
                ok = true;
            }

            if (!sy.count(y[i])) {
                sy.insert(y[i]);
                ok = true;
            }

            if (ok) ans = (1ll * ans * k) % MOD;
            if (sx.size() == n || sy.size() == m) break;
        }

        cout << ans << '\n';
    }
    return 0;
}
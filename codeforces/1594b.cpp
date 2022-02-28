#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        int res = 0, cur = 1;
        for (int i = 0; i < 30; i++) {
            if ((k >> i) & 1)
                res = (1ll * res + cur) % MOD;
            cur = (1ll * cur * n) % MOD;
        }
        cout << res << '\n';
    }
    return 0;
}
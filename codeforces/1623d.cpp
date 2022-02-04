#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int calcPow(int a, int n) {
    int ans = 1;
    while (n > 0) {
        if (n & 1) ans = (1ll * ans * a) % MOD;
        a = (1ll * a * a) % MOD;
        n /= 2;
    }
    return ans;
}

int calc(int x, int y) {
    return 1ll * x * calcPow(y, MOD - 2) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, rb, cb, rd, cd, p;
        cin >> n >> m >> rb >> cb >> rd >> cd >> p;
        p = calc(100 - p, 100);

        int dr = -1, dc = -1;
        int u = 0, v = 1;
        for (int i = 0; i < 4 * (n - 1) * (m - 1); i++) {
            if (rb + dr < 1 || rb + dr > n) dr = -dr;
            if (cb + dc < 1 || cb + dc > m) dc = -dc;
            rb += dr;
            cb += dc;
            u += 1;
            u %= MOD;
            if (rb == rd || cb == cd) {
                u = (1ll * u * p) % MOD;
                v = (1ll * v * p) % MOD;
            }
        }

        cout << calc(u, (1 - v + MOD) % MOD) << '\n';
    }
    return 0;
}
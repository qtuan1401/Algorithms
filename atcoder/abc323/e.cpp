#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int calcPow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) 
            res = 1ll * res * a % MOD;
        
        a = 1ll * a * a % MOD;
        n /= 2;
    }

    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, x;
        cin >> n >> x;
        vector < int > t(n);
        vector < int > f(x + 1, 0);
        f[0] = 1;
        for (int i = 0; i < n; i++) {
            cin >> t[i];
        }

        int prob = calcPow(n, MOD - 2);
        for (int i = 1; i <= x; i++) {
            for (int j = 0; j < n; j++) {
                if (i - t[j] < 0) continue;
                f[i] += 1ll * prob * f[i - t[j]] % MOD;
                f[i] %= MOD;
            }
        }
        
        int ans = 0;
        for (int i = x; i >= 0; i--) {
            if (i + t[0] > x) {
                ans += 1ll * prob * f[i] % MOD;
                ans %= MOD;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
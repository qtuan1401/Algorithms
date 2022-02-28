#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int calc(int n, int x) {
    if (n == 0) return 0;
    int ans = 1;
    for (int i = 0; i < n; i++)
        ans = (1ll * ans * x) % MOD;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, x;
    cin >> n >> x;
    vector < vector < int > > nck(n + 1, vector < int > (n + 1, 0));
    for (int i = 0; i <= n; i++) {
        nck[i][0] = nck[i][i] = 1;
        for (int j = 1; j < i; j++) 
            nck[i][j] = (nck[i - 1][j] + nck[i - 1][j - 1]) % MOD;
    }

    vector < vector < int > > f(n + 1, vector < int > (x + 1, 0));
    f[n][0] = 1;
    for (int i = n; i > 1; i--) {
        for (int j = 0; j < x; j++) {
            if (!f[i][j]) continue;
            int pw = 1, nj = min(x, j + i - 1);
            for (int k = i; k >= 0; k--) {
                f[k][nj] += 1ll * f[i][j] * ((1ll * nck[i][k] * pw) % MOD) % MOD;
                f[k][nj] %= MOD;
                pw = (1ll * pw * (nj - j)) % MOD;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i <= x; i++) {
        ans += f[0][i];
        ans %= MOD;
    }

    cout << ans << '\n';
    return 0;
}
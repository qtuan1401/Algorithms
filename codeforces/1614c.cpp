#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int getBit(int x, int i) {
    return (x >> i) & 1;
}

int flipBit(int x, int i) {
    return x ^ (1 << i);
}

long long calc(long long a, int n) {
    long long res = 1;
    if (n == 0)
        return 1;
    while (n > 0) {
        if (n & 1)
            res = (res * a) % MOD;
        n >>= 1;
        a = (a * a) % MOD;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector < int > sum[2][31];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 31; j++) {
                sum[i][j].resize(n + 1);
                for (int k = 0; k < n; k++)
                    sum[i][j][k] = 0;
            }
        }
        for (int i = 0; i < m; i++) {
            int l, r, x;
            cin >> l >> r >> x;
            l--; r--;
            for (int j = 0; j < 31; j++) {
                int pos = getBit(x, j);
                sum[pos][j][l]++;
                sum[pos][j][r + 1]--;
            }
        }
        // cout << sum[2][0][0] << " " << sum[0][0][1] << endl;
        for (int j = 0; j < 31; j++) {
            for (int i = 0; i < n; i++) {
                if (i > 0) {
                    sum[0][j][i] += sum[0][j][i - 1];
                    sum[1][j][i] += sum[1][j][i - 1];
                }
            }
        }
        // generate array
        vector < int > a(n);
        for (int i = 0; i < n; i++) {
            a[i] = 0;
            for (int j = 0; j < 31; j++) {
                if (i == 0) {
                    if (sum[0][j][i] == 0 && sum[1][j][i] > 0) {
                        // cout << j << endl;
                        a[i] = flipBit(a[i], j);
                    }
                } else {
                    if (sum[0][j][i] == 0 && sum[1][j][i] > 0) {
                        // cout << "*" << j << endl;
                        a[i] = flipBit(a[i], j);
                    }
                }
            }
            // cout << endl;
        }
        long long res = 0;
        for (int j = 0; j < 31; j++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += getBit(a[i], j) == 1;
            }
            if (cnt > 0)
                res += (1ll << j) * ((1ll * calc(2, cnt - 1) * calc(2, n - cnt)) % MOD) % MOD;
            res %= MOD;
        }
        cout << res << '\n';
    }
    return 0;
}
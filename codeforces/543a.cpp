#include <bits/stdc++.h>

using namespace std;

int n, m, b, MOD;
int a[505], f[2][505][505];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> b >> MOD;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int res = 0;
    f[1][0][0] = 1;
    for(int i = 0; i < n; i++) {
        int id = i & 1;
        for(int j = 0; j <= m; j++)
            for(int k = 0; k <= b; k++) {
                f[id][j][k] = f[id ^ 1][j][k];
                if (j > 0 && k >= a[i]) {
                    f[id][j][k] += f[id][j - 1][k - a[i]];
                    f[id][j][k] %= MOD;
                }
            }
    }
    for(int i = 0; i <= b; i++)
        res = (res + f[(n - 1) & 1][m][i]) % MOD;
    cout << res;
    return 0;
}
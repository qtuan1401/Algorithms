#include <bits/stdc++.h>

using namespace std;

const int lim = 893;
const int MXN = 2e5 + 10;
const int MOD = 1e9 + 7;

int f[5][MXN];
int r, g;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> r >> g;
    f[0][0] = 1;
    int ans = 0;
    for(int i = 1; i <= lim; i++) {
        int id = i % 2;
        int sum = i * (i + 1) / 2;
        int res = 0;
        for(int j = r; j >= 0; j--) {
            if (sum - j <= g) {
                f[id][j] = f[id ^ 1][j];
                if (j - i >= 0)
                    f[id][j] = (f[id][j] + f[id ^ 1][j - i]) % MOD;
                res = (res + f[id][j]) % MOD;
            }
        }
        if (res > 0)
            ans = res;
        for(int j = 0; j <= r; j++)
            f[id ^ 1][j] = 0;
    }
    cout << ans;
    return 0;
}

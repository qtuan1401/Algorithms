#include <bits/stdc++.h>

using namespace std;

const long long MXN = 1e3 + 10;
const long long MXC = 1e4 + 10;

typedef pair < long long, long long > II;

long long f[MXN][MXC];
long long c[MXN], cost[MXN];
long long w, n, b, sum, x;


int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> w >> b >> x;
    for(long long i = 0; i < n; i++)
        cin >> c[i], sum += c[i];
    
    for(long long i = 0; i < n; i++)
        for(long long j = 0; j <= sum; j++)
            f[i][j] = -1;

    for(long long i = 0; i < n; i++)
        cin >> cost[i];

    f[0][0] = w;
    for(long long i = 1; i <= c[0]; i++)
        if (f[0][i - 1] >= cost[0])
            f[0][i] = min(w + i * b, f[0][i - 1] - cost[0]);
    
    for(long long i = 1; i < n; i++) {
        for(long long j = 0; j <= sum; j++) {
            for(long long k = 0; k <= min(j, c[i]); k++) {
                if (f[i - 1][j - k] == -1)
                    continue;
                long long mana = min(1ll * w + (j - k) * b, f[i - 1][j - k] + x);
                if (mana >= cost[i] * k) {
                    f[i][j] = max(f[i][j], min(w + 1ll * j * b, mana - cost[i] * k));
                }
            }
        }
    }

    long long res = 0;
    for(long long i = 0; i < n; i++)
        for(long long j = 0; j <= sum; j++) {
            //if (f[i][j] != -1)
            //    cout << i << " " << j << " " << f[i][j] << endl;
            //cout << i << " " << j << " " << f[i][j].first << " " << f[i][j].second << endl;
            if (f[i][j] >= 0)
                res = max(res, j);
        }
    cout << res;
    return 0;
}
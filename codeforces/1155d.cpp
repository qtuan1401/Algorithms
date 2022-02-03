#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 10;

long long f[MAXN][5], a[MAXN];
int n, x;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> x;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    f[0][0] = max(0ll, a[0]);
    f[0][1] = max(0ll, a[0] * x);
    f[0][2] = max(0ll, a[0] * x);
    for(int i = 1; i <= n; i++) {
        f[i][0] = max(0ll, f[i - 1][0] + a[i]);
        f[i][1] = max(0ll, max(f[i - 1][0], f[i - 1][1]) + a[i] * x);
        f[i][2] = max(0ll, max(f[i - 1][1], f[i - 1][2]) + a[i]);
    }
    long long res = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= 2; j++)
            res = max(res, f[i][j]);
    }
    cout << res;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int MXN = 2e7 + 10;

int n, x, y;
long long f[MXN];

int main() {
    //freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> x >> y;
    for(int i = 1; i <= n; i++)
        f[i] = 1e18;
    f[1] = x;
    for(int i = 1; i <= n; i++) {
        f[i + 1] = min(f[i + 1], f[i] + x);
        f[i * 2] = min(f[i * 2], f[i] + y);
        f[i * 2 - 1] = min(f[i * 2 - 1], f[i] + x + y);
    }
    cout << f[n];
    return 0;
}
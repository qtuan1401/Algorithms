#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        vector < int > a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector < vector < long long > > f(n + 1, vector < long long > (n + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                f[i][j] = max(f[i][j], f[i - 1][j] + a[i - 1]);
                if (j > 0) f[i][j] = max(f[i][j], f[i - 1][j - 1] + a[i - 1] + x);
            }
        }

        for (int k = 0; k <= n; k++) {
            long long mx = 0;
            for (int i = 1; i <= n; i++)
                mx = max(mx, f[i][k]);
            cout << mx << " ";
        }
        cout << '\n';
    }
    return 0;
}
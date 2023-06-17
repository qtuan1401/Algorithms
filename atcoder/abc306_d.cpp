#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e15;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n;
        cin >> n;
        vector < vector < long long > > f(n + 1, vector < long long > (2, -INF));
        f[0][0] = 0;
        for (int i = 0; i < n; i++) {
            long long x, y;
            cin >> x >> y;
            f[i + 1][0] = f[i][0];
            f[i + 1][1] = f[i][1];
            if (x == 0) {
                f[i + 1][0] = max(f[i + 1][0], max(f[i][0], f[i][1]) + y);
            } else {
                f[i + 1][1] = max(f[i + 1][1], f[i][0] + y);
            }
        }

        cout << max(0ll, max(f[n][0], f[n][1]));
    }
    return 0;
}
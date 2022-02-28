#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e15;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < int > a(n), b(n);
        long long res = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i], res += a[i] * a[i] * (n - 1);
        for (int i = 0; i < n; i++)
            cin >> b[i], res += b[i] * b[i] * (n - 1);

        vector < vector < long long > > f(n, vector < long long > (10001, INF));
        // cout << res << endl;

        f[0][a[0]] = f[0][b[0]] = 0;
        int tot = a[0] + b[0];
        for (int i = 1; i < n; i++) {
            for (int sum = 1; sum <= 10000; sum++) {
                if (sum - a[i] >= 0)
                    f[i][sum] = min(f[i][sum], f[i - 1][sum - a[i]] + 2 * a[i] * (sum - a[i]) + 2 * b[i] * (tot - sum + a[i]));
                if (sum - b[i] >= 0)
                    f[i][sum] = min(f[i][sum], f[i - 1][sum - b[i]] + 2 * b[i] * (sum - b[i]) + 2 * a[i] * (tot - sum + b[i]));
            }
            tot += a[i] + b[i];
        }

//        if (n > 1) cout << f[1][2] << endl;

        long long sum = INF;
        for (int i = 0; i <= 10000; i++)
            sum = min(sum, f[n - 1][i]);
        cout << res + sum << '\n';
    }
    return 0;
}
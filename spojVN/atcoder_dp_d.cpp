#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, mw;
    cin >> n >> mw;
    vector < int > w(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    vector < long long > f[n];
    for (int i = 0; i < n; i++)
        f[i].resize(mw + 1);
    if (n == 1) {
        cout << v[0] << '\n';
        return 0;
    }
    f[0][w[0]] = v[0];
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= mw; j++) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (j - w[i] >= 0)
                f[i][j] = max(f[i][j], f[i - 1][j - w[i]] + v[i]);
        }
    }

    cout << f[n - 1][mw];
    return 0;
}
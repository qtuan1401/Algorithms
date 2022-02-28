#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < vector < int > > a(n + 1, vector < int > (n));
        for (int i = 0; i < n; i++)
            cin >> a[0][i];

        for (int i = 1; i <= n; i++) {
            vector < int > cnt(n + 1, 0);
            for (int j = 0; j < n; j++)
                cnt[a[i - 1][j]]++;
            for (int j = 0; j < n; j++)
                a[i][j] = cnt[a[i - 1][j]];
        }

        int q;
        cin >> q;
        while (q--) {
            int x, k;
            cin >> x >> k;
            x--;
            if (k == 0) cout << a[0][x] << '\n';
            else {
                k = min(k, n);
                cout << a[k][x] << '\n';
            }
        }
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        s = "#" + s;
        t = "#" + t;

        vector < int > sums(n + 1, 0), sumt(n + 1, 0);
        sums[0] = sumt[0] = 0;
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + (s[i] == '1');
            sumt[i] = sumt[i - 1] + (t[i] == '1');
        }

        vector < vector < long long  > > f(n + 1, vector < long long > (n + 1, 1e18));
        f[0][0] = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (j > 0)
                    f[i][j] = min(f[i][j], f[i][j - 1] + 1ll * (t[j] == '0') * (sums[i] + sumt[j - 1]));
                if (i > 0)
                    f[i][j] = min(f[i][j], f[i - 1][j] + 1ll * (s[i] == '0') * (sums[i - 1] + sumt[j]));
            }
        }
        cout << f[n][n] << '\n';
    }
    return 0;
}
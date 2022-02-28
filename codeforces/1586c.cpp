#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    vector < string > s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    vector < vector < int > > f(n, vector < int > (m));
    vector < int > isExit(m), cnt(m);
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            if (s[i][j - 1] == 'X' && s[i - 1][j] == 'X')
                isExit[j] = 1;
    // for (int j = 0; j < m; j++) {
    //     for (int i = 0; i < n; i++) {
    //         if (j == 0) {
    //             f[i][j] = s[i][j] == '.';
    //             continue;
    //         }

    //         if (s[i][j] == '.') {
    //             f[i][j] = s[i][j - 1] == '.';
    //             if (i == 0) f[i][j] |= s[i][j] == '.';
    //             if (i > 0) f[i][j] |= f[i - 1][j];
    //             if (f[i][j] == 0)
    //                 isExit[j] = 0;
    //         }
    //         cnt[j] += s[i][j] == 'X';
    //     }
    // }

    for (int j = 1; j < m; j++)
        isExit[j] += isExit[j - 1];

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        if (cnt[l] == n) {
            cout << "NO\n";
            continue;
        }

        if (isExit[r] - isExit[l] > 0) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
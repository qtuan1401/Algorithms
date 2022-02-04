#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, r, c;
        cin >> n >> m >> r >> c;
        r--; c--;
        vector < string > s(n);
        for (int i = 0; i < n; i++)
            cin >> s[i];
        if (s[r][c] == 'B') {
            cout << 0 << '\n';
            continue;
        }
        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (s[i][c] == 'B') {
                cout << "1\n";
                ok = true;
                break;
            }
        }
        if (ok) continue;
        for (int i = 0; i < m; i++) {
            if (s[r][i] == 'B') {
                cout << "1\n";
                ok = true;
                break;
            }
        }
        if (ok) continue;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                if (s[i][j] == 'B') {
                    cout << "2\n";
                    ok = true;
                    break;
                }
            if (ok) break;
        }
        if (ok) continue;
        cout << "-1\n";
    }
    return 0;
}
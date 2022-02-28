#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s[2];
        cin >> n;
        cin >> s[0] >> s[1];
        bool ok = true;
        for (int i = 0; i < n; i++)
            if (s[0][i] == '1' && s[1][i] == '1')
                ok = false;
        ok &= s[1][n - 1] == '0';
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
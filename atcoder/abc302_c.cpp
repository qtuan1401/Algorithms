#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, m;
        cin >> n >> m;
        vector < string > s(n);
        for (int i = 0; i < n; i++) cin >> s[i];

        vector < int > id(n);
        for (int i = 0; i < n; i++) id[i] = i;
        bool found = false;
        do {
            bool ok = true;
            for (int i = 0; i < n - 1; i++) {
                int diff = 0;
                for (int j = 0; j < m; j++) {
                    diff += s[id[i]][j] != s[id[i + 1]][j];
                }

                if (diff != 1) {
                    ok = false;
                    break;
                }
            }

            if (ok == true) {
                found = true;
                break;
            }
        } while (next_permutation(id.begin(), id.end()));

        if (found) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
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

        vector < vector < int > > val(2);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            val[x % 2].push_back(x);
        }

        bool ok = true;
        for (int id = 0; id < 2; id++) {
            if (!ok) break;
            for (int i = 1; i < val[id].size(); i++) {
                if (val[id][i] < val[id][i - 1]) {
                    ok = false;
                    break;
                }
            }
        }

        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
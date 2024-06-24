#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        bool ok = true;
        int n;
        cin >> n;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (i > 0) {
                if (cur != x) {
                    ok = false;
                }
            }
            cur = x;
        }
        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
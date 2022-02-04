#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int l, r, k;
        cin >> l >> r >> k;
        if (l == r && l == 1) {
            cout << "NO\n";
            continue;
        }
        int diff = r - l + 1;
        if (k == 0) {
            if (diff >= 2)
                cout << "NO\n";
            else cout << "YES\n";
            continue;
        }
        if (k * 2 >= diff) {
            cout << "YES\n";
        } else if (k * 2 <= diff - 2) {
            cout << "NO\n";
        } else {
            if (r % 2 == 0) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    
    return 0;
}
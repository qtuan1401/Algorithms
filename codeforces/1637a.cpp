#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < int > a(n), mn(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        mn[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
            mn[i] = min(mn[i + 1], a[i]);
        int mx = 0;
        bool ok = false;
        for (int i = 0; i < n - 1; i++) {
            mx = max(mx, a[i]);
            if (mx > mn[i + 1]) ok = true;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n, m;
        cin >> n >> m;
        // cout << n << " " << m << endl;
        vector < int > a(n), b(n);
        a[0] = 1;
        for (int i = 1; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int ans = -1;
        for (int i = 0, j = 0; i < n && j < n; i++, j++) {
            while (j < n && a[i] >= b[j]) j++;
            if (j < n) ans = i;
            // cout << i << " " << j << endl;
        }

        cout << n - ans - 1 << '\n';
    }
    return 0;
}
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
        int n, k;
        cin >> n >> k;
        vector < int > a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (k != 4) {
            int ans = 10;
            for (int i = 0; i < n; i++) {
                ans = min(ans, (k * 2 - a[i] % k) % k);
            }
            cout << ans << '\n';
        } else {
            int cnt2 = 0, cnt4 = 0;
            for (int i = 0; i < n; i++) {
                cnt2 += a[i] % 2 == 0;
                cnt4 += a[i] % 4 == 0;
            }
            if (cnt2 >= 2 || cnt4 > 0) {
                cout << "0\n";
                continue;
            }
            int ans = 2;
            for (int i = 0; i < n; i++) {
                if (a[i] % 2 == 0 || (a[i] + 1) % 4 == 0) {
                    ans = 1;
                    break;
                }
            } 
            cout << ans << '\n';
        }
    }
    return 0;
}
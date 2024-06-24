#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    vector < long long > pp2(40, 0);
    pp2[0] = 1;
    for (int i = 1; i < 40; i++) {
        pp2[i] = pp2[i - 1] * 2;
    }
    while (tests--) {
        int n;
        cin >> n;
        vector < long long > a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        long long ans = 0;
        long long pp = 0;
        for (int i = 1; i < n; i++) {
            for (int j = max(0ll, pp - 31); j <= pp + 31; j++) {
                if (j < pp) {
                    if (a[i - 1] * pp2[pp - j] <= a[i]) {
                        pp = j;
                        ans += j;
                        break;
                    }
                } else {
                    if (a[i - 1] <= a[i] * pp2[j - pp]) {
                        pp = j;
                        ans += j;
                        break;
                    }
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
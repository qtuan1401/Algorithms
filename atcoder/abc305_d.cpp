#include <bits/stdc++.h>

using namespace std;

const int dx[] = {0, 1, -1, 0, -1, 0, 0, 1};
const int dy[] = {1, 0, 0, 1, 0, -1, -1, 0};

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n;
        cin >> n;
        vector < long long > a(n), sum(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i < n; i += 2) {
            sum[i] = a[i + 1] - a[i];
        }
        
        for (int i = 1; i < n; i++) sum[i] += sum[i - 1];
        int q;
        cin >> q;
        while (q--) {
            long long l, r;
            cin >> l >> r;
            int pl = lower_bound(a.begin(), a.end(), l) - a.begin();
            int pr = upper_bound(a.begin(), a.end(), r) - a.begin() - 1;
            if (pl > pr) {
                if (pl % 2 == 0) cout << r - l << '\n';
                else cout << 0 << '\n';
                continue;
            }
            long long ans = 0;
            if (pl > 0 && pl % 2 == 0) ans += a[pl] - l;
            if (pr & 1) {
                ans += r - a[pr];
                pr--;
            }
            if (pl <= pr) {
                ans += sum[pr];
                if (pl > 0) ans -= sum[pl - 1];
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
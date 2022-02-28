#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < double > a(n);
        double sum = 0;
        for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
        double mean = sum / n;

        sum = 0;
        map < double, int > mp;
        for (int i = 0; i < n; i++) {
            a[i] -= mean;
            mp[a[i]]++;
        }

        long long res = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] >= 0) continue;
            res += mp[-a[i]];
        }

        res += 1ll * mp[0] * (mp[0] - 1) / 2;
        cout << res << '\n';
    }
    return 0;
}
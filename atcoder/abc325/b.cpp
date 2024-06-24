#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n;
        cin >> n;
        vector < long long > sum(49, 0), real(24, 0);
        for (int i = 0; i < n; i++) {
                int w, x;
                cin >> w >> x;
                sum[9 + x] += w;
                sum[18 + x] -= w;
        }
        long long ans = sum[0];
        real[0] = sum[0];
        for (int i = 1; i <= 48; i++) {
            sum[i] += sum[i - 1];
            real[i % 24] += sum[i];
        }

        for (int i = 0; i < 24; i++) ans = max(ans, real[i]);

        cout << ans << '\n';
    }
    return 0;
}
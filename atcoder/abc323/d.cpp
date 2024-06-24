#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int  n;
        cin >> n;
        set < long long > sz;
        map < long long, long long > sum;
        for (int i = 0; i < n; i++) {
            long long s, c;
            cin >> s >> c;
            sz.insert(s);
            sum[s] = c;
        }

        long long ans = 0;
        while (sz.size()) {
            long long val = *sz.begin();
            sz.erase(sz.begin());
            long long c = sum[val];
            ans += c % 2;
            if (c / 2 > 0) {
                sum[val * 2] += c / 2;
                sz.insert(val * 2);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
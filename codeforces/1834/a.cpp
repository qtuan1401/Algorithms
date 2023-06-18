#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        vector < int > cnt(2, 0);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == -1) cnt[0]++;
            else cnt[1]++;
        }

        int ans = 0;
        while (cnt[1] < cnt[0] || cnt[0] % 2 != 0) {
            ans++;
            cnt[1]++;
            cnt[0]--;
        }

        cout << ans << '\n';
    }
    return 0;
}
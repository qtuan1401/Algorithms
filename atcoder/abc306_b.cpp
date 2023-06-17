#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        unsigned long long ans = 0;
        for (int i = 0; i < 64; i++) {
            int x;
            cin >> x;
            ans += (1ull << i) * x;
        }
        cout << ans << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e15;

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
        vector < int > a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }
        vector < long long > mx(n, -INF);
        mx[a[0]] = 0;
        long long ans = 0;
        for (int i = 1; i < n; i++) {
            long long cur = i + 1 + mx[a[i]];
            mx[a[i]] = max(mx[a[i]], ans - i);
            ans = max(ans, cur);
        }

        cout << ans << '\n';
    }
    return 0;
}
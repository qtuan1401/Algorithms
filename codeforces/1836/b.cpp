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
        long long n, k, g;
        cin >> n >> k >> g;
        long long r = (g - 1) / 2;
        long long remain = r * n;
        if (remain >= k * g) {
            cout << k * g << '\n';
            continue;
        }       

        remain = k * g - remain;
        long long ans = r * (n - 1);
        remain = r + remain % g;
        remain %= g;

        if (remain <= r) ans += remain;
        else ans -= g - remain;

        cout << ans << endl;
    }
    return 0;
}
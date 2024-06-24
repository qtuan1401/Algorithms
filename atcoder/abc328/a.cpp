#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, x;
        cin >> n >> x;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            if (val <= x) ans += val;
        }
        cout << ans << '\n';
    }
    return 0;
}
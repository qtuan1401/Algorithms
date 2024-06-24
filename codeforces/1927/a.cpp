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
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        string s;
        cin >> n >> s;
        int mn = n, mx = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'B') {
                mn = min(mn, i);
                mx = max(mx, i);
            }
        }

        if (mn == n) cout <<  "0\n";
        else cout << mx - mn + 1 << '\n';
    }
    return 0;
}
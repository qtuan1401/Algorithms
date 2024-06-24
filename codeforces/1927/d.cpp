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
        cin >> n;
        vector < int > a(n), diff(n, -1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = n - 2; i >= 0; i--) {
            if (a[i] != a[i + 1]) {
                diff[i] = i + 1;
            } else {
                diff[i] = diff[i + 1];
            }
        }

        int q;
        cin >> q;
        while (q--) {
            int pl, pr;
            cin >> pl >> pr;
            pl--; pr--;
            int pos = diff[pl];
            if (pos > pr || pos == -1) {
                cout << "-1 -1\n";
            } else {
                cout << pl + 1 << " " << pos + 1 << '\n';
            }
        }

    }
    return 0;
}
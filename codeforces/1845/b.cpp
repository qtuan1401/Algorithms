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
        int xa, ya, xb, yb, xc, yc;
        cin >> xa >> ya >> xb >> yb >> xc >> yc;
        int diffx = 0, diffy = 0;
        if (1ll * (xa - xb) * (xa - xc) >= 0) {
            diffx = min(abs(xa - xb), abs(xa - xc));
        }

        if (1ll * (ya - yb) * (ya - yc) >= 0) {
            diffy = min(abs(ya - yb), abs(ya - yc));
        }

        cout << diffx + diffy + 1 << '\n';
    }
    return 0;
}
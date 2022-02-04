#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        int na = b - (c - b);
        if (na >= a && na % a == 0) {
            cout << "YES\n";
            // cout << na << " " << b << " " << c << endl;
            continue;
        }
        if ((c - a) % 2 == 0) {
            int diff = (c - a) / 2;
            int nb = c - diff;
            if (nb >= b && nb % b == 0) {
                cout << "YES\n";
                // cout << a << " " << nb << " " << c << endl;
                continue;
            }
        }
        int nc = b + b - a;
        if (nc >= c && nc % c == 0) {
            cout << "YES\n";
            // cout << a << " " << b << " " << nc << endl;
        } else cout << "NO\n";
    }
    return 0;
}
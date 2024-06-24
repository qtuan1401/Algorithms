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
        int n, k, x;
        cin >> n >> k >> x;
        if (k == n && x != k) {
            cout << "YES\n" << 1 << '\n' << n << '\n';
            continue;
        }

        if (x == 1) {
            if (n == 1 || n == 3 || k == 1 || (n % 2 == 1 && k == 2)) {
                cout << "NO\n";
                continue;
            } else {
                cout << "YES\n";
                if (n & 1) {
                    cout << 2 + (n - 5) / 2 << '\n';
                    cout << 2 << " " << 3 << '\n';
                } else {
                    cout << n / 2 << '\n';
                }
                for (int i = 1; i <= (n - (n & 1) * 5) / 2; i++) cout << 2 << " ";
                cout << '\n';
            }
        } else {
            if (n == 1) {
                cout << "NO\n";
                continue;
            }
            cout << "YES\n";
            cout << n << '\n';
            for (int i = 1; i <= n; i++) {
                cout << 1 << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}
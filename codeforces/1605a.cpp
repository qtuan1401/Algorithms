#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        int diff = abs(a1 + a3 - 2 * a2);
        if (diff % 3 == 0) cout << "0\n";
        else cout << "1\n";
    }
    return 0;
}
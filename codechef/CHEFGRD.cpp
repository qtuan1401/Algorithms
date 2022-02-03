#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, x, y;
        cin >> n >> x >> y;
        int s = (n + 1) / 2;
        int t1 = abs(s - x), t2 = abs(s - y);
        if ((t1 + t2) % 2 == 0)
            cout << 0;
        else cout << 1;
        cout << '\n';
    }
    return 0;
}
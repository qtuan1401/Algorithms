#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            res = max(res, x - i);

        }
        cout << res << '\n';
    }
    return 0;
}
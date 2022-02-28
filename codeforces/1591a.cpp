#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int pre = -1, res = 1;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (res == -1) continue;
            if (pre == 0 && x == 0) {
                res = -1;
                continue;
            }
            // cout << res << " " << x << endl;
            if (pre <= 0 && x == 1)
                res++;
            if (pre == 1 && x == 1) res += 5;
            pre = x;
        }
        cout << res << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        if (n == 1) {
            cout << "0\n";
            continue;
        }

        long long cur = 0;
        for (int i = 0; i < 31; i++) {
            cur ^= (1ll << i);
            if (cur > n) break;
        }
        // cout << cur << endl;
        long long res = 0;
        while (n > 0) {
            while (cur / 2 > n) cur /= 2;
            long long x = cur ^ n;
            if (x > n || x < 1) {
                n--;
            } else {
                res += (n - x + 1) * cur;
                n = x - 1;
            }
            
        }
        cout << res << '\n';
    }
    return 0;
}
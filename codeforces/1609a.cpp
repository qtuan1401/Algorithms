#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < long long > a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (n == 1) {
            cout << a[0] << '\n';
            continue;
        }
        sort(a.begin(), a.end());
        
        long long sum = 0, res = 0, mul = 1;
        for (int i = 0; i < n; i++) {
            // cout << a[i] << endl;
            while (a[i] % 2 == 0) {
                a[i] /= 2;
                mul *= 2;
            }
            sum += a[i];
        }

        // cout << sum << " " << mul << endl;
        for (int i = 0; i < n; i++)
            res = max(res, sum + a[i] * (mul - 1));
        cout << res << '\n';
    }
    return 0;
}
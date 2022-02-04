#include <bits/stdc++.h>

using namespace std;

int getBit(int x, int i) {
    return (x >> i) & 1;
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector < int > a(n), cnt(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
            cnt[a[i]]++;
        }
        int sum = 0, x = 0, y = n - 1, mn = n;
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && 2 * sum - n < k)
                sum += cnt[j++];
            j--;
            // cout << i << " " << j << " " << sum << endl;
            if (2 * sum - n >= k) {
                if (mn > j - i) {
                    mn = j - i;
                    x = i; y = j;
                }
            }
            j++;
            sum -= cnt[i];
        }
        cout << x + 1 << " " << y + 1 << '\n';
        int remain = k, diff = 0, l = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < x || a[i] > y)
                diff--;
            else diff++;
            // cout << i << " * " << diff << endl;
            if (diff >= 1 && remain > 1) {
                cout << l + 1 << " " << i + 1 << '\n';
                diff = 0;
                l = i + 1;
                remain--;
            }
        }
        cout << l + 1 << " " << n << '\n';
    }
    return 0;
}
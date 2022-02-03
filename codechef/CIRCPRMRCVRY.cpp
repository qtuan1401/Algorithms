#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector < int > a(n), pos;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 0) pos.push_back(i);
        }

        int cur = 0, mx = 0;
        vector < int > ans(n, 0);
        while (pos.size()) {
            vector < int > cnt(n);
            for (int i = 0; i < n; i++)
                cnt[i] = 0;
            for (int & i : pos) {
                for (int j = 0; j <= k; j++) {
                    int val = a[(i + j) % n];
                    if (val == 0)
                        cnt[(i + j) % n] = cnt[(i + j - 1 + 5 * n) % n] + 1;
                    else cnt[(i + j) % n] = cnt[(i + j - 1 + 5 * n) % n];
                }
            }

            // for (int i = 0; i < n; i++)
            //     cout << cnt[i] << " ";
            // cout << endl;

            for (int i = 0; i < n; i++)
                if (cnt[i] == pos.size() + 1) {
                    ok = false;
                    break;
                }

            for (int & i: pos) {
                if (cnt[i] == 1) cur = mx;
                ans[i] = cur + cnt[i];
                mx = max(mx, ans[i]);
            }

            for (int & i: pos) {
                for (int j = 0; j <= k; j++)
                    a[(i - j + n * 5) % n]--;
            }

            for (int & i: pos) {
                
            }

            pos.clear();
            for (int i = 0; i < n; i++)
                if (ans[i] == 0 && a[i] == 0) {
                    pos.push_back(i);
                }
            if (pos.size() == 0) {
                if (mx < n) ok = false;
                break;
            }
            // cout << mx << " " << pos.size() << endl;
            // for (int i = 0; i < n; i++)
            //     cout << a[i] << " ";
            // cout << endl;
        }
        if (ok) {
            for (int i = 0; i < n; i++)
                cout << ans[i] << " ";
            cout << '\n';
        } else cout << "-1\n";
    }
    return 0;
}
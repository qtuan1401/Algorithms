#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        int res = n + 1;
        for (int i = 0; i < n; i++) {
            int cnt[3] = {0, 0, 0};
            for (int j = i; j >= 0; j--) {
                if ((i - j + 1) > 7) break;
                cnt[s[j] - 'a']++;
                if (j == i) continue;
                // cout << i << " " << j << " " << cnt[0] << " " << cnt[1] << " " << cnt[2] << endl;
                if (cnt[0] > cnt[1] && cnt[0] > cnt[2]) {
                    res = min(res, i - j + 1);
                }
            }
        }

        if (res == n + 1) cout << "-1\n";
        else cout << res << '\n';
    }
    return 0;
}
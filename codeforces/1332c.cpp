#include <bits/stdc++.h>

using namespace std;

const int LIM = 2e5 + 10;

int cnt[LIM][30];

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k;
        cin >> s;
        for (int i = 0; i < k; i++)
            for (int j = 0; j < 26; j++)
                cnt[i][j] = 0;
        for (int i = 0; i < s.size(); i++)
            cnt[i % k][s[i] - 'a']++;
        int res = 0;
        for (int i = 0; i < k; i++) {
            int mx = 0, pos = 0;
            // cout << i << " " << n - i - 1 << " " << (n - i - 1) % k << endl;
            for (int j = 0; j < 26; j++) {
                if (mx < cnt[i][j]) {
                    pos = j;
                    mx = cnt[i][j];
                }
            }
            if (i != (n - i - 1) % k) {
                mx = 0;
                for (int j = 0; j < 26; j++) {
                    if (mx < cnt[i][j] + cnt[(n - i - 1) % k][j]) {
                        mx = cnt[i][j] + cnt[(n - i - 1) % k][j];
                        pos = j;
                    }
                }
            }
            res += n / k - cnt[i][pos];
        }
        cout << res << '\n';
    }
    return 0;
}
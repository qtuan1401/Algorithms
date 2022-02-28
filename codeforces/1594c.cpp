#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    // freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        char c;
        string s;
        cin >> n >> c >> s;
        int tot = 0;
        for (int i = 0; i < n; i++)
            tot += s[i] != c;
        if (tot == 0) {
            cout << "0\n";
            continue;
        }
        
        vector < int > ans;
        for (int i = 1; i <= n; i++) {
            if (ans.size()) break;
            if (s[i - 1] == c) {
                int cnt = 0;
                for (int j = i + i; j <= n; j += i)
                    cnt += s[j - 1] != c;
                if (cnt == 0) {
                    ans.push_back(i);
                    break;
                }
                // cout << i << " * " << cnt << endl;
            }
        }

        if (!ans.size()) {
            ans.push_back(n);
            ans.push_back(n - 1);
        }

        cout << ans.size() << '\n';
        for (int &val: ans) cout << val << " ";
        cout << '\n';
    }
    return 0;
}
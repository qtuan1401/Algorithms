#include <bits/stdc++.h>

using namespace std;

string s;

int change(char c) {
    int n = s.size();
    int l = 0, r = n - 1;
    int cnt = 0;
    while (l < r) {
        if (s[l] == s[r]) {
            l++;
            r--;
        } else {
            if (s[l] == c) l++, cnt++;
            else if (s[r] == c) r--, cnt++;
            else return n + 1;
        }
    }

    return cnt;
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n >> s;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != s[n - i - 1]) {
                res = min(change(s[i]), change(s[n - i - 1]));
                break;
            }
        }
        if (res == n + 1) cout << "-1\n";
        else cout << res << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int l = n - 1;
        long long ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (l < 0) {
                cout << "-1 ";
                continue;
            }
            l = min(l, i);
            if (s[i] == '1') {
                while (l >= 0 && s[l] == '1') l--;
            }

            if (l < 0) cout << "-1 ";
            else {
                swap(s[l], s[i]);
                ans += i - l;
                cout << ans << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}
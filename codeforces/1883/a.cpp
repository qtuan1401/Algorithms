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
        string s;
        cin >> s;
        int cur = 1;
        long long ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int num = s[i] - '0';
            if (num == 0) num = 10;
            ans += abs(num - cur);
            ans++;
            cur = num;
        }
        cout << ans << '\n';
    }
    return 0;
}
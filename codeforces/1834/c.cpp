#include <bits/stdc++.h>

using namespace std;

int calc(string s, string t) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans += s[i] != t[i];
    }
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        string s, t;
        cin >> n >> s >> t;

        int dist1 = calc(s, t);
        reverse(s.begin(), s.end());
        int dist2 = calc(s, t);

        dist1 = dist1 * 2 - dist1 % 2;
        if (dist2 == 0) {
            cout << min(dist1, 2) << '\n';
            continue;
        }

        dist2 = dist2 * 2 - (dist2 % 2 == 0);
        cout << min(dist1, dist2) << '\n';
    }
    return 0;
}
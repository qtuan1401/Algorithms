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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector < int > cnt(26);
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (k == 0) break;
            if (cnt[i] % 2 == 0) continue;
            k--;
            cnt[i]--;
        }
        
        bool ok = true;
        if (k == 0) {
            int tot = 0;
            for (auto & e : cnt) tot += e % 2;
            if (tot > 1) ok = false;
            else ok = true;
        } else {
            int sum = 0;
            for (auto & e : cnt) sum += e;
            if (sum >= k) ok = true;
            else ok = false;
        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
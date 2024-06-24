#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n;
        cin >> n;
        vector < pair < int, int > > cnt(n, {0, 0});
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            cnt[i].second = n - i;
            for (char & c : s)
                cnt[i].first += (c == 'o'); 

        }

        sort(cnt.begin(), cnt.end());
        reverse(cnt.begin(), cnt.end());

        for (auto & p : cnt) cout << n - p.second + 1 << " ";
    }
    return 0;
}
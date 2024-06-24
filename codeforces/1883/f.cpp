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
        vector < int > a(n), l(n), r(n);

        for (int i = 0; i < n; i++) cin >> a[i];

        map < int, int > mp;
        for (int i = 0; i < n; i++) {
            if (mp[a[i]] == 0) l[i] = 1;
            mp[a[i]]++;
        }
        
        mp.clear();
        for (int i = n - 1; i >= 0; i--) {
            if (mp[a[i]] == 0) r[i] = 1;
            mp[a[i]]++;
        }

        for (int i = 1; i < n; i++) l[i] += l[i - 1];

        long long ans = 0;
        for (int i = n - 1; i >= 1; i--) {
            if (r[i] == 1) {
                ans += l[i - 1];
            }
        }

        for (int i = 0; i < n; i++) {
            ans += mp[a[i]] == 1;
        }

        cout << ans << '\n';
    }
    return 0;
}
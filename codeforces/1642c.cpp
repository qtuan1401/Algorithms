#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        vector < long long > a(n);
        map < long long, int > mp;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }

        sort(a.begin(), a.end());

        int res = 0;
        for (int i = 0; i < n; i++) {
            // cout << a[i] << " " << mp[a[i]] << endl;
            if (mp[a[i]] == 0) continue;
            long long val = a[i] * x;
            if (mp[val]) {
                mp[val]--;
            } else res++;
            mp[a[i]]--;
        }
        cout << res << '\n';
    }
    return 0;
}
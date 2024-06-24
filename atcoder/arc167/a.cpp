#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, m;
        cin >> n >> m;
        vector < int > a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        long long ans = 0;
        for (int i = n - m; i < n; i++) {
            long long j = i - (n - m);
            long long val = a[i];
            if (j < n - m) {
                val += a[n - m - j - 1];
            }  
            ans += val * val;
        }

        cout << ans << '\n';
    }
    return 0;
}
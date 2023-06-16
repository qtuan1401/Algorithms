#include <bits/stdc++.h>

using namespace std;

typedef pair < long long, long long > PLL;

int bs(vector < PLL > & a, int l, int r, long long val) {
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid].first >= val) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, m;
        long long d;
        cin >> n >> m >> d;
        vector < PLL > a(n + m);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = 0;
        }

        for (int i = n; i < n + m; i++) {
            cin >> a[i].first;
            a[i].second = 1;
        }

        sort(a.begin(), a.end());

        int pre0 = -1, pre1 = -1;
        long long ans = -1;
        for (int i = 0; i < n + m; i++) {
            int pos = bs(a, 0, i - 1, a[i].first - d);
            if (pos >= 0) {
                if (a[i].second == 1 && pre0 >= pos) {
                    ans = max(ans, a[i].first + a[pre0].first);
                } else if (a[i].second == 0 && pre1 >= pos) {
                    ans = max(ans, a[i].first + a[pre1].first);
                }
            }

            if (a[i].second == 1) pre1 = i;
            else pre0 = i;
        }

        cout << ans << '\n';
    }
    return 0;
}
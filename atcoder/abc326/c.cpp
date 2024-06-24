#include <bits/stdc++.h>

#define vall(a) (a.begin(), a.end())

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

int bs(int l, int r, int target, vector < int > & a) {
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] >= target) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    return ans;
}

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
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        a.push_back(a[n - 1] + 1);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int pos = bs(0, n, a[i] + m, a);
            ans = max(ans, pos - i);
        }

        cout << ans << '\n';
    }
    return 0;
}
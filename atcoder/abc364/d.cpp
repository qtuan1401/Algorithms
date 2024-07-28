#include <bits/stdc++.h>

using namespace std;

template < class T >
void resetVec(vector < T > & a, int sz, T val) {
    a.clear();
    a.resize(sz, val);
}

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;

int sz;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, q;
        cin >> n >> q;
        int sz = sqrt(n) + 1;
        vector < int > a(n + 2);
        a[0] = -1e9;
        a[n + 1] = 1e9;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        for (int i = 0; i < q; i++) {
            int x, k;
            cin >> x >> k;
            int pos = lower_bound(a.begin(), a.end(), x) - a.begin();
            int l = pos, r = pos, cnt = 0;
            while (a[l] > x) l--;
            while (a[r] < x) r++;
            if (l == r) {
                if (l > 0) l--;
                else r++;
            }
            // cout << l << " " << r << endl;
            while (cnt + 2 * sz < k) {
                int ll = max(0, l - sz + 1);
                int rr = min(n + 1, r + sz - 1);
                if (x - a[ll] <= a[rr] - x) {
                    cnt += l - ll + 1;
                    l = ll - 1;
                } else {
                    cnt += rr - r + 1;
                    r = rr + 1;
                }
            }
            // cout << l << " " << r << " " << cnt << endl;
            int ans = 0;
            while (cnt < k) {
                if (x - a[l] <= a[r] - x) {
                    // cout << a[l] << " ";
                    ans = x - a[l];
                    l--;
                } else {
                    // cout << a[r] << " ";
                    ans = a[r] - x;
                    r++;
                }
                cnt++;
            }
            cout << ans << endl;
        }

        
    }
    return 0;
}
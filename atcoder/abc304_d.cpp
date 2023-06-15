#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > II;

vector < int > b;

int bs(int val) {
    int l = 0;
    int r = (int)b.size() - 1;
    int ans = 0;
    // cout << l << " " << r << " " << val << endl;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (b[mid] <= val) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    // cout << ans << endl;
    return ans;
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int w, h;
        cin >> w >> h;
        int n;
        cin >> n;
        vector < II > p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i].first >> p[i].second;
        }

        sort(p.begin(), p.end());

        int an, bn;
        
        cin >> an;
        vector < int > a(an + 1);
        a[an] = w;
        for (int i = 0; i < an; i++) cin >> a[i];
        cin >> bn;
        b.resize(bn + 2);
        b[0] = 0;  b[bn + 1] = h;
        for (int i = 1; i <= bn; i++) cin >> b[i];
        int mn = n, mx = 0, cur = 0;
        vector < int > sum(bn + 5, 0);
       
        for (int i = 0; i <= an; i++) {
            int l = cur;
            while (cur < n && p[cur].first <= a[i]) {
                int pos = bs(p[cur].second);
                sum[pos]++;
                cur++;
            }

            set < int > s;
            for (int i = l; i < cur; i++) {
                int pos = bs(p[i].second);
                s.insert(pos);
                mn = min(mn, sum[pos]);
                mx = max(mx, sum[pos]);
                // cout << p[i].first << " " << p[i].second << " " << pos << " " << sum[pos] << endl;
            }

            for (int i = l; i < cur; i++) {
                int pos = bs(p[i].second);
                sum[pos] = 0;
            }
            // cout << s.size() << " " << bn + 1 << endl;
            if (s.size() < bn + 1) mn = 0;
        }

        cout << mn << " " << mx << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int bsL(vector < int > & a, int val) {
    int l = 0, r = (int)a.size() - 1;
    int ans = r + 1; 
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] >= val) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    return ans;
}

int bsR(vector < int > & a, int val) {
    int l = 0, r = (int)a.size() - 1;
    int ans = -1; 
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] <= val) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }

    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n, m;
        cin >> n >> m;
        vector < int > loc, l(n), r(n);
        loc.push_back(1);
        loc.push_back(m);
        for (int i = 0; i < n; i++) {
            cin >> l[i] >> r[i];
            loc.push_back(l[i]);
            loc.push_back(r[i]);
        }

        sort(loc.begin(), loc.end());
        loc.erase(unique(loc.begin(), loc.end()), loc.end());

        int len = loc.size();
        vector < int > sum(len + 5);
        vector < vector < int > > seg(2);

        for (int i = 0; i < n; i++) {
            int pl = lower_bound(loc.begin(), loc.end(), l[i]) - loc.begin();
            int pr = lower_bound(loc.begin(), loc.end(), r[i]) - loc.begin();

            sum[pl] += 1;
            sum[pr + 1] -= 1;

            if (l[i] == 1) {
                seg[0].push_back(r[i]);
            } 

            if (r[i] == m) {
                seg[1].push_back(l[i]);
            }
        }

        for (int i = 0; i < 2; i++)
            sort(seg[i].begin(), seg[i].end());

        for (int i = 1; i < len; i++) sum[i] += sum[i - 1];
        // for (int i = 0; i < 2; i++) {
        //     for (auto & e : seg[i]) cout << e << " ";
        //     cout << endl;
        // }
        
        int ans = 0;
        for (int i = 0; i < len; i++) {
            int val = sum[i];

            // cout << i << " " << sum[i] << endl;
            if (seg[0].empty() || seg[1].empty()) {
                ans = max(ans, val);
            }
            if (seg[0].size()) {
                int pos = bsL(seg[0], loc[i]);
                pos = (int)seg[0].size() - pos;
                // cout << pos << endl;
                ans = max(ans, val - pos);
            } 
            
            if (seg[1].size()) {
                int pos = bsR(seg[1], loc[i]);
                // cout << pos << endl;
                ans = max(ans, val - pos - 1);
            }

            
        }

        cout << ans << '\n';
    }
    return 0;
}
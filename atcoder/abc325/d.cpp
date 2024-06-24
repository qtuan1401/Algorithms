#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > pii;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n;
        cin >> n;
        vector < long long > t;
        vector < long long > a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
            t.push_back(a[i]);
            t.push_back(a[i] + b[i]);
        }

        sort(t.begin(), t.end());
        t.erase(unique(t.begin(), t.end()), t.end());
        
        int len = t.size();
        vector < vector < int > > p(len);
        for (int i = 0; i < n; i++) {
            int l = lower_bound(t.begin(), t.end(), a[i]) - t.begin();
            int r = lower_bound(t.begin(), t.end(), a[i] + b[i]) - t.begin();
            p[l].push_back(r);
        }

        priority_queue < pii, vector < pii >, greater < pii > > heap;
        int ans = 0;
        for (int i = 0; i < len; i++) {
            for (auto & e : p[i]) heap.push({e, i});
            long long tot = 1;
            if (i + 1 < len) tot = t[i + 1] - t[i];
            // cout << i << "| " << heap.size() << " " << tot << endl;
            long long val = t[i];
            while (heap.size() && tot > 0) {
                auto cur = heap.top(); heap.pop();
                int l = cur.second, r = cur.first;
                // cout << i << " * " << l << " " << r << endl;
                if (t[r] < val) continue;
                tot--;
                ans++;
                val++;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
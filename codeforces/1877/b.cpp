#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > II;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n, p;
        cin >> n >> p;
        vector < II > a(n);
        for (int i = 0; i < n; i++) cin >> a[i].second;
        for (int i = 0; i < n; i++) cin >> a[i].first;

        sort(a.begin(), a.end());
        long long ans = p;
        priority_queue < II, vector < II >, greater < II > > heap;
        heap.push({a[0].first, a[0].second});

        for (int i = 1; i < n; i++) {
            auto pr = heap.top(); heap.pop();
            int w = pr.second;
            int v = pr.first;
            if (v >= p) {
                ans += p;
            } else {
                ans += v;
                w--;
            }
           
            if (w > 0) heap.push({v, w});
            heap.push({a[i].first, a[i].second});
        }

        cout << ans << '\n';
    }
    return 0;
}
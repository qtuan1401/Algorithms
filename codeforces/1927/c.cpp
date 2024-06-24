#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector < int > a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());

        vector < int > cnt(k + 1, 0);
        for (int i = 0; i < a.size(); i++) 
            if (a[i] <= k) cnt[a[i]] += 1;
        for (int j = 0; j < b.size(); j++) 
            if (b[j] <= k) cnt[b[j]] += 2;
        
        bool ok = true;
        int cntA = 0, cntB = 0;
        for (int i = 1; i <= k; i++) {
            if (cnt[i] == 1) {
                cntA++;
            } else if (cnt[i] == 2) {
                cntB++;
            } else if (cnt[i] == 0) {
                ok = false;
            } 
        }

        if (ok && cntA <= k / 2 && cntB <= k / 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
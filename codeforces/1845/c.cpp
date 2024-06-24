#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        string s;
        cin >> s;
        vector < vector < int > > pos(10);
        for (int i = 0; i < s.size(); i++) {
            pos[s[i] - '0'].push_back(i);
        }
        
        int n;
        string l, r;
        cin >> n >> l >> r;

        bool found = false;
        int bound = -1;
        for (int i = 0; i < n; i++) {
            int mx = bound;
            for (int cur = l[i] - '0'; cur <= r[i] - '0'; cur++) {
                int p = lower_bound(pos[cur].begin(), pos[cur].end(), bound + 1) - pos[cur].begin();
                if (p == pos[cur].size()) {
                    found = true;
                    break;
                }
                mx = max(mx, pos[cur][p]);
            }
            
            if (found) break;
            bound = mx;
        }


        if (found) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
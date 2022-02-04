#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < int > a(n), move(n + 1);
        vector < vector < int > > pos(n + 2);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pos[a[i]].push_back(i);
        }
        for (int i = 0; i <= n + 1; i++)
            pos[i].push_back(n);
        int cur = 0, p = 0;
        vector < int > ans;
        while (p < n) {
            int mx = 0;
            for (int i = 0; i <= n + 1; i++) {
                while (move[i] < pos[i].size() && pos[i][move[i]] < p)
                    move[i]++;
                if (pos[i][move[i]] != n)
                    mx = max(mx, pos[i][move[i]]);
                else {
                    cur = i;
                    if (cur == 0) {
                        for (int j = p + 1; j < n; j++)
                            ans.push_back(0);
                        p = n;
                    }
                    break;
                }
                
            }
            ans.push_back(cur);
            p = max(p, mx + 1);
            // cout << cur << " ";
        }
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << '\n';
    }
    
    return 0;
}
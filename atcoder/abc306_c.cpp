#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n;
        cin >> n;
        vector < vector < int > > pos(n);
        for (int i = 0; i < 3 * n; i++) {
            int x;
            cin >> x;
            x--;
            pos[x].push_back(i + 1);
        }

        vector < pair < int, int > > ans;
        for (int i = 0; i < n; i++) {
            ans.push_back({pos[i][1], i + 1});
        }

        sort(ans.begin(), ans.end());

        for (auto & e : ans) cout << e.second << " ";
    }
    return 0;
}
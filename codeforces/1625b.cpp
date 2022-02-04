#include <bits/stdc++.h>

using namespace std;

const int MXN = 150001;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < vector < int > > pos(MXN);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            pos[x].push_back(i);
        }

        int ans = -1;
        for (int i = 0; i < MXN; i++) {
            for (int j = 0; j + 1 < pos[i].size(); j++) {
                int x = pos[i][j];
                int y = pos[i][j + 1];
                // cout <<x << " " << y << endl;
                int diff = min(x, y - x);
                // cout << diff << " " << y - diff << endl;
                ans = max(ans, n - (y - x));
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
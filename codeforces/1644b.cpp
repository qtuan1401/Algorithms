#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < vector < int > > ans(n);
        ans[0].push_back(0);
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1];
            for (int j = 0; j <= i; j++) 
                ans[j].push_back(i);
            swap(ans[i][i], ans[i][i - 1]);
        }

        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--)
                cout << ans[i][j] + 1 << " ";
            cout << '\n';
        }
    }
    return 0;
}
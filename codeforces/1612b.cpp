#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, a, b;
        cin >> n >> a >> b;
        vector < int > ans;
        vector < bool > marked(n + 1);
        for (int i = 1; i <= n; i++)
            marked[i] = false;
        int i = 1;
        ans.push_back(b);
        marked[b] = true;
        for ( ; i <= b; i++) {
            if (i != a && i != b) {
                ans.push_back(i);
                marked[i] = true;
            }
            if (ans.size() == n / 2)
                break;
        }

        if (i == n + 1 || ans.size() < n / 2) {
            cout << "-1\n";
            continue;
        }
        bool ok = true;
        for (int j = 1; j <= n; j++)
            if (!marked[j]) {
                if (j < a) {
                    ok = false;
                    break;
                }
                ans.push_back(j);
            }
        
        if (ok) {
            reverse(ans.begin(), ans.end());
            for (int i = 0; i < n; i++)
                cout << ans[i] << " ";
            cout << '\n';
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}
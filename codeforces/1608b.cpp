#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, a, b;
        cin >> n >> a >> b;
        if (a == b && b == 0) {
            // cout << n << " ";
            for (int i = 1; i <= n; i++)
                cout << i << " ";
            cout << '\n';
            continue;
        }
        if (abs(a - b) > 1 || a + b + 2 > n) cout << "-1\n";
        else {
            vector < int > ans;
            int r = a + b + 2;
            if (a == b) {
                for (int i = n; i > r; i--)
                    ans.push_back(i);
            }
            for (int i = r; i >= 1; i--) {
                int x = i, y = r - i + 1;
                if (x < y) break;
                ans.push_back(x);
                if (x != y) ans.push_back(y);
            }
            if (a != b) {
                for (int i = r + 1; i <= n; i++)
                    ans.push_back(i);
            }

            if (a > b) 
                for (int i = 0; i < n; i++)
                    ans[i] = n - ans[i] + 1;
            for (int &val : ans)
                cout << val << " ";
            cout << '\n';
            
        }
    }
    return 0;
}
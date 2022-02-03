#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n == 2) cout << "NO\n";
        else {
            vector < int > small, big;
            for (int i = 1; i <= (n + 1) / 2; i++)
                small.push_back(i);
            for (int i = (n + 1) / 2 + 1; i <= n; i++)
                big.push_back(i);
            reverse(big.begin(), big.end());
            int ns = 0, ng = 0;
            cout << "YES\n";
            vector < int > ans(n);
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                    if (n % 2 == 1)
                        ans[i] = small[ns++];
                    else 
                        ans[i] = big[ng++];
                } else {
                    if (n % 2 == 1)
                        ans[i] = big[ng++];
                    else
                        ans[i] = small[ns++];
                }
            }
            if (n % 2 == 0) {
                swap(ans[0], ans[2]);
            }
            for (int i = 0; i < n; i++)
                cout << ans[i] << " ";
            cout << '\n';
        }
    }
    return 0;
}
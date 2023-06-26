#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n, m;
        cin >> n >> m;
        long long sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sum1 += x;
        }

        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            sum2 += x;
        }

        if (sum1 == sum2) cout << "Draw\n";
        else if (sum1 > sum2) cout << "Tsondu\n";
        else cout << "Tenzing\n";
    }
    return 0;
}
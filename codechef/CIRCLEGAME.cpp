#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> m >> n;
        vector < int > f(n);
        f[0] = 1;
        for (int i = 2; i <= n; i++) {
            int nxt = m % i;
            if (nxt == 0)
                nxt = i;
            int winner = 1;
            if (nxt == 0) {
                winner = f[i - 2] + 1;
            } else {
                winner = f[i - 2];
                winner += (winner >= nxt);
            }
            f[i - 1] = winner;
        }
        for (int i = 0; i < n; i++)
            cout << f[i] << " ";
    }
    return 0;
}
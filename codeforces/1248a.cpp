#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n;
        long long cnt[2][2];
        cnt[0][0] = cnt[0][1] = cnt[1][0] = cnt[1][1] = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[0][x % 2]++;
        }

        cin >> m;
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            cnt[1][x % 2]++;
        }

        cout << cnt[0][0] * cnt[1][0] + cnt[0][1] * cnt[1][1] << '\n';
    }
    return 0;
}
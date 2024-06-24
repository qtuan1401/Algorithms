#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, m;
        cin >> n >> m;
        vector < int > id(m);
        for (int i = 0; i < m; i++) {
            id[i] = i;
        }
        vector < int > a(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }
        vector < int > sum(n, 0);
        vector < string > s(n);

        sort(id.begin(), id.end(), [&](int i, int j) {
            return a[i] > a[j];
        });

        int mx1 = 0, mx2 = 0;

        for (int i = 0; i < n; i++) {
            cin >> s[i];
            for (int j = 0; j < m; j++)
                if (s[i][j] == 'o')
                    sum[i] += a[j];
            sum[i] += i + 1;
            if (sum[i] > mx1) {
                mx2 = mx1;
                mx1 = sum[i];
            } else if (sum[i] > mx2) {
                mx2 = sum[i];
            }
        }

        for (int i = 0; i < n; i++) {
            int target = mx1;
            if (sum[i] == target) target = mx2;

            int cnt = 0;
            for (int j = 0; j < m && sum[i] <= target; j++) {
                if (s[i][id[j]] == 'x') {
                    sum[i] += a[id[j]];
                    cnt++;
                }
            }

            cout << cnt << '\n';
        }
    }
    return 0;
}
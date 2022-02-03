#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > II;

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < II > a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i + 1;
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        vector < int > ans(n + 1);
        ans[0] = 0;
        long long sum = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int pos = a[i].second;
            cnt += (i % 2 == 0);
            if (i % 2 == 0)
                ans[pos] = cnt;
            else
                ans[pos] = -cnt;
            sum += 2ll * a[i].first * cnt;
        }
        cout << sum << '\n';
        for (int i = 0; i <= n; i++)
            cout << ans[i] << " ";
        cout << '\n';
    }
    return 0;
}
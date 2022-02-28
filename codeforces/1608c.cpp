#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < pair < pair < int, int >, int > > a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i].first.first;
        for (int i = 0; i < n; i++)
            cin >> a[i].first.second, a[i].second = i;
        sort(a.begin(), a.end());
        vector < int > mx(n, 0);
        mx[0] = a[0].first.second;
        for (int i = 1; i < n; i++)
            mx[i] = max(mx[i - 1], a[i].first.second);

        vector < int > ans(n);
        ans[a[n - 1].second] = 1;
        int mn = a[n - 1].first.second;
        for (int i = n - 2; i >= 0; i--) {
            int win = ans[a[i].second] = (mx[i] > mn);
            if (win) mn = min(mn, a[i].first.second);
        }
        for (int &val : ans)
            cout << val;
        cout << '\n';
    }
}
#include <bits/stdc++.h>

using namespace std;

vector < int > fw;

void update(int i, int val) {
    while (i < fw.size()) {
        fw[i] = max(fw[i], val);
        i += (i & (-i));
    }
}

int get(int i) {
    int res = 0;
    while (i > 0) {
        res = max(res, fw[i]);
        i -= (i & (-i));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, ans = 0;
        cin >> n >> m;
        vector < pair < int, int > > a(n), b(m);
        vector < int > c;
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        int cnt = 1;
        c.resize(n);
        c[a[0].second] = 1;
        for (int i = 1; i < n; i++) {
            cnt += (a[i].first != a[i - 1].first);
            c[a[i].second] = cnt;
        }

        fw.resize(n + 1);
        for (int i = 0; i <= n; i++)
            fw[i] = 0;
        int res = 0;

        for (int i = 0; i < n; i++) {
            int mx = get(c[i]) + 1;
            res = max(res, mx);
            update(c[i], mx);
        }
        ans += res;

        for (int i = 0; i < m; i++) {
            cin >> b[i].first;
            b[i].second = i;
        }
        sort(b.begin(), b.end());
        cnt = 1;
        c.resize(m);
        c[b[0].second] = 1;
        for (int i = 1; i < m; i++) {
            cnt += (b[i].first != b[i - 1].first);
            c[b[i].second] = cnt;
        }
        fw.resize(m + 1);
        for (int i = 0; i <= m; i++)
            fw[i] = 0;
        res = 0;
        for (int i = 0; i < m; i++) {
            int mx = get(c[i]) + 1;
            res = max(res, mx);
            update(c[i], mx);
        }
        ans += res;
        cout << ans << '\n';
    }
    return 0;
}
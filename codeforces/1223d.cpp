#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 10;

int dq[MAXN], l[MAXN], r[MAXN];
int n;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            l[i] = n + 1;
            r[i] = dq[i] = 0;
        }
        vector < int > v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            v[i]--;
            l[v[i]] = min(l[v[i]], i);
            r[v[i]] = max(r[v[i]], i);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        int res = n;
        for(int i = v.size() - 1; i >= 0; i--) {
            if (i == v.size() - 1 || r[v[i]] >= l[v[i + 1]])
                dq[i] = 1;
            else dq[i] = dq[i + 1] + 1;
            res = min(res, (int)v.size() - dq[i]);
        }
        cout << res << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, l, r, k;
        cin >> n >> l >> r >> k;
        vector < int > a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (k <= 0 || k < a[i])
                break;
            if (a[i] < l)
                continue;
            if (a[i] > r)
                break;
            k -= a[i];
            cnt++;
        }
        cout << cnt << '\n';
    }    
    return 0;
}
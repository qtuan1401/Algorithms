#include <bits/stdc++.h>

using namespace std;

template < class T >
void resetVec(vector < T > & a, int sz, T val) {
    a.clear();
    a.resize(sz, val);
}

typedef long double ld;
typedef long long ll;
typedef pair < long long, long long > pii;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        long long k;
        cin >> n >> k;
        vector < pii > a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }

        sort(a.begin(), a.end());

        long long alpha = 1, ans = 0;
        bool flag = 0;
        for (int i = 0; i < n - 1; i++) {
            // cout << alpha * (a[i + 1].first - a[i].first) << endl;
            if (alpha * (a[i + 1].first - a[i].first) <= k) {
                k -= alpha * (a[i + 1].first - a[i].first);
                alpha++;
            } else {
                flag = 1;
                    // cout << i << " " << a[i].first << " " << k << endl;
                a[i].first += k / alpha;
                k %= alpha;

                for (int j = 0; j < i; j++) a[j].first = a[i].first;
                break;
            }
            // cout << i << " " << k << endl;
        }
        if (flag == 0) {
            for (int i = 0; i < n - 1; i++) a[i].first = a[n - 1].first;
        }
        // cout << a[0].first << " " << k << endl;
        long long cnt = a[0].first + k / n, remain = 0;
        // cout << cnt << endl;
        ans = cnt * n - (n - 1);
        // cout << ans << endl;
        k %= n;
        // cout << k << endl;
        long long addon = 0;
        long long len = a[0].first;
        for (int i = 1; i < n; i++) {
            a[i].first -= len;
            if (a[i].first > 0) addon++;
        }

        addon += k;
        cout << ans + addon << '\n';
    }
    return 0;
}
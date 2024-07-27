#include <bits/stdc++.h>

using namespace std;

template < class T >
void resetVec(vector < T > & a, int sz, T val) {
    a.clear();
    a.resize(sz, val);
}

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n;
        long long x, y;
        cin >> n >> x >> y;
        vector < pii > a(n);
        for (int i = 0; i < n; i++) cin >> a[i].first;
        for (int i = 0; i < n; i++) cin >> a[i].second;

        sort(a.begin(), a.end());

        int ans = n, cnt = 0;
        long long sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            cnt++;
            sum += a[i].first;
            if (sum > x) break;
        } 

        ans = min(ans, cnt);
        sort(a.begin(), a.end(), [&](pii l, pii r) {
            return l.second < r.second;
        });
        cnt = 0; sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            cnt++;
            sum += a[i].second;
            if (sum > y) break;
        }
        ans = min(ans, cnt);
        cout << ans << '\n';
    }
    return 0;
}
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

int calc(vector < pii > & a, int x, int y, int n) {
    vector < vector < int > > f(n + 1, vector < int > (x + 1, y + 1));
    f[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = n; j >= 1; j--) {
            for (int k = 0; k <= x; k++) {
                if (k + a[i].first > x) continue;
                f[j][k + a[i].first] = min(f[j][k + a[i].first], f[j - 1][k] + a[i].second);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) 
            if (f[i][j] <= y) ans = i;
    }
    return min(n, ans + 1);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n;
        int x, y;
        cin >> n >> x >> y;
        vector < pii > a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
        }
       
        cout << calc(a, x, y, n) << '\n';
    }
    return 0;
}
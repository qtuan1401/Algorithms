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

int bs(vector < long long > & a, int l, int r, long long d) {
    int pos = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] < d) {
            pos = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return pos;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        long long n, k, q;
        cin >> n >> k >> q;
        vector < long long > a(k + 1), b(k + 1);
        a[0] = 0; b[0] = 0; 
        for (int i = 1; i <= k; i++) cin >> a[i];
        for (int i = 1; i <= k; i++) cin >> b[i];

        while (q--) {
            long long d;
            cin >> d;
            int pos = bs(a, 0, k - 1, d);
            if (d == a[pos + 1]) {
                cout << b[pos + 1] << " ";
                continue;
            }
            cout << b[pos] + (d - a[pos]) * (b[pos + 1] - b[pos]) / (a[pos + 1] - a[pos]) << " ";
        }
        cout << '\n';
    }
    return 0;
}
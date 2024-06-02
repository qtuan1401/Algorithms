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
        int n, m;
        cin >> n >> m;
        vector < int > a(m, 0);
        for (int i = 0; i < m; i++) cin >> a[i];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                a[j] -= x;
            }
        }

        bool ok = true;
        for (int i = 0; i < m; i++)
            if (a[i] > 0) ok = false;

        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
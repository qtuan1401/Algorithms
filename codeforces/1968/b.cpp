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
    int tests;
    cin >> tests;
    while (tests--) {
        int n, m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;
        int p = 0;
        for (int i = 0; i < m && p < n; p++, i++) {
            while (i < m && b[i] != a[p]) {
                i++;
            }
            if (i == m) break;
        }

        cout << p << '\n';
    }
    return 0;
}
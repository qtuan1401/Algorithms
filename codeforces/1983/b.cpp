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

void inc(string & s, int i, int val) {
    int c = s[i] - '0';
    c = (c + val) % 3;
    s[i] = char (c + '0');
}

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
        vector < string > a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int j = 0; j < n; j++) cin >> b[j];

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) {
                while (a[i][j] != b[i][j]) {
                    inc(a[i], j, 1);
                    inc(a[i + 1], j + 1, 1);
                    inc(a[i], j + 1, 2);
                    inc(a[i + 1], j, 2);
                }
            }
        }

        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != b[i][j]) {
                    ok = false;
                }
            }
        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
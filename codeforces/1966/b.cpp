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
        vector < string > s(n);
        for (int i = 0; i < n; i++) cin >> s[i];

        if (n == 1) {
            if (s[0][0] == s[0][m - 1]) cout << "YES\n";
            else cout << "NO\n";
        } else if (m == 1) {
            if (s[0][0] == s[n - 1][0]) cout << "YES\n";
            else cout << "NO\n";
        } else {
            if (s[0][0] == s[n - 1][m - 1] || s[0][m - 1] == s[n - 1][0]) cout << "YES\n";
            else {
                bool found = false;
                if (s[0][0] == s[0][m - 1]) {
                    for (int i = 0; i < m; i++) {
                        if (s[0][0] != s[0][i]) {
                            found = true;
                            break;
                        }
                    }

                    for (int i = 0; i < m; i++) {
                        if (s[n - 1][0] != s[n - 1][i]) {
                            found = true;
                            break;
                        }
                    }
                } else {
                    for (int i = 0; i < n; i++) {
                        if (s[i][0] != s[0][0]) {
                            found = true;
                            break;
                        }
                    }

                    for (int i = 0; i < n; i++) {
                        if (s[i][m - 1] != s[0][m - 1]) {
                            found = true;
                            break;
                        }
                    }
                }

                if (found) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
    return 0;
}
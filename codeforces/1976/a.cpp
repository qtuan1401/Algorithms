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
        int n;
        string s;
        cin >> n >> s;
        bool ok = true;
        for (int i = 1; i < n; i++) {
            char a = s[i - 1];
            char b = s[i];
            if (isalpha(a) && isdigit(b)) {
                ok = false;
                break;
            }

            if (isalpha(a) && isalpha(b) && a > b) {
                ok = false;
                break;
            }

            if (isdigit(a) && isdigit(b) && a > b) {
                ok = false;
                break;
            }
        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

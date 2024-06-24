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
        string s;
        cin >> s;
        bool ans = false;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[0]) {
                swap(s[0], s[i]);
                ans = true;
                break;
            }
        }

        if (ans) cout << "YES\n" << s << '\n';
        else cout << "NO\n";
    }
    return 0;
}
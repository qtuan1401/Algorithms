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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        bool ans = (a <= c && c <= b && b <= d) || (c <= a && a <= d && d <= b);
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
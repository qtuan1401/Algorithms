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
        bool ok = false;
        if (n == m) ok = true;
        else if (n > m && (n - m) % 2 == 0) ok = true;
        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
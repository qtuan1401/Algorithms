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
        int n, l, r;
        cin >> n >> l >> r;
        for (int i = 1; i < l; i++) cout << i << " ";
        for (int i = r; i >= l; i--) cout << i << " ";
        for (int i = r + 1; i <= n; i++) cout << i << " ";
    }
    return 0;
}
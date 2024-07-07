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
        int n, k, x;
        cin >> n >> k >> x;
        for (int i = 0; i < k; i++) {
            int v;
            cin >> v;
            cout << v << " ";
        }
        cout << x << " ";
        for (int i = k; i < n; i++) {
            int v;
            cin >> v;
            cout << v << " ";
        }
        cout << '\n';
    }
    return 0;
}
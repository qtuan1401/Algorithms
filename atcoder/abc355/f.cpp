#include <bits/stdc++.h>

using namespace std;

template < class T >
void resetVec(vector < T > & a, int sz, T val) {
    a.clear();
    a.resize(sz, val);
}

typedef long double ld;
typedef long long ll;
typedef pair < pair < int, int >,  pair < int, int > > pii;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, q;
        cin >> n >> q;
        vector < pairs > edges;
        for (int i = 0; i < n; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({0, })
        }
    }
    return 0;
}